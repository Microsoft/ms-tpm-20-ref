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
#include "ECC_Encrypt_fp.h"

#if CC_ECC_Encrypt  // Conditional expansion of this file

//  Return Type: TPM_RC
//      TPM_RC_ATTRIBUTES        key referenced by 'keyHandle' is restricted
//      TPM_RC_KEY                keyHandle does not reference an ECC key
//      TPM_RCS_SCHEME            bad scheme
TPM_RC
TPM2_ECC_Encrypt(
    ECC_Encrypt_In   *in,            // IN: input parameter list
    ECC_Encrypt_Out  *out            // OUT: output parameter list
    )
{
    OBJECT          *pubKey = HandleToObject(in->keyHandle);
// Parameter validation
    if (pubKey->publicArea.type != TPM_ALG_ECC)
        return TPM_RC_KEY + RC_ECC_Encrypt_keyHandle;
    // Have to have a scheme selected
    if(!CryptEccSelectScheme(pubKey, &in->inScheme))
        return TPM_RCS_SCHEME + RC_ECC_Encrypt_inScheme;
//  Command Output
    return CryptEccEncrypt(pubKey, &in->inScheme, &in->plainText,
                           &out->C1.point, &out->C2, &out->C3);
}

#endif // CC_ECC_Encrypt
