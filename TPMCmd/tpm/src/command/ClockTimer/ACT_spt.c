/* Microsoft Reference Implementation for TPM 2.0
 *
 *  The copyright in this software is being made available under the BSD License,
 *  included below. This software may be subject to other third party and
 *  contributor rights, including patent rights, and no such rights are granted
 *  under this license.
 *
 *  Copyright (c) Microsoft Corporation
 *
 *  All rights reserved.
 *
 *  BSD License
 *
 *  Redistribution and use in source and binary forms, with or without modification,
 *  are permitted provided that the following conditions are met:
 *
 *  Redistributions of source code must retain the above copyright notice, this list
 *  of conditions and the following disclaimer.
 *
 *  Redistributions in binary form must reproduce the above copyright notice, this
 *  list of conditions and the following disclaimer in the documentation and/or
 *  other materials provided with the distribution.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS ""AS IS""
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 *  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 *  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 *  ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
//** Introduction
// This code implements the ACT update code. It does not use a mutex. This code uses
// a platform service (_plat__ACT_UpdateCounter()) that returns 'false' if the update
// is not accepted. If this occurs, then TPM_RC_RETRY should be sent to the caller so
// that they can retry the operation later. The implementation of this is platform
// dependent but the reference uses a simple flag to indicate that an update is
// pending and the only process that can clear that flag is the process that does the
// actual update.

//** Includes
#include "Tpm.h"
#include "ACT_spt_fp.h"
#include "Platform_fp.h"

//** Functions

//*** _ActResume()
// This function does the resume processing for an ACT. It updates the saved count
// and turns signaling back on if necessary.
static void
_ActResume(
    UINT32              act,            //IN: the act number
    ACT_STATE          *actData         //IN: pointer to the saved ACT data
)
{
    // If the act was non-zero, then restore the counter value.
    if(actData->remaining > 0)
        _plat__ACT_UpdateCounter(act, actData->remaining);
    // if the counter was zero and the ACT signaling, enable the signaling.
    else if(go.signaledACT & (1 << act))
        _plat__ACT_SetSignaled(act, TRUE);
}

//*** ActStartup()
// This function is called by TPM2_Startup() to initialize the ACT counter values.
BOOL
ActStartup(
    STARTUP_TYPE        type
)
{
    // Reset all the ACT hardware
    _plat__ACT_Initialize();

    // If this not a cold start, copy all the current 'signaled' settings to
    // 'preservedSignaled'.
    if (g_powerWasLost)
        go.preservedSignaled = 0;
    else
        go.preservedSignaled |= go.signaledACT;

    // For TPM_RESET or TPM_RESTART, the ACTs will all be disabled and the output
    // de-asserted.
    if(type != SU_RESUME)
    {
        go.signaledACT = 0;
#define CLEAR_ACT_POLICY(N)                                                         \
            go.ACT_##N.hashAlg = TPM_ALG_NULL;                                      \
            go.ACT_##N.authPolicy.b.size = 0;
        FOR_EACH_ACT(CLEAR_ACT_POLICY)
    }
    else
    {
        // Resume each of the implemented ACT
#define RESUME_ACT(N)   _ActResume(0x##N, &go.ACT_##N);

        FOR_EACH_ACT(RESUME_ACT)
    }
    // set no ACT updated since last startup. This is to enable the halving of the
    // timeout value
    s_ActUpdated = 0;
    _plat__ACT_EnableTicks(TRUE);
    return TRUE;
}

//*** _ActSaveState()
// Get the counter state and the signaled state for an ACT. If the ACT has not been
// updated since the last time it was saved, then divide the count by 2.
static void
_ActSaveState(
    UINT32              act,
    P_ACT_STATE         actData
)
{
    actData->remaining = _plat__ACT_GetRemaining(act);
    // If the ACT hasn't been updated since the last startup, then it should be
    // be halved.
    if((s_ActUpdated & (1 << act)) == 0)
    {
        // Don't halve if the count is set to max or if halving would make it zero
        if((actData->remaining != UINT32_MAX) && (actData->remaining > 1))
            actData->remaining /= 2;
    }
    if(_plat__ACT_GetSignaled(act))
        go.signaledACT |= (1 << act);
}

//*** ActGetSignaled()
// This function returns the state of the signaled flag associated with an ACT.
BOOL
ActGetSignaled(
    TPM_RH              actHandle
)
{
    UINT32              act = actHandle - TPM_RH_ACT_0;
//
    return _plat__ACT_GetSignaled(act);
}

//***ActShutdown()
// This function saves the current state of the counters
BOOL
ActShutdown(
    TPM_SU              state       //IN: the type of the shutdown.
)
{
    // if this is not shutdown state, then the only type of startup is TPM_RESTART
    // so the timer values will be cleared. If this is shutdown state, get the current
    // countdown and signaled values. Plus, if the counter has not been updated
    // since the last restart, divide the time by 2 so that there is no attack on the
    // countdown by saving the countdown state early and then not using the TPM.
    if(state == TPM_SU_STATE)
    {
        // This will be populated as each of the ACT is queried
        go.signaledACT = 0;
        // Get the current count and the signaled state
#define SAVE_ACT_STATE(N) _ActSaveState(0x##N, &go.ACT_##N);

        FOR_EACH_ACT(SAVE_ACT_STATE);
    }
    return TRUE;
}


//*** ActIsImplemented()
// This function determines if an ACT is implemented in both the TPM and the platform
// code.
BOOL
ActIsImplemented(
    UINT32          act
)
{
    // This switch accounts for the TPM implemented values.
    switch(act)
    {
        FOR_EACH_ACT(CASE_ACT_NUMBER)
            // This ensures that the platform implements the values implemented by
            // the TPM
            return _plat__ACT_GetImplemented(act);
        default:
            break;
    }
    return FALSE;
}

//***ActCounterUpdate()
// This function updates the ACT counter. If the counter already has a pending update,
// it returns TPM_RC_RETRY so that the update can be tried again later.
TPM_RC
ActCounterUpdate(
    TPM_RH          handle,         //IN: the handle of the act
    UINT32          newValue        //IN: the value to set in the ACT
)
{
    UINT32          act;
    TPM_RC          result;
//
    act = handle - TPM_RH_ACT_0;
    // This should never fail, but...
    if(!_plat__ACT_GetImplemented(act))
        result = TPM_RC_VALUE;
    else
    {
        // Will need to clear orderly so fail if we are orderly and NV is
        // not available
        if(NV_IS_ORDERLY)
            RETURN_IF_NV_IS_NOT_AVAILABLE;
        // if the attempt to update the counter fails, it means that there is an
        // update pending so wait until it has occurred and then do an update.
        if(!_plat__ACT_UpdateCounter(act, newValue))
            result = TPM_RC_RETRY;
        else
        {
            // Indicate that the ACT has been updated since last TPM2_Startup().
            s_ActUpdated |= (UINT16)(1 << act);

            // Clear the preservedSignaled attribute.
            go.preservedSignaled &= ~((UINT16)(1 << act));

            // Need to clear the orderly flag
            g_clearOrderly = TRUE;

            result = TPM_RC_SUCCESS;
        }
    }
    return result;
}


//*** ActGetCapabilityData()
// This function returns the list of ACT data
//  Return Type: TPMI_YES_NO
//      YES             if more ACT data is available
//      NO              if no more ACT data to
TPMI_YES_NO
ActGetCapabilityData(
    TPM_HANDLE       actHandle,     // IN: the handle for the starting ACT
    UINT32           maxCount,      // IN: maximum allowed return values
    TPML_ACT_DATA   *actList        // OUT: ACT data list
)
{
    // Initialize output property list
    actList->count = 0;

    // Make sure that the starting handle value is in range (again)
    if((actHandle < TPM_RH_ACT_0) || (actHandle > TPM_RH_ACT_F))
        return FALSE;
    // The maximum count of curves we may return is MAX_ECC_CURVES
    if(maxCount > MAX_ACT_DATA)
        maxCount = MAX_ACT_DATA;
    // Scan the ACT data from the starting ACT
    for(; actHandle <= TPM_RH_ACT_F; actHandle++)
    {
        UINT32          act = actHandle - TPM_RH_ACT_0;
        if(actList->count < maxCount)
        {
            if(ActIsImplemented(act))
            {
                TPMS_ACT_DATA    *actData = &actList->actData[actList->count];
            //
                memset(&actData->attributes, 0, sizeof(actData->attributes));
                actData->handle = actHandle;
                actData->timeout = _plat__ACT_GetRemaining(act);
                if(_plat__ACT_GetSignaled(act))
                    SET_ATTRIBUTE(actData->attributes, TPMA_ACT, signaled);
                else
                    CLEAR_ATTRIBUTE(actData->attributes, TPMA_ACT, signaled);
                if (go.preservedSignaled & (1 << act))
                    SET_ATTRIBUTE(actData->attributes, TPMA_ACT, preserveSignaled);
                actList->count++;
            }
        }
        else
        {
            if(_plat__ACT_GetImplemented(act))
                return YES;
        }
    }
    // If we get here, either all of the ACT values were put in the list, or the list
    // was filled and there are no more ACT values to return
    return NO;
}
