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
#include "ECC_Decrypt_fp.h"
#include "CryptEccCrypt_fp.h"

#if CC_ECC_Decrypt  // Conditional expansion of this file

//  Return Type: TPM_RC
//      TPM_RC_ATTRIBUTES        key referenced by 'keyHandle' is restricted
//      TPM_RC_KEY                keyHandle does not reference an ECC key
//      TPM_RC_NO_RESULT        internal error in big number processing
//      TPM_RC_SCHEME            bad scheme
//      TPM_RC_VALUE            C3 did not match hash of recovered data
TPM_RC
TPM2_ECC_Decrypt(
    ECC_Decrypt_In   *in,            // IN: input parameter list
    ECC_Decrypt_Out  *out            // OUT: output parameter list
    )
{
    OBJECT          *key = HandleToObject(in->keyHandle);
// Parameter validation
    // Must be the correct type of key with correct attributes
    if (key->publicArea.type != TPM_ALG_ECC)
        return TPM_RC_KEY + RC_ECC_Decrypt_keyHandle;
    if (IS_ATTRIBUTE(key->publicArea.objectAttributes, TPMA_OBJECT, restricted)
        || !IS_ATTRIBUTE(key->publicArea.objectAttributes, TPMA_OBJECT, decrypt))
        return TPM_RCS_ATTRIBUTES + RC_ECC_Decrypt_keyHandle;
    // Have to have a scheme selected
    if(!CryptEccSelectScheme(key, &in->inScheme))
        return TPM_RCS_SCHEME + RC_ECC_Decrypt_inScheme;
//  Command Output
    return CryptEccDecrypt(key, &in->inScheme, &out->plainText,
                           &in->C1.point, &in->C2, &in->C3);
}

#endif // CC_ECC_Decrypt
