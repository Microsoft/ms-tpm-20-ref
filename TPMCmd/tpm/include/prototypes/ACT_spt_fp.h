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
/*(Auto-generated)
 *  Created by TpmPrototypes 1.00
 *  Date: Oct 24, 2019  Time: 10:38:43AM
 */

#ifndef    _ACT_SPT_FP_H_
#define    _ACT_SPT_FP_H_

//*** ActStartup()
// This function is called by TPM2_Startup() to initialize the ACT counter values.
BOOL
ActStartup(
    STARTUP_TYPE        type
);

//*** ActGetSignaled()
// This function returns the state of the signaled flag associated with an ACT.
BOOL
ActGetSignaled(
    TPM_RH              actHandle
);

//***ActShutdown()
// This function saves the current state of the counters
BOOL
ActShutdown(
    TPM_SU              state       //IN: the type of the shutdown.
);

//*** ActIsImplemented()
// This function determines if an ACT is implemented in both the TPM and the platform
// code.
BOOL
ActIsImplemented(
    UINT32          act
);

//***ActCounterUpdate()
// This function updates the ACT counter. If the counter already has a pending update,
// it returns TPM_RC_RETRY so that the update can be tried again later.
TPM_RC
ActCounterUpdate(
    TPM_RH          handle,         //IN: the handle of the act
    UINT32          newValue        //IN: the value to set in the ACT
);

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
);

#endif  // _ACT_SPT_FP_H_
