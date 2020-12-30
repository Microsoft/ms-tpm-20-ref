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
//** Includes, Defines, and Types
#include    "Tpm.h"
#include    <stdio.h>
#include    <assert.h>

#if RUNTIME_SIZE_CHECKS

#if TABLE_DRIVEN_MARSHAL
extern uint32_t    MarshalDataSize;
#endif

static      int once = 0;

//** TpmSizeChecks()
// This function is used during the development process to make sure that the
// vendor-specific values result in a consistent implementation. When possible,
// the code contains #if to do compile-time checks. However, in some cases, the
// values require the use of "sizeof()" and that can't be used in an #if.
BOOL
TpmSizeChecks(
    void
    )
{
    BOOL        PASS = TRUE;
#if DEBUG
//
    if(once++ != 0)
        return 1;
    {
        UINT32      maxAsymSecurityStrength = MAX_ASYM_SECURITY_STRENGTH;
        UINT32      maxHashSecurityStrength = MAX_HASH_SECURITY_STRENGTH;
        UINT32      maxSymSecurityStrength = MAX_SYM_SECURITY_STRENGTH;
        UINT32      maxSecurityStrengthBits = MAX_SECURITY_STRENGTH_BITS;
        UINT32      proofSize = PROOF_SIZE;
        UINT32      compliantProofSize = COMPLIANT_PROOF_SIZE;
        UINT32      compliantPrimarySeedSize = COMPLIANT_PRIMARY_SEED_SIZE;
        UINT32      primarySeedSize = PRIMARY_SEED_SIZE;

        UINT32      cmacState = sizeof(tpmCmacState_t);
        UINT32      hashState = sizeof(HASH_STATE);
        UINT32      keyScheduleSize = sizeof(tpmCryptKeySchedule_t);
    //
        NOT_REFERENCED(cmacState);
        NOT_REFERENCED(hashState);
        NOT_REFERENCED(keyScheduleSize);
        NOT_REFERENCED(maxAsymSecurityStrength);
        NOT_REFERENCED(maxHashSecurityStrength);
        NOT_REFERENCED(maxSymSecurityStrength);
        NOT_REFERENCED(maxSecurityStrengthBits);
        NOT_REFERENCED(proofSize);
        NOT_REFERENCED(compliantProofSize);
        NOT_REFERENCED(compliantPrimarySeedSize);
        NOT_REFERENCED(primarySeedSize);


        {
            TPMT_SENSITIVE           *p;
            // This assignment keeps compiler from complaining about a conditional
            // comparison being between two constants
            UINT16                    max_rsa_key_bytes = MAX_RSA_KEY_BYTES;
            if((max_rsa_key_bytes / 2) != (sizeof(p->sensitive.rsa.t.buffer) / 5))
            {
                printf("Sensitive part of TPMT_SENSITIVE is undersized. May be caused"
                       " by use of wrong version of Part 2.\n");
                PASS = FALSE;
            }
        }
#if TABLE_DRIVEN_MARSHAL
        printf("sizeof(MarshalData) = %zu\n", sizeof(MarshalData_st));
#endif

        printf("Size of OBJECT = %zu\n", sizeof(OBJECT));
        printf("Size of components in TPMT_SENSITIVE = %zu\n", sizeof(TPMT_SENSITIVE));
        printf("    TPMI_ALG_PUBLIC                 %zu\n", sizeof(TPMI_ALG_PUBLIC));
        printf("    TPM2B_AUTH                      %zu\n", sizeof(TPM2B_AUTH));
        printf("    TPM2B_DIGEST                    %zu\n", sizeof(TPM2B_DIGEST));
        printf("    TPMU_SENSITIVE_COMPOSITE        %zu\n",
               sizeof(TPMU_SENSITIVE_COMPOSITE));
    }
        // Make sure that the size of the context blob is large enough for the largest
        // context
        // TPMS_CONTEXT_DATA contains two TPM2B values. That is not how this is
        // implemented. Rather, the size field of the TPM2B_CONTEXT_DATA is used to
        // determine the amount of data in the encrypted data. That part is not
        // independently sized. This makes the actual size 2 bytes smaller than
        // calculated using Part 2. Since this is opaque to the caller, it is not
        // necessary to fix. The actual size is returned by TPM2_GetCapabilties().

        // Initialize output handle.  At the end of command action, the output
        // handle of an object will be replaced, while the output handle
        // for a session will be the same as input

        // Get the size of fingerprint in context blob.  The sequence value in
        // TPMS_CONTEXT structure is used as the fingerprint
    {
        UINT32  fingerprintSize = sizeof(UINT64);
        UINT32  integritySize = sizeof(UINT16)
            + CryptHashGetDigestSize(CONTEXT_INTEGRITY_HASH_ALG);
        UINT32  biggestObject = MAX(MAX(sizeof(HASH_OBJECT), sizeof(OBJECT)),
                                    sizeof(SESSION));
        UINT32  biggestContext = fingerprintSize + integritySize + biggestObject;

        // round required size up to nearest 8 byte boundary.
        biggestContext = 8 * ((biggestContext + 7) / 8);

        if(MAX_CONTEXT_SIZE < biggestContext)
        {
            printf("MAX_CONTEXT_SIZE needs to be increased to at least %d (%d)\n",
                   biggestContext, MAX_CONTEXT_SIZE);
            PASS = FALSE;
        }
        else if (MAX_CONTEXT_SIZE > biggestContext)
        {
            printf("MAX_CONTEXT_SIZE can be reduced to %d (%d)\n",
                   biggestContext, MAX_CONTEXT_SIZE);
        }
    }
    {
        union u
        {
            TPMA_OBJECT             attributes;
            UINT32                  uint32Value;
        } u;
        // these are defined so that compiler doesn't complain about conditional
        // expressions comparing two constants.
        int                         aSize = sizeof(u.attributes);
        int                         uSize = sizeof(u.uint32Value);
        u.uint32Value = 0;
        SET_ATTRIBUTE(u.attributes, TPMA_OBJECT, fixedTPM);
        if(u.uint32Value != 2)
        {
            printf("The bit allocation in a TPMA_OBJECT is not as expected");
            PASS = FALSE;
        }
        if(aSize != uSize)  // comparison of two sizeof() values annoys compiler
        {
            printf("A TPMA_OBJECT is not the expected size.");
            PASS = FALSE;
        }
    }
    // Check that the platorm implementes each of the ACT that the TPM thinks are
    // present
    {
        uint32_t            act;
        for(act = 0; act < 16; act++)
        {
            switch(act)
            {
                FOR_EACH_ACT(CASE_ACT_NUMBER)
                    if(!_plat__ACT_GetImplemented(act))
                    {
                        printf("TPM_RH_ACT_%1X is not implemented by platform\n",
                               act);
                        PASS = FALSE;
                    }
                default:
                    break;
            }
        }
    }
#endif // DEBUG
    return (PASS);
}

#endif // RUNTIME_SIZE_CHECKS
