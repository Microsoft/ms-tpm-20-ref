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
#include "Tpm.h"
#include "ACT_SetTimeout_fp.h"

#if CC_ACT_SetTimeout  // Conditional expansion of this file

/*(See part 3 specification)
// prove an object with a specific Name is loaded in the TPM
*/
//  Return Type: TPM_RC
//      TPM_RC_RETRY            returned when an update for the selected ACT is
//                              already pending
//      TPM_RC_VALUE            attempt to disable signaling from an ACT that has
//                              not expired
TPM_RC
TPM2_ACT_SetTimeout(
    ACT_SetTimeout_In      *in             // IN: input parameter list
    )
{
    // If 'startTimeout' is UINT32_MAX, then this is an attempt to disable the ACT
    // and turn off the signaling for the ACT. This is only valid if the ACT
    // is signaling.
    if((in->startTimeout == UINT32_MAX) && !ActGetSignaled(in->actHandle))
        return TPM_RC_VALUE + RC_ACT_SetTimeout_startTimeout;
    return ActCounterUpdate(in->actHandle, in->startTimeout);
}

#endif // CC_ACT_SetTimeout
