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
 *  Created by NewMarshal; Version 1.4 Apr 7, 2019
 *  Date: Mar  6, 2020  Time: 01:50:10PM
 */

#ifndef _TABLE_MARSHAL_DEFINES_H_
#define _TABLE_MARSHAL_DEFINES_H_


#define NULL_SHIFT  15
#define NULL_FLAG   (1 << NULL_SHIFT)

// The range macro processes a min, max value and produces a values that is used in
// the computation to see if something is within a range. The max value is (max-min).
// This lets the check for something ('val') within a range become:
//   if((val - min) <= max) // passes if in range
//   if((val - min) > max) // passes if not in range
// This works because all values are converted to UINT32 values before the compare.
// For (val - min), all values greater than or equal to val will become positive
// values with a value equal to 'min' being zero. This means that in an unsigned
// compare against 'max,' any value that is outside the range will appear to be a
// number greater than max. The benefit of this operation is that this will work even
// if the input value is a signed number as long as the input is sign extended.

#define RANGE(_min_, _max_, _base_)                                                  \
    (UINT32)_min_, (UINT32)((_base_)(_max_ - _min_))

// This macro is like the offsetof macro but, instead of computing the offset of
// a structure element, it computes the stride between elements that are in a
// structure array. This is used instead of sizeof() because the sizeof() operator on
// a structure can return an implementation dependent value.
#define STRIDE(s)   ((UINT16)(size_t)&(((s *)0)[1]))

#define MARSHAL_REF(TYPE)   ((UINT16)(offsetof(MARSHAL_DATA, TYPE)))


// This macro creates the entry in the array lookup table
#define ARRAY_MARSHAL_ENTRY(TYPE)                                                   \
        {(marshalIndex_t)TYPE##_MARSHAL_REF, (UINT16)STRIDE(TYPE)}

// Defines for array lookup
#define UINT8_ARRAY_MARSHAL_INDEX                   0   // 0x00
#define TPM_CC_ARRAY_MARSHAL_INDEX                  1   // 0x01
#define TPMA_CC_ARRAY_MARSHAL_INDEX                 2   // 0x02
#define TPM_ALG_ID_ARRAY_MARSHAL_INDEX              3   // 0x03
#define TPM_HANDLE_ARRAY_MARSHAL_INDEX              4   // 0x04
#define TPM2B_DIGEST_ARRAY_MARSHAL_INDEX            5   // 0x05
#define TPMT_HA_ARRAY_MARSHAL_INDEX                 6   // 0x06
#define TPMS_PCR_SELECTION_ARRAY_MARSHAL_INDEX      7   // 0x07
#define TPMS_ALG_PROPERTY_ARRAY_MARSHAL_INDEX       8   // 0x08
#define TPMS_TAGGED_PROPERTY_ARRAY_MARSHAL_INDEX    9   // 0x09
#define TPMS_TAGGED_PCR_SELECT_ARRAY_MARSHAL_INDEX  10  // 0x0A
#define TPM_ECC_CURVE_ARRAY_MARSHAL_INDEX           11  // 0x0B
#define TPMS_TAGGED_POLICY_ARRAY_MARSHAL_INDEX      12  // 0x0C
#define TPMS_ACT_DATA_ARRAY_MARSHAL_INDEX           13  // 0x0D
#define TPMS_AC_OUTPUT_ARRAY_MARSHAL_INDEX          14  // 0x0E


// Defines for referencing a type by offset
#define UINT8_MARSHAL_REF                           \
            ((UINT16)(offsetof(MarshalData_st, UINT8_DATA)))
#define BYTE_MARSHAL_REF                            UINT8_MARSHAL_REF
#define TPM_HT_MARSHAL_REF                          UINT8_MARSHAL_REF
#define TPMA_LOCALITY_MARSHAL_REF                   UINT8_MARSHAL_REF
#define UINT16_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, UINT16_DATA)))
#define TPM_KEY_SIZE_MARSHAL_REF                    UINT16_MARSHAL_REF
#define TPM_KEY_BITS_MARSHAL_REF                    UINT16_MARSHAL_REF
#define TPM_ALG_ID_MARSHAL_REF                      UINT16_MARSHAL_REF
#define TPM_ST_MARSHAL_REF                          UINT16_MARSHAL_REF
#define UINT32_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, UINT32_DATA)))
#define TPM_ALGORITHM_ID_MARSHAL_REF                UINT32_MARSHAL_REF
#define TPM_MODIFIER_INDICATOR_MARSHAL_REF          UINT32_MARSHAL_REF
#define TPM_AUTHORIZATION_SIZE_MARSHAL_REF          UINT32_MARSHAL_REF
#define TPM_PARAMETER_SIZE_MARSHAL_REF              UINT32_MARSHAL_REF
#define TPM_SPEC_MARSHAL_REF                        UINT32_MARSHAL_REF
#define TPM_CONSTANTS32_MARSHAL_REF                 UINT32_MARSHAL_REF
#define TPM_CC_MARSHAL_REF                          UINT32_MARSHAL_REF
#define TPM_RC_MARSHAL_REF                          UINT32_MARSHAL_REF
#define TPM_PT_MARSHAL_REF                          UINT32_MARSHAL_REF
#define TPM_PT_PCR_MARSHAL_REF                      UINT32_MARSHAL_REF
#define TPM_PS_MARSHAL_REF                          UINT32_MARSHAL_REF
#define TPM_HANDLE_MARSHAL_REF                      UINT32_MARSHAL_REF
#define TPM_RH_MARSHAL_REF                          UINT32_MARSHAL_REF
#define TPM_HC_MARSHAL_REF                          UINT32_MARSHAL_REF
#define TPMA_PERMANENT_MARSHAL_REF                  UINT32_MARSHAL_REF
#define TPMA_STARTUP_CLEAR_MARSHAL_REF              UINT32_MARSHAL_REF
#define TPMA_MEMORY_MARSHAL_REF                     UINT32_MARSHAL_REF
#define TPMA_CC_MARSHAL_REF                         UINT32_MARSHAL_REF
#define TPMA_MODES_MARSHAL_REF                      UINT32_MARSHAL_REF
#define TPMA_X509_KEY_USAGE_MARSHAL_REF             UINT32_MARSHAL_REF
#define TPM_NV_INDEX_MARSHAL_REF                    UINT32_MARSHAL_REF
#define TPM_AE_MARSHAL_REF                          UINT32_MARSHAL_REF
#define UINT64_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, UINT64_DATA)))
#define INT8_MARSHAL_REF                            \
            ((UINT16)(offsetof(MarshalData_st, INT8_DATA)))
#define INT16_MARSHAL_REF                           \
            ((UINT16)(offsetof(MarshalData_st, INT16_DATA)))
#define INT32_MARSHAL_REF                           \
            ((UINT16)(offsetof(MarshalData_st, INT32_DATA)))
#define INT64_MARSHAL_REF                           \
            ((UINT16)(offsetof(MarshalData_st, INT64_DATA)))
#define UINT0_MARSHAL_REF                           \
            ((UINT16)(offsetof(MarshalData_st, UINT0_DATA)))
#define TPM_ECC_CURVE_MARSHAL_REF                   \
            ((UINT16)(offsetof(MarshalData_st, TPM_ECC_CURVE_DATA)))
#define TPM_CLOCK_ADJUST_MARSHAL_REF                \
            ((UINT16)(offsetof(MarshalData_st, TPM_CLOCK_ADJUST_DATA)))
#define TPM_EO_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, TPM_EO_DATA)))
#define TPM_SU_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, TPM_SU_DATA)))
#define TPM_SE_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, TPM_SE_DATA)))
#define TPM_CAP_MARSHAL_REF                         \
            ((UINT16)(offsetof(MarshalData_st, TPM_CAP_DATA)))
#define TPMA_ALGORITHM_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMA_ALGORITHM_DATA)))
#define TPMA_OBJECT_MARSHAL_REF                     \
            ((UINT16)(offsetof(MarshalData_st, TPMA_OBJECT_DATA)))
#define TPMA_SESSION_MARSHAL_REF                    \
            ((UINT16)(offsetof(MarshalData_st, TPMA_SESSION_DATA)))
#define TPMA_ACT_MARSHAL_REF                        \
            ((UINT16)(offsetof(MarshalData_st, TPMA_ACT_DATA)))
#define TPMI_YES_NO_MARSHAL_REF                     \
            ((UINT16)(offsetof(MarshalData_st, TPMI_YES_NO_DATA)))
#define TPMI_DH_OBJECT_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMI_DH_OBJECT_DATA)))
#define TPMI_DH_PARENT_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMI_DH_PARENT_DATA)))
#define TPMI_DH_PERSISTENT_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPMI_DH_PERSISTENT_DATA)))
#define TPMI_DH_ENTITY_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMI_DH_ENTITY_DATA)))
#define TPMI_DH_PCR_MARSHAL_REF                     \
            ((UINT16)(offsetof(MarshalData_st, TPMI_DH_PCR_DATA)))
#define TPMI_SH_AUTH_SESSION_MARSHAL_REF            \
            ((UINT16)(offsetof(MarshalData_st, TPMI_SH_AUTH_SESSION_DATA)))
#define TPMI_SH_HMAC_MARSHAL_REF                    \
            ((UINT16)(offsetof(MarshalData_st, TPMI_SH_HMAC_DATA)))
#define TPMI_SH_POLICY_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMI_SH_POLICY_DATA)))
#define TPMI_DH_CONTEXT_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMI_DH_CONTEXT_DATA)))
#define TPMI_DH_SAVED_MARSHAL_REF                   \
            ((UINT16)(offsetof(MarshalData_st, TPMI_DH_SAVED_DATA)))
#define TPMI_RH_HIERARCHY_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_HIERARCHY_DATA)))
#define TPMI_RH_ENABLES_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_ENABLES_DATA)))
#define TPMI_RH_HIERARCHY_AUTH_MARSHAL_REF          \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_HIERARCHY_AUTH_DATA)))
#define TPMI_RH_HIERARCHY_POLICY_MARSHAL_REF        \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_HIERARCHY_POLICY_DATA)))
#define TPMI_RH_PLATFORM_MARSHAL_REF                \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_PLATFORM_DATA)))
#define TPMI_RH_OWNER_MARSHAL_REF                   \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_OWNER_DATA)))
#define TPMI_RH_ENDORSEMENT_MARSHAL_REF             \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_ENDORSEMENT_DATA)))
#define TPMI_RH_PROVISION_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_PROVISION_DATA)))
#define TPMI_RH_CLEAR_MARSHAL_REF                   \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_CLEAR_DATA)))
#define TPMI_RH_NV_AUTH_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_NV_AUTH_DATA)))
#define TPMI_RH_LOCKOUT_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_LOCKOUT_DATA)))
#define TPMI_RH_NV_INDEX_MARSHAL_REF                \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_NV_INDEX_DATA)))
#define TPMI_RH_AC_MARSHAL_REF                      \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_AC_DATA)))
#define TPMI_RH_ACT_MARSHAL_REF                     \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RH_ACT_DATA)))
#define TPMI_ALG_HASH_MARSHAL_REF                   \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_HASH_DATA)))
#define TPMI_ALG_ASYM_MARSHAL_REF                   \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_ASYM_DATA)))
#define TPMI_ALG_SYM_MARSHAL_REF                    \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_SYM_DATA)))
#define TPMI_ALG_SYM_OBJECT_MARSHAL_REF             \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_SYM_OBJECT_DATA)))
#define TPMI_ALG_SYM_MODE_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_SYM_MODE_DATA)))
#define TPMI_ALG_KDF_MARSHAL_REF                    \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_KDF_DATA)))
#define TPMI_ALG_SIG_SCHEME_MARSHAL_REF             \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_SIG_SCHEME_DATA)))
#define TPMI_ECC_KEY_EXCHANGE_MARSHAL_REF           \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ECC_KEY_EXCHANGE_DATA)))
#define TPMI_ST_COMMAND_TAG_MARSHAL_REF             \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ST_COMMAND_TAG_DATA)))
#define TPMI_ALG_MAC_SCHEME_MARSHAL_REF             \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_MAC_SCHEME_DATA)))
#define TPMI_ALG_CIPHER_MODE_MARSHAL_REF            \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_CIPHER_MODE_DATA)))
#define TPMS_EMPTY_MARSHAL_REF                      \
            ((UINT16)(offsetof(MarshalData_st, TPMS_EMPTY_DATA)))
#define TPMS_ENC_SCHEME_RSAES_MARSHAL_REF           TPMS_EMPTY_MARSHAL_REF
#define TPMS_ALGORITHM_DESCRIPTION_MARSHAL_REF      \
            ((UINT16)(offsetof(MarshalData_st, TPMS_ALGORITHM_DESCRIPTION_DATA)))
#define TPMU_HA_MARSHAL_REF                         \
            ((UINT16)(offsetof(MarshalData_st, TPMU_HA_DATA)))
#define TPMT_HA_MARSHAL_REF                         \
            ((UINT16)(offsetof(MarshalData_st, TPMT_HA_DATA)))
#define TPM2B_DIGEST_MARSHAL_REF                    \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_DIGEST_DATA)))
#define TPM2B_NONCE_MARSHAL_REF                     TPM2B_DIGEST_MARSHAL_REF
#define TPM2B_AUTH_MARSHAL_REF                      TPM2B_DIGEST_MARSHAL_REF
#define TPM2B_OPERAND_MARSHAL_REF                   TPM2B_DIGEST_MARSHAL_REF
#define TPM2B_DATA_MARSHAL_REF                      \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_DATA_DATA)))
#define TPM2B_EVENT_MARSHAL_REF                     \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_EVENT_DATA)))
#define TPM2B_MAX_BUFFER_MARSHAL_REF                \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_MAX_BUFFER_DATA)))
#define TPM2B_MAX_NV_BUFFER_MARSHAL_REF             \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_MAX_NV_BUFFER_DATA)))
#define TPM2B_TIMEOUT_MARSHAL_REF                   \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_TIMEOUT_DATA)))
#define TPM2B_IV_MARSHAL_REF                        \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_IV_DATA)))
#define NULL_UNION_MARSHAL_REF                      \
            ((UINT16)(offsetof(MarshalData_st, NULL_UNION_DATA)))
#define TPMU_NAME_MARSHAL_REF                       NULL_UNION_MARSHAL_REF
#define TPMU_SENSITIVE_CREATE_MARSHAL_REF           NULL_UNION_MARSHAL_REF
#define TPM2B_NAME_MARSHAL_REF                      \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_NAME_DATA)))
#define TPMS_PCR_SELECT_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMS_PCR_SELECT_DATA)))
#define TPMS_PCR_SELECTION_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPMS_PCR_SELECTION_DATA)))
#define TPMT_TK_CREATION_MARSHAL_REF                \
            ((UINT16)(offsetof(MarshalData_st, TPMT_TK_CREATION_DATA)))
#define TPMT_TK_VERIFIED_MARSHAL_REF                \
            ((UINT16)(offsetof(MarshalData_st, TPMT_TK_VERIFIED_DATA)))
#define TPMT_TK_AUTH_MARSHAL_REF                    \
            ((UINT16)(offsetof(MarshalData_st, TPMT_TK_AUTH_DATA)))
#define TPMT_TK_HASHCHECK_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMT_TK_HASHCHECK_DATA)))
#define TPMS_ALG_PROPERTY_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMS_ALG_PROPERTY_DATA)))
#define TPMS_TAGGED_PROPERTY_MARSHAL_REF            \
            ((UINT16)(offsetof(MarshalData_st, TPMS_TAGGED_PROPERTY_DATA)))
#define TPMS_TAGGED_PCR_SELECT_MARSHAL_REF          \
            ((UINT16)(offsetof(MarshalData_st, TPMS_TAGGED_PCR_SELECT_DATA)))
#define TPMS_TAGGED_POLICY_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPMS_TAGGED_POLICY_DATA)))
#define TPMS_ACT_DATA_MARSHAL_REF                   \
            ((UINT16)(offsetof(MarshalData_st, TPMS_ACT_DATA_DATA)))
#define TPML_CC_MARSHAL_REF                         \
            ((UINT16)(offsetof(MarshalData_st, TPML_CC_DATA)))
#define TPML_CCA_MARSHAL_REF                        \
            ((UINT16)(offsetof(MarshalData_st, TPML_CCA_DATA)))
#define TPML_ALG_MARSHAL_REF                        \
            ((UINT16)(offsetof(MarshalData_st, TPML_ALG_DATA)))
#define TPML_HANDLE_MARSHAL_REF                     \
            ((UINT16)(offsetof(MarshalData_st, TPML_HANDLE_DATA)))
#define TPML_DIGEST_MARSHAL_REF                     \
            ((UINT16)(offsetof(MarshalData_st, TPML_DIGEST_DATA)))
#define TPML_DIGEST_VALUES_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPML_DIGEST_VALUES_DATA)))
#define TPML_PCR_SELECTION_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPML_PCR_SELECTION_DATA)))
#define TPML_ALG_PROPERTY_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPML_ALG_PROPERTY_DATA)))
#define TPML_TAGGED_TPM_PROPERTY_MARSHAL_REF        \
            ((UINT16)(offsetof(MarshalData_st, TPML_TAGGED_TPM_PROPERTY_DATA)))
#define TPML_TAGGED_PCR_PROPERTY_MARSHAL_REF        \
            ((UINT16)(offsetof(MarshalData_st, TPML_TAGGED_PCR_PROPERTY_DATA)))
#define TPML_ECC_CURVE_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPML_ECC_CURVE_DATA)))
#define TPML_TAGGED_POLICY_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPML_TAGGED_POLICY_DATA)))
#define TPML_ACT_DATA_MARSHAL_REF                   \
            ((UINT16)(offsetof(MarshalData_st, TPML_ACT_DATA_DATA)))
#define TPMU_CAPABILITIES_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMU_CAPABILITIES_DATA)))
#define TPMS_CAPABILITY_DATA_MARSHAL_REF            \
            ((UINT16)(offsetof(MarshalData_st, TPMS_CAPABILITY_DATA_DATA)))
#define TPMS_CLOCK_INFO_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMS_CLOCK_INFO_DATA)))
#define TPMS_TIME_INFO_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMS_TIME_INFO_DATA)))
#define TPMS_TIME_ATTEST_INFO_MARSHAL_REF           \
            ((UINT16)(offsetof(MarshalData_st, TPMS_TIME_ATTEST_INFO_DATA)))
#define TPMS_CERTIFY_INFO_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMS_CERTIFY_INFO_DATA)))
#define TPMS_QUOTE_INFO_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMS_QUOTE_INFO_DATA)))
#define TPMS_COMMAND_AUDIT_INFO_MARSHAL_REF         \
            ((UINT16)(offsetof(MarshalData_st, TPMS_COMMAND_AUDIT_INFO_DATA)))
#define TPMS_SESSION_AUDIT_INFO_MARSHAL_REF         \
            ((UINT16)(offsetof(MarshalData_st, TPMS_SESSION_AUDIT_INFO_DATA)))
#define TPMS_CREATION_INFO_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPMS_CREATION_INFO_DATA)))
#define TPMS_NV_CERTIFY_INFO_MARSHAL_REF            \
            ((UINT16)(offsetof(MarshalData_st, TPMS_NV_CERTIFY_INFO_DATA)))
#define TPMS_NV_DIGEST_CERTIFY_INFO_MARSHAL_REF     \
            ((UINT16)(offsetof(MarshalData_st, TPMS_NV_DIGEST_CERTIFY_INFO_DATA)))
#define TPMI_ST_ATTEST_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ST_ATTEST_DATA)))
#define TPMU_ATTEST_MARSHAL_REF                     \
            ((UINT16)(offsetof(MarshalData_st, TPMU_ATTEST_DATA)))
#define TPMS_ATTEST_MARSHAL_REF                     \
            ((UINT16)(offsetof(MarshalData_st, TPMS_ATTEST_DATA)))
#define TPM2B_ATTEST_MARSHAL_REF                    \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_ATTEST_DATA)))
#define TPMS_AUTH_COMMAND_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMS_AUTH_COMMAND_DATA)))
#define TPMS_AUTH_RESPONSE_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPMS_AUTH_RESPONSE_DATA)))
#define TPMI_TDES_KEY_BITS_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPMI_TDES_KEY_BITS_DATA)))
#define TPMI_AES_KEY_BITS_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMI_AES_KEY_BITS_DATA)))
#define TPMI_SM4_KEY_BITS_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMI_SM4_KEY_BITS_DATA)))
#define TPMI_CAMELLIA_KEY_BITS_MARSHAL_REF          \
            ((UINT16)(offsetof(MarshalData_st, TPMI_CAMELLIA_KEY_BITS_DATA)))
#define TPMU_SYM_KEY_BITS_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMU_SYM_KEY_BITS_DATA)))
#define TPMU_SYM_MODE_MARSHAL_REF                   \
            ((UINT16)(offsetof(MarshalData_st, TPMU_SYM_MODE_DATA)))
#define TPMT_SYM_DEF_MARSHAL_REF                    \
            ((UINT16)(offsetof(MarshalData_st, TPMT_SYM_DEF_DATA)))
#define TPMT_SYM_DEF_OBJECT_MARSHAL_REF             \
            ((UINT16)(offsetof(MarshalData_st, TPMT_SYM_DEF_OBJECT_DATA)))
#define TPM2B_SYM_KEY_MARSHAL_REF                   \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_SYM_KEY_DATA)))
#define TPMS_SYMCIPHER_PARMS_MARSHAL_REF            \
            ((UINT16)(offsetof(MarshalData_st, TPMS_SYMCIPHER_PARMS_DATA)))
#define TPM2B_LABEL_MARSHAL_REF                     \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_LABEL_DATA)))
#define TPMS_DERIVE_MARSHAL_REF                     \
            ((UINT16)(offsetof(MarshalData_st, TPMS_DERIVE_DATA)))
#define TPM2B_DERIVE_MARSHAL_REF                    \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_DERIVE_DATA)))
#define TPM2B_SENSITIVE_DATA_MARSHAL_REF            \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_SENSITIVE_DATA_DATA)))
#define TPMS_SENSITIVE_CREATE_MARSHAL_REF           \
            ((UINT16)(offsetof(MarshalData_st, TPMS_SENSITIVE_CREATE_DATA)))
#define TPM2B_SENSITIVE_CREATE_MARSHAL_REF          \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_SENSITIVE_CREATE_DATA)))
#define TPMS_SCHEME_HASH_MARSHAL_REF                \
            ((UINT16)(offsetof(MarshalData_st, TPMS_SCHEME_HASH_DATA)))
#define TPMS_SCHEME_HMAC_MARSHAL_REF                TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_SIG_SCHEME_RSASSA_MARSHAL_REF          TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_SIG_SCHEME_RSAPSS_MARSHAL_REF          TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_SIG_SCHEME_ECDSA_MARSHAL_REF           TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_SIG_SCHEME_SM2_MARSHAL_REF             TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_SIG_SCHEME_ECSCHNORR_MARSHAL_REF       TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_ENC_SCHEME_OAEP_MARSHAL_REF            TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_KEY_SCHEME_ECDH_MARSHAL_REF            TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_KEY_SCHEME_ECMQV_MARSHAL_REF           TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_KDF_SCHEME_MGF1_MARSHAL_REF            TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_KDF_SCHEME_KDF1_SP800_56A_MARSHAL_REF  TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_KDF_SCHEME_KDF2_MARSHAL_REF            TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_KDF_SCHEME_KDF1_SP800_108_MARSHAL_REF  TPMS_SCHEME_HASH_MARSHAL_REF
#define TPMS_SCHEME_ECDAA_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMS_SCHEME_ECDAA_DATA)))
#define TPMS_SIG_SCHEME_ECDAA_MARSHAL_REF           TPMS_SCHEME_ECDAA_MARSHAL_REF
#define TPMI_ALG_KEYEDHASH_SCHEME_MARSHAL_REF       \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_KEYEDHASH_SCHEME_DATA)))
#define TPMS_SCHEME_XOR_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMS_SCHEME_XOR_DATA)))
#define TPMU_SCHEME_KEYEDHASH_MARSHAL_REF           \
            ((UINT16)(offsetof(MarshalData_st, TPMU_SCHEME_KEYEDHASH_DATA)))
#define TPMT_KEYEDHASH_SCHEME_MARSHAL_REF           \
            ((UINT16)(offsetof(MarshalData_st, TPMT_KEYEDHASH_SCHEME_DATA)))
#define TPMU_SIG_SCHEME_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMU_SIG_SCHEME_DATA)))
#define TPMT_SIG_SCHEME_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMT_SIG_SCHEME_DATA)))
#define TPMU_KDF_SCHEME_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMU_KDF_SCHEME_DATA)))
#define TPMT_KDF_SCHEME_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMT_KDF_SCHEME_DATA)))
#define TPMI_ALG_ASYM_SCHEME_MARSHAL_REF            \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_ASYM_SCHEME_DATA)))
#define TPMU_ASYM_SCHEME_MARSHAL_REF                \
            ((UINT16)(offsetof(MarshalData_st, TPMU_ASYM_SCHEME_DATA)))
#define TPMI_ALG_RSA_SCHEME_MARSHAL_REF             \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_RSA_SCHEME_DATA)))
#define TPMT_RSA_SCHEME_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMT_RSA_SCHEME_DATA)))
#define TPMI_ALG_RSA_DECRYPT_MARSHAL_REF            \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_RSA_DECRYPT_DATA)))
#define TPMT_RSA_DECRYPT_MARSHAL_REF                \
            ((UINT16)(offsetof(MarshalData_st, TPMT_RSA_DECRYPT_DATA)))
#define TPM2B_PUBLIC_KEY_RSA_MARSHAL_REF            \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_PUBLIC_KEY_RSA_DATA)))
#define TPMI_RSA_KEY_BITS_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMI_RSA_KEY_BITS_DATA)))
#define TPM2B_PRIVATE_KEY_RSA_MARSHAL_REF           \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_PRIVATE_KEY_RSA_DATA)))
#define TPM2B_ECC_PARAMETER_MARSHAL_REF             \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_ECC_PARAMETER_DATA)))
#define TPMS_ECC_POINT_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMS_ECC_POINT_DATA)))
#define TPM2B_ECC_POINT_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_ECC_POINT_DATA)))
#define TPMI_ALG_ECC_SCHEME_MARSHAL_REF             \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_ECC_SCHEME_DATA)))
#define TPMI_ECC_CURVE_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ECC_CURVE_DATA)))
#define TPMT_ECC_SCHEME_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMT_ECC_SCHEME_DATA)))
#define TPMS_ALGORITHM_DETAIL_ECC_MARSHAL_REF       \
            ((UINT16)(offsetof(MarshalData_st, TPMS_ALGORITHM_DETAIL_ECC_DATA)))
#define TPMS_SIGNATURE_RSA_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPMS_SIGNATURE_RSA_DATA)))
#define TPMS_SIGNATURE_RSASSA_MARSHAL_REF           TPMS_SIGNATURE_RSA_MARSHAL_REF
#define TPMS_SIGNATURE_RSAPSS_MARSHAL_REF           TPMS_SIGNATURE_RSA_MARSHAL_REF
#define TPMS_SIGNATURE_ECC_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPMS_SIGNATURE_ECC_DATA)))
#define TPMS_SIGNATURE_ECDAA_MARSHAL_REF            TPMS_SIGNATURE_ECC_MARSHAL_REF
#define TPMS_SIGNATURE_ECDSA_MARSHAL_REF            TPMS_SIGNATURE_ECC_MARSHAL_REF
#define TPMS_SIGNATURE_SM2_MARSHAL_REF              TPMS_SIGNATURE_ECC_MARSHAL_REF
#define TPMS_SIGNATURE_ECSCHNORR_MARSHAL_REF        TPMS_SIGNATURE_ECC_MARSHAL_REF
#define TPMU_SIGNATURE_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMU_SIGNATURE_DATA)))
#define TPMT_SIGNATURE_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMT_SIGNATURE_DATA)))
#define TPMU_ENCRYPTED_SECRET_MARSHAL_REF           \
            ((UINT16)(offsetof(MarshalData_st, TPMU_ENCRYPTED_SECRET_DATA)))
#define TPM2B_ENCRYPTED_SECRET_MARSHAL_REF          \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_ENCRYPTED_SECRET_DATA)))
#define TPMI_ALG_PUBLIC_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPMI_ALG_PUBLIC_DATA)))
#define TPMU_PUBLIC_ID_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMU_PUBLIC_ID_DATA)))
#define TPMS_KEYEDHASH_PARMS_MARSHAL_REF            \
            ((UINT16)(offsetof(MarshalData_st, TPMS_KEYEDHASH_PARMS_DATA)))
#define TPMS_RSA_PARMS_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMS_RSA_PARMS_DATA)))
#define TPMS_ECC_PARMS_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMS_ECC_PARMS_DATA)))
#define TPMU_PUBLIC_PARMS_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMU_PUBLIC_PARMS_DATA)))
#define TPMT_PUBLIC_PARMS_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMT_PUBLIC_PARMS_DATA)))
#define TPMT_PUBLIC_MARSHAL_REF                     \
            ((UINT16)(offsetof(MarshalData_st, TPMT_PUBLIC_DATA)))
#define TPM2B_PUBLIC_MARSHAL_REF                    \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_PUBLIC_DATA)))
#define TPM2B_TEMPLATE_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_TEMPLATE_DATA)))
#define TPM2B_PRIVATE_VENDOR_SPECIFIC_MARSHAL_REF   \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_PRIVATE_VENDOR_SPECIFIC_DATA)))
#define TPMU_SENSITIVE_COMPOSITE_MARSHAL_REF        \
            ((UINT16)(offsetof(MarshalData_st, TPMU_SENSITIVE_COMPOSITE_DATA)))
#define TPMT_SENSITIVE_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMT_SENSITIVE_DATA)))
#define TPM2B_SENSITIVE_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_SENSITIVE_DATA)))
#define TPM2B_PRIVATE_MARSHAL_REF                   \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_PRIVATE_DATA)))
#define TPM2B_ID_OBJECT_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_ID_OBJECT_DATA)))
#define TPMS_NV_PIN_COUNTER_PARAMETERS_MARSHAL_REF  \
            ((UINT16)(offsetof(MarshalData_st, TPMS_NV_PIN_COUNTER_PARAMETERS_DATA)))
#define TPMA_NV_MARSHAL_REF                         \
            ((UINT16)(offsetof(MarshalData_st, TPMA_NV_DATA)))
#define TPMS_NV_PUBLIC_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMS_NV_PUBLIC_DATA)))
#define TPM2B_NV_PUBLIC_MARSHAL_REF                 \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_NV_PUBLIC_DATA)))
#define TPM2B_CONTEXT_SENSITIVE_MARSHAL_REF         \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_CONTEXT_SENSITIVE_DATA)))
#define TPMS_CONTEXT_DATA_MARSHAL_REF               \
            ((UINT16)(offsetof(MarshalData_st, TPMS_CONTEXT_DATA_DATA)))
#define TPM2B_CONTEXT_DATA_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_CONTEXT_DATA_DATA)))
#define TPMS_CONTEXT_MARSHAL_REF                    \
            ((UINT16)(offsetof(MarshalData_st, TPMS_CONTEXT_DATA)))
#define TPMS_CREATION_DATA_MARSHAL_REF              \
            ((UINT16)(offsetof(MarshalData_st, TPMS_CREATION_DATA_DATA)))
#define TPM2B_CREATION_DATA_MARSHAL_REF             \
            ((UINT16)(offsetof(MarshalData_st, TPM2B_CREATION_DATA_DATA)))
#define TPM_AT_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, TPM_AT_DATA)))
#define TPMS_AC_OUTPUT_MARSHAL_REF                  \
            ((UINT16)(offsetof(MarshalData_st, TPMS_AC_OUTPUT_DATA)))
#define TPML_AC_CAPABILITIES_MARSHAL_REF            \
            ((UINT16)(offsetof(MarshalData_st, TPML_AC_CAPABILITIES_DATA)))
#define Type00_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type00_DATA)))
#define Type01_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type01_DATA)))
#define Type02_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type02_DATA)))
#define Type03_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type03_DATA)))
#define Type04_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type04_DATA)))
#define Type05_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type05_DATA)))
#define Type06_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type06_DATA)))
#define Type07_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type07_DATA)))
#define Type08_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type08_DATA)))
#define Type09_MARSHAL_REF                          Type08_MARSHAL_REF
#define Type14_MARSHAL_REF                          Type08_MARSHAL_REF
#define Type10_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type10_DATA)))
#define Type11_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type11_DATA)))
#define Type12_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type12_DATA)))
#define Type13_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type13_DATA)))
#define Type15_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type15_DATA)))
#define Type16_MARSHAL_REF                          Type15_MARSHAL_REF
#define Type17_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type17_DATA)))
#define Type18_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type18_DATA)))
#define Type19_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type19_DATA)))
#define Type20_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type20_DATA)))
#define Type21_MARSHAL_REF                          Type20_MARSHAL_REF
#define Type22_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type22_DATA)))
#define Type23_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type23_DATA)))
#define Type24_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type24_DATA)))
#define Type25_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type25_DATA)))
#define Type26_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type26_DATA)))
#define Type27_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type27_DATA)))
#define Type28_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type28_DATA)))
#define Type29_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type29_DATA)))
#define Type30_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type30_DATA)))
#define Type31_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type31_DATA)))
#define Type32_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type32_DATA)))
#define Type33_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type33_DATA)))
#define Type34_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type34_DATA)))
#define Type35_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type35_DATA)))
#define Type36_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type36_DATA)))
#define Type37_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type37_DATA)))
#define Type38_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type38_DATA)))
#define Type39_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type39_DATA)))
#define Type40_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type40_DATA)))
#define Type41_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type41_DATA)))
#define Type42_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type42_DATA)))
#define Type43_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type43_DATA)))
#define Type44_MARSHAL_REF                          \
            ((UINT16)(offsetof(MarshalData_st, Type44_DATA)))


//#defines to change calling sequence for code using marshaling
#define UINT8_Unmarshal(target, buffer, size)                                       \
    Unmarshal(UINT8_MARSHAL_REF, (target), (buffer), (size))
#define UINT8_Marshal(source, buffer, size)                                         \
    Marshal(UINT8_MARSHAL_REF, (source), (buffer), (size))
#define BYTE_Unmarshal(target, buffer, size)                                        \
    Unmarshal(UINT8_MARSHAL_REF, (target), (buffer), (size))
#define BYTE_Marshal(source, buffer, size)                                          \
    Marshal(UINT8_MARSHAL_REF, (source), (buffer), (size))
#define INT8_Unmarshal(target, buffer, size)                                        \
    Unmarshal(INT8_MARSHAL_REF, (target), (buffer), (size))
#define INT8_Marshal(source, buffer, size)                                          \
    Marshal(INT8_MARSHAL_REF, (source), (buffer), (size))
#define UINT16_Unmarshal(target, buffer, size)                                      \
    Unmarshal(UINT16_MARSHAL_REF, (target), (buffer), (size))
#define UINT16_Marshal(source, buffer, size)                                        \
    Marshal(UINT16_MARSHAL_REF, (source), (buffer), (size))
#define INT16_Unmarshal(target, buffer, size)                                       \
    Unmarshal(INT16_MARSHAL_REF, (target), (buffer), (size))
#define INT16_Marshal(source, buffer, size)                                         \
    Marshal(INT16_MARSHAL_REF, (source), (buffer), (size))
#define UINT32_Unmarshal(target, buffer, size)                                      \
    Unmarshal(UINT32_MARSHAL_REF, (target), (buffer), (size))
#define UINT32_Marshal(source, buffer, size)                                        \
    Marshal(UINT32_MARSHAL_REF, (source), (buffer), (size))
#define INT32_Unmarshal(target, buffer, size)                                       \
    Unmarshal(INT32_MARSHAL_REF, (target), (buffer), (size))
#define INT32_Marshal(source, buffer, size)                                         \
    Marshal(INT32_MARSHAL_REF, (source), (buffer), (size))
#define UINT64_Unmarshal(target, buffer, size)                                      \
    Unmarshal(UINT64_MARSHAL_REF, (target), (buffer), (size))
#define UINT64_Marshal(source, buffer, size)                                        \
    Marshal(UINT64_MARSHAL_REF, (source), (buffer), (size))
#define INT64_Unmarshal(target, buffer, size)                                       \
    Unmarshal(INT64_MARSHAL_REF, (target), (buffer), (size))
#define INT64_Marshal(source, buffer, size)                                         \
    Marshal(INT64_MARSHAL_REF, (source), (buffer), (size))
#define TPM_ALGORITHM_ID_Unmarshal(target, buffer, size)                            \
    Unmarshal(TPM_ALGORITHM_ID_MARSHAL_REF, (target), (buffer), (size))
#define TPM_ALGORITHM_ID_Marshal(source, buffer, size)                              \
    Marshal(TPM_ALGORITHM_ID_MARSHAL_REF, (source), (buffer), (size))
#define TPM_MODIFIER_INDICATOR_Unmarshal(target, buffer, size)                      \
    Unmarshal(TPM_MODIFIER_INDICATOR_MARSHAL_REF, (target), (buffer), (size))
#define TPM_MODIFIER_INDICATOR_Marshal(source, buffer, size)                        \
    Marshal(TPM_MODIFIER_INDICATOR_MARSHAL_REF, (source), (buffer), (size))
#define TPM_AUTHORIZATION_SIZE_Unmarshal(target, buffer, size)                      \
    Unmarshal(TPM_AUTHORIZATION_SIZE_MARSHAL_REF, (target), (buffer), (size))
#define TPM_AUTHORIZATION_SIZE_Marshal(source, buffer, size)                        \
    Marshal(TPM_AUTHORIZATION_SIZE_MARSHAL_REF, (source), (buffer), (size))
#define TPM_PARAMETER_SIZE_Unmarshal(target, buffer, size)                          \
    Unmarshal(TPM_PARAMETER_SIZE_MARSHAL_REF, (target), (buffer), (size))
#define TPM_PARAMETER_SIZE_Marshal(source, buffer, size)                            \
    Marshal(TPM_PARAMETER_SIZE_MARSHAL_REF, (source), (buffer), (size))
#define TPM_KEY_SIZE_Unmarshal(target, buffer, size)                                \
    Unmarshal(TPM_KEY_SIZE_MARSHAL_REF, (target), (buffer), (size))
#define TPM_KEY_SIZE_Marshal(source, buffer, size)                                  \
    Marshal(TPM_KEY_SIZE_MARSHAL_REF, (source), (buffer), (size))
#define TPM_KEY_BITS_Unmarshal(target, buffer, size)                                \
    Unmarshal(TPM_KEY_BITS_MARSHAL_REF, (target), (buffer), (size))
#define TPM_KEY_BITS_Marshal(source, buffer, size)                                  \
    Marshal(TPM_KEY_BITS_MARSHAL_REF, (source), (buffer), (size))
#define TPM_CONSTANTS32_Marshal(source, buffer, size)                               \
    Marshal(TPM_CONSTANTS32_MARSHAL_REF, (source), (buffer), (size))
#define TPM_ALG_ID_Unmarshal(target, buffer, size)                                  \
    Unmarshal(TPM_ALG_ID_MARSHAL_REF, (target), (buffer), (size))
#define TPM_ALG_ID_Marshal(source, buffer, size)                                    \
    Marshal(TPM_ALG_ID_MARSHAL_REF, (source), (buffer), (size))
#define TPM_ECC_CURVE_Unmarshal(target, buffer, size)                               \
    Unmarshal(TPM_ECC_CURVE_MARSHAL_REF, (target), (buffer), (size))
#define TPM_ECC_CURVE_Marshal(source, buffer, size)                                 \
    Marshal(TPM_ECC_CURVE_MARSHAL_REF, (source), (buffer), (size))
#define TPM_CC_Unmarshal(target, buffer, size)                                      \
    Unmarshal(TPM_CC_MARSHAL_REF, (target), (buffer), (size))
#define TPM_CC_Marshal(source, buffer, size)                                        \
    Marshal(TPM_CC_MARSHAL_REF, (source), (buffer), (size))
#define TPM_RC_Marshal(source, buffer, size)                                        \
    Marshal(TPM_RC_MARSHAL_REF, (source), (buffer), (size))
#define TPM_CLOCK_ADJUST_Unmarshal(target, buffer, size)                            \
    Unmarshal(TPM_CLOCK_ADJUST_MARSHAL_REF, (target), (buffer), (size))
#define TPM_EO_Unmarshal(target, buffer, size)                                      \
    Unmarshal(TPM_EO_MARSHAL_REF, (target), (buffer), (size))
#define TPM_EO_Marshal(source, buffer, size)                                        \
    Marshal(TPM_EO_MARSHAL_REF, (source), (buffer), (size))
#define TPM_ST_Unmarshal(target, buffer, size)                                      \
    Unmarshal(TPM_ST_MARSHAL_REF, (target), (buffer), (size))
#define TPM_ST_Marshal(source, buffer, size)                                        \
    Marshal(TPM_ST_MARSHAL_REF, (source), (buffer), (size))
#define TPM_SU_Unmarshal(target, buffer, size)                                      \
    Unmarshal(TPM_SU_MARSHAL_REF, (target), (buffer), (size))
#define TPM_SE_Unmarshal(target, buffer, size)                                      \
    Unmarshal(TPM_SE_MARSHAL_REF, (target), (buffer), (size))
#define TPM_CAP_Unmarshal(target, buffer, size)                                     \
    Unmarshal(TPM_CAP_MARSHAL_REF, (target), (buffer), (size))
#define TPM_CAP_Marshal(source, buffer, size)                                       \
    Marshal(TPM_CAP_MARSHAL_REF, (source), (buffer), (size))
#define TPM_PT_Unmarshal(target, buffer, size)                                      \
    Unmarshal(TPM_PT_MARSHAL_REF, (target), (buffer), (size))
#define TPM_PT_Marshal(source, buffer, size)                                        \
    Marshal(TPM_PT_MARSHAL_REF, (source), (buffer), (size))
#define TPM_PT_PCR_Unmarshal(target, buffer, size)                                  \
    Unmarshal(TPM_PT_PCR_MARSHAL_REF, (target), (buffer), (size))
#define TPM_PT_PCR_Marshal(source, buffer, size)                                    \
    Marshal(TPM_PT_PCR_MARSHAL_REF, (source), (buffer), (size))
#define TPM_PS_Marshal(source, buffer, size)                                        \
    Marshal(TPM_PS_MARSHAL_REF, (source), (buffer), (size))
#define TPM_HANDLE_Unmarshal(target, buffer, size)                                  \
    Unmarshal(TPM_HANDLE_MARSHAL_REF, (target), (buffer), (size))
#define TPM_HANDLE_Marshal(source, buffer, size)                                    \
    Marshal(TPM_HANDLE_MARSHAL_REF, (source), (buffer), (size))
#define TPM_HT_Unmarshal(target, buffer, size)                                      \
    Unmarshal(TPM_HT_MARSHAL_REF, (target), (buffer), (size))
#define TPM_HT_Marshal(source, buffer, size)                                        \
    Marshal(TPM_HT_MARSHAL_REF, (source), (buffer), (size))
#define TPM_RH_Unmarshal(target, buffer, size)                                      \
    Unmarshal(TPM_RH_MARSHAL_REF, (target), (buffer), (size))
#define TPM_RH_Marshal(source, buffer, size)                                        \
    Marshal(TPM_RH_MARSHAL_REF, (source), (buffer), (size))
#define TPM_HC_Unmarshal(target, buffer, size)                                      \
    Unmarshal(TPM_HC_MARSHAL_REF, (target), (buffer), (size))
#define TPM_HC_Marshal(source, buffer, size)                                        \
    Marshal(TPM_HC_MARSHAL_REF, (source), (buffer), (size))
#define TPMA_ALGORITHM_Unmarshal(target, buffer, size)                              \
    Unmarshal(TPMA_ALGORITHM_MARSHAL_REF, (target), (buffer), (size))
#define TPMA_ALGORITHM_Marshal(source, buffer, size)                                \
    Marshal(TPMA_ALGORITHM_MARSHAL_REF, (source), (buffer), (size))
#define TPMA_OBJECT_Unmarshal(target, buffer, size)                                 \
    Unmarshal(TPMA_OBJECT_MARSHAL_REF, (target), (buffer), (size))
#define TPMA_OBJECT_Marshal(source, buffer, size)                                   \
    Marshal(TPMA_OBJECT_MARSHAL_REF, (source), (buffer), (size))
#define TPMA_SESSION_Unmarshal(target, buffer, size)                                \
    Unmarshal(TPMA_SESSION_MARSHAL_REF, (target), (buffer), (size))
#define TPMA_SESSION_Marshal(source, buffer, size)                                  \
    Marshal(TPMA_SESSION_MARSHAL_REF, (source), (buffer), (size))
#define TPMA_LOCALITY_Unmarshal(target, buffer, size)                               \
    Unmarshal(TPMA_LOCALITY_MARSHAL_REF, (target), (buffer), (size))
#define TPMA_LOCALITY_Marshal(source, buffer, size)                                 \
    Marshal(TPMA_LOCALITY_MARSHAL_REF, (source), (buffer), (size))
#define TPMA_PERMANENT_Marshal(source, buffer, size)                                \
    Marshal(TPMA_PERMANENT_MARSHAL_REF, (source), (buffer), (size))
#define TPMA_STARTUP_CLEAR_Marshal(source, buffer, size)                            \
    Marshal(TPMA_STARTUP_CLEAR_MARSHAL_REF, (source), (buffer), (size))
#define TPMA_MEMORY_Marshal(source, buffer, size)                                   \
    Marshal(TPMA_MEMORY_MARSHAL_REF, (source), (buffer), (size))
#define TPMA_CC_Marshal(source, buffer, size)                                       \
    Marshal(TPMA_CC_MARSHAL_REF, (source), (buffer), (size))
#define TPMA_MODES_Marshal(source, buffer, size)                                    \
    Marshal(TPMA_MODES_MARSHAL_REF, (source), (buffer), (size))
#define TPMA_X509_KEY_USAGE_Marshal(source, buffer, size)                           \
    Marshal(TPMA_X509_KEY_USAGE_MARSHAL_REF, (source), (buffer), (size))
#define TPMA_ACT_Unmarshal(target, buffer, size)                                    \
    Unmarshal(TPMA_ACT_MARSHAL_REF, (target), (buffer), (size))
#define TPMA_ACT_Marshal(source, buffer, size)                                      \
    Marshal(TPMA_ACT_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_YES_NO_Unmarshal(target, buffer, size)                                 \
    Unmarshal(TPMI_YES_NO_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_YES_NO_Marshal(source, buffer, size)                                   \
    Marshal(TPMI_YES_NO_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_DH_OBJECT_Unmarshal(target, buffer, size, flag)                        \
    Unmarshal(TPMI_DH_OBJECT_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer),\
      (size))
#define TPMI_DH_OBJECT_Marshal(source, buffer, size)                                \
    Marshal(TPMI_DH_OBJECT_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_DH_PARENT_Unmarshal(target, buffer, size, flag)                        \
    Unmarshal(TPMI_DH_PARENT_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer),\
      (size))
#define TPMI_DH_PARENT_Marshal(source, buffer, size)                                \
    Marshal(TPMI_DH_PARENT_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_DH_PERSISTENT_Unmarshal(target, buffer, size)                          \
    Unmarshal(TPMI_DH_PERSISTENT_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_DH_PERSISTENT_Marshal(source, buffer, size)                            \
    Marshal(TPMI_DH_PERSISTENT_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_DH_ENTITY_Unmarshal(target, buffer, size, flag)                        \
    Unmarshal(TPMI_DH_ENTITY_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer),\
      (size))
#define TPMI_DH_PCR_Unmarshal(target, buffer, size, flag)                           \
    Unmarshal(TPMI_DH_PCR_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer),   \
      (size))
#define TPMI_SH_AUTH_SESSION_Unmarshal(target, buffer, size, flag)                  \
    Unmarshal(TPMI_SH_AUTH_SESSION_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),    \
      (buffer), (size))
#define TPMI_SH_AUTH_SESSION_Marshal(source, buffer, size)                          \
    Marshal(TPMI_SH_AUTH_SESSION_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_SH_HMAC_Unmarshal(target, buffer, size)                                \
    Unmarshal(TPMI_SH_HMAC_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_SH_HMAC_Marshal(source, buffer, size)                                  \
    Marshal(TPMI_SH_HMAC_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_SH_POLICY_Unmarshal(target, buffer, size)                              \
    Unmarshal(TPMI_SH_POLICY_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_SH_POLICY_Marshal(source, buffer, size)                                \
    Marshal(TPMI_SH_POLICY_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_DH_CONTEXT_Unmarshal(target, buffer, size)                             \
    Unmarshal(TPMI_DH_CONTEXT_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_DH_CONTEXT_Marshal(source, buffer, size)                               \
    Marshal(TPMI_DH_CONTEXT_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_DH_SAVED_Unmarshal(target, buffer, size)                               \
    Unmarshal(TPMI_DH_SAVED_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_DH_SAVED_Marshal(source, buffer, size)                                 \
    Marshal(TPMI_DH_SAVED_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_RH_HIERARCHY_Unmarshal(target, buffer, size, flag)                     \
    Unmarshal(TPMI_RH_HIERARCHY_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),       \
      (buffer), (size))
#define TPMI_RH_HIERARCHY_Marshal(source, buffer, size)                             \
    Marshal(TPMI_RH_HIERARCHY_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_RH_ENABLES_Unmarshal(target, buffer, size, flag)                       \
    Unmarshal(TPMI_RH_ENABLES_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),         \
      (buffer), (size))
#define TPMI_RH_ENABLES_Marshal(source, buffer, size)                               \
    Marshal(TPMI_RH_ENABLES_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_RH_HIERARCHY_AUTH_Unmarshal(target, buffer, size)                      \
    Unmarshal(TPMI_RH_HIERARCHY_AUTH_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_RH_HIERARCHY_POLICY_Unmarshal(target, buffer, size)                    \
    Unmarshal(TPMI_RH_HIERARCHY_POLICY_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_RH_PLATFORM_Unmarshal(target, buffer, size)                            \
    Unmarshal(TPMI_RH_PLATFORM_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_RH_OWNER_Unmarshal(target, buffer, size, flag)                         \
    Unmarshal(TPMI_RH_OWNER_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer), \
      (size))
#define TPMI_RH_ENDORSEMENT_Unmarshal(target, buffer, size, flag)                   \
    Unmarshal(TPMI_RH_ENDORSEMENT_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),     \
      (buffer), (size))
#define TPMI_RH_PROVISION_Unmarshal(target, buffer, size)                           \
    Unmarshal(TPMI_RH_PROVISION_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_RH_CLEAR_Unmarshal(target, buffer, size)                               \
    Unmarshal(TPMI_RH_CLEAR_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_RH_NV_AUTH_Unmarshal(target, buffer, size)                             \
    Unmarshal(TPMI_RH_NV_AUTH_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_RH_LOCKOUT_Unmarshal(target, buffer, size)                             \
    Unmarshal(TPMI_RH_LOCKOUT_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_RH_NV_INDEX_Unmarshal(target, buffer, size)                            \
    Unmarshal(TPMI_RH_NV_INDEX_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_RH_NV_INDEX_Marshal(source, buffer, size)                              \
    Marshal(TPMI_RH_NV_INDEX_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_RH_AC_Unmarshal(target, buffer, size)                                  \
    Unmarshal(TPMI_RH_AC_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_RH_ACT_Unmarshal(target, buffer, size)                                 \
    Unmarshal(TPMI_RH_ACT_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_RH_ACT_Marshal(source, buffer, size)                                   \
    Marshal(TPMI_RH_ACT_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_HASH_Unmarshal(target, buffer, size, flag)                         \
    Unmarshal(TPMI_ALG_HASH_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer), \
      (size))
#define TPMI_ALG_HASH_Marshal(source, buffer, size)                                 \
    Marshal(TPMI_ALG_HASH_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_ASYM_Unmarshal(target, buffer, size, flag)                         \
    Unmarshal(TPMI_ALG_ASYM_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer), \
      (size))
#define TPMI_ALG_ASYM_Marshal(source, buffer, size)                                 \
    Marshal(TPMI_ALG_ASYM_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_SYM_Unmarshal(target, buffer, size, flag)                          \
    Unmarshal(TPMI_ALG_SYM_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer),  \
      (size))
#define TPMI_ALG_SYM_Marshal(source, buffer, size)                                  \
    Marshal(TPMI_ALG_SYM_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_SYM_OBJECT_Unmarshal(target, buffer, size, flag)                   \
    Unmarshal(TPMI_ALG_SYM_OBJECT_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),     \
      (buffer), (size))
#define TPMI_ALG_SYM_OBJECT_Marshal(source, buffer, size)                           \
    Marshal(TPMI_ALG_SYM_OBJECT_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_SYM_MODE_Unmarshal(target, buffer, size, flag)                     \
    Unmarshal(TPMI_ALG_SYM_MODE_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),       \
      (buffer), (size))
#define TPMI_ALG_SYM_MODE_Marshal(source, buffer, size)                             \
    Marshal(TPMI_ALG_SYM_MODE_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_KDF_Unmarshal(target, buffer, size, flag)                          \
    Unmarshal(TPMI_ALG_KDF_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer),  \
      (size))
#define TPMI_ALG_KDF_Marshal(source, buffer, size)                                  \
    Marshal(TPMI_ALG_KDF_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_SIG_SCHEME_Unmarshal(target, buffer, size, flag)                   \
    Unmarshal(TPMI_ALG_SIG_SCHEME_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),     \
      (buffer), (size))
#define TPMI_ALG_SIG_SCHEME_Marshal(source, buffer, size)                           \
    Marshal(TPMI_ALG_SIG_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ECC_KEY_EXCHANGE_Unmarshal(target, buffer, size, flag)                 \
    Unmarshal(TPMI_ECC_KEY_EXCHANGE_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),   \
      (buffer), (size))
#define TPMI_ECC_KEY_EXCHANGE_Marshal(source, buffer, size)                         \
    Marshal(TPMI_ECC_KEY_EXCHANGE_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ST_COMMAND_TAG_Unmarshal(target, buffer, size)                         \
    Unmarshal(TPMI_ST_COMMAND_TAG_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_ST_COMMAND_TAG_Marshal(source, buffer, size)                           \
    Marshal(TPMI_ST_COMMAND_TAG_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_MAC_SCHEME_Unmarshal(target, buffer, size, flag)                   \
    Unmarshal(TPMI_ALG_MAC_SCHEME_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),     \
      (buffer), (size))
#define TPMI_ALG_MAC_SCHEME_Marshal(source, buffer, size)                           \
    Marshal(TPMI_ALG_MAC_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_CIPHER_MODE_Unmarshal(target, buffer, size, flag)                  \
    Unmarshal(TPMI_ALG_CIPHER_MODE_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),    \
      (buffer), (size))
#define TPMI_ALG_CIPHER_MODE_Marshal(source, buffer, size)                          \
    Marshal(TPMI_ALG_CIPHER_MODE_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_EMPTY_Unmarshal(target, buffer, size)                                  \
    Unmarshal(TPMS_EMPTY_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_EMPTY_Marshal(source, buffer, size)                                    \
    Marshal(TPMS_EMPTY_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_ALGORITHM_DESCRIPTION_Marshal(source, buffer, size)                    \
    Marshal(TPMS_ALGORITHM_DESCRIPTION_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_HA_Unmarshal(target, buffer, size, selector)                           \
    UnmarshalUnion(TPMU_HA_MARSHAL_REF, (target), (buffer), (size), (selector))
#define TPMU_HA_Marshal(source, buffer, size, selector)                             \
    MarshalUnion(TPMU_HA_MARSHAL_REF, (source), (buffer), (size), (selector))
#define TPMT_HA_Unmarshal(target, buffer, size, flag)                               \
    Unmarshal(TPMT_HA_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer),       \
      (size))
#define TPMT_HA_Marshal(source, buffer, size)                                       \
    Marshal(TPMT_HA_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_DIGEST_Unmarshal(target, buffer, size)                                \
    Unmarshal(TPM2B_DIGEST_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_DIGEST_Marshal(source, buffer, size)                                  \
    Marshal(TPM2B_DIGEST_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_DATA_Unmarshal(target, buffer, size)                                  \
    Unmarshal(TPM2B_DATA_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_DATA_Marshal(source, buffer, size)                                    \
    Marshal(TPM2B_DATA_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_NONCE_Unmarshal(target, buffer, size)                                 \
    Unmarshal(TPM2B_NONCE_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_NONCE_Marshal(source, buffer, size)                                   \
    Marshal(TPM2B_NONCE_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_AUTH_Unmarshal(target, buffer, size)                                  \
    Unmarshal(TPM2B_AUTH_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_AUTH_Marshal(source, buffer, size)                                    \
    Marshal(TPM2B_AUTH_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_OPERAND_Unmarshal(target, buffer, size)                               \
    Unmarshal(TPM2B_OPERAND_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_OPERAND_Marshal(source, buffer, size)                                 \
    Marshal(TPM2B_OPERAND_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_EVENT_Unmarshal(target, buffer, size)                                 \
    Unmarshal(TPM2B_EVENT_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_EVENT_Marshal(source, buffer, size)                                   \
    Marshal(TPM2B_EVENT_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_MAX_BUFFER_Unmarshal(target, buffer, size)                            \
    Unmarshal(TPM2B_MAX_BUFFER_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_MAX_BUFFER_Marshal(source, buffer, size)                              \
    Marshal(TPM2B_MAX_BUFFER_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_MAX_NV_BUFFER_Unmarshal(target, buffer, size)                         \
    Unmarshal(TPM2B_MAX_NV_BUFFER_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_MAX_NV_BUFFER_Marshal(source, buffer, size)                           \
    Marshal(TPM2B_MAX_NV_BUFFER_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_TIMEOUT_Unmarshal(target, buffer, size)                               \
    Unmarshal(TPM2B_TIMEOUT_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_TIMEOUT_Marshal(source, buffer, size)                                 \
    Marshal(TPM2B_TIMEOUT_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_IV_Unmarshal(target, buffer, size)                                    \
    Unmarshal(TPM2B_IV_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_IV_Marshal(source, buffer, size)                                      \
    Marshal(TPM2B_IV_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_NAME_Unmarshal(target, buffer, size)                                  \
    Unmarshal(TPM2B_NAME_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_NAME_Marshal(source, buffer, size)                                    \
    Marshal(TPM2B_NAME_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_PCR_SELECT_Unmarshal(target, buffer, size)                             \
    Unmarshal(TPMS_PCR_SELECT_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_PCR_SELECT_Marshal(source, buffer, size)                               \
    Marshal(TPMS_PCR_SELECT_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_PCR_SELECTION_Unmarshal(target, buffer, size)                          \
    Unmarshal(TPMS_PCR_SELECTION_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_PCR_SELECTION_Marshal(source, buffer, size)                            \
    Marshal(TPMS_PCR_SELECTION_MARSHAL_REF, (source), (buffer), (size))
#define TPMT_TK_CREATION_Unmarshal(target, buffer, size)                            \
    Unmarshal(TPMT_TK_CREATION_MARSHAL_REF, (target), (buffer), (size))
#define TPMT_TK_CREATION_Marshal(source, buffer, size)                              \
    Marshal(TPMT_TK_CREATION_MARSHAL_REF, (source), (buffer), (size))
#define TPMT_TK_VERIFIED_Unmarshal(target, buffer, size)                            \
    Unmarshal(TPMT_TK_VERIFIED_MARSHAL_REF, (target), (buffer), (size))
#define TPMT_TK_VERIFIED_Marshal(source, buffer, size)                              \
    Marshal(TPMT_TK_VERIFIED_MARSHAL_REF, (source), (buffer), (size))
#define TPMT_TK_AUTH_Unmarshal(target, buffer, size)                                \
    Unmarshal(TPMT_TK_AUTH_MARSHAL_REF, (target), (buffer), (size))
#define TPMT_TK_AUTH_Marshal(source, buffer, size)                                  \
    Marshal(TPMT_TK_AUTH_MARSHAL_REF, (source), (buffer), (size))
#define TPMT_TK_HASHCHECK_Unmarshal(target, buffer, size)                           \
    Unmarshal(TPMT_TK_HASHCHECK_MARSHAL_REF, (target), (buffer), (size))
#define TPMT_TK_HASHCHECK_Marshal(source, buffer, size)                             \
    Marshal(TPMT_TK_HASHCHECK_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_ALG_PROPERTY_Marshal(source, buffer, size)                             \
    Marshal(TPMS_ALG_PROPERTY_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_TAGGED_PROPERTY_Marshal(source, buffer, size)                          \
    Marshal(TPMS_TAGGED_PROPERTY_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_TAGGED_PCR_SELECT_Marshal(source, buffer, size)                        \
    Marshal(TPMS_TAGGED_PCR_SELECT_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_TAGGED_POLICY_Marshal(source, buffer, size)                            \
    Marshal(TPMS_TAGGED_POLICY_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_ACT_DATA_Marshal(source, buffer, size)                                 \
    Marshal(TPMS_ACT_DATA_MARSHAL_REF, (source), (buffer), (size))
#define TPML_CC_Unmarshal(target, buffer, size)                                     \
    Unmarshal(TPML_CC_MARSHAL_REF, (target), (buffer), (size))
#define TPML_CC_Marshal(source, buffer, size)                                       \
    Marshal(TPML_CC_MARSHAL_REF, (source), (buffer), (size))
#define TPML_CCA_Marshal(source, buffer, size)                                      \
    Marshal(TPML_CCA_MARSHAL_REF, (source), (buffer), (size))
#define TPML_ALG_Unmarshal(target, buffer, size)                                    \
    Unmarshal(TPML_ALG_MARSHAL_REF, (target), (buffer), (size))
#define TPML_ALG_Marshal(source, buffer, size)                                      \
    Marshal(TPML_ALG_MARSHAL_REF, (source), (buffer), (size))
#define TPML_HANDLE_Marshal(source, buffer, size)                                   \
    Marshal(TPML_HANDLE_MARSHAL_REF, (source), (buffer), (size))
#define TPML_DIGEST_Unmarshal(target, buffer, size)                                 \
    Unmarshal(TPML_DIGEST_MARSHAL_REF, (target), (buffer), (size))
#define TPML_DIGEST_Marshal(source, buffer, size)                                   \
    Marshal(TPML_DIGEST_MARSHAL_REF, (source), (buffer), (size))
#define TPML_DIGEST_VALUES_Unmarshal(target, buffer, size)                          \
    Unmarshal(TPML_DIGEST_VALUES_MARSHAL_REF, (target), (buffer), (size))
#define TPML_DIGEST_VALUES_Marshal(source, buffer, size)                            \
    Marshal(TPML_DIGEST_VALUES_MARSHAL_REF, (source), (buffer), (size))
#define TPML_PCR_SELECTION_Unmarshal(target, buffer, size)                          \
    Unmarshal(TPML_PCR_SELECTION_MARSHAL_REF, (target), (buffer), (size))
#define TPML_PCR_SELECTION_Marshal(source, buffer, size)                            \
    Marshal(TPML_PCR_SELECTION_MARSHAL_REF, (source), (buffer), (size))
#define TPML_ALG_PROPERTY_Marshal(source, buffer, size)                             \
    Marshal(TPML_ALG_PROPERTY_MARSHAL_REF, (source), (buffer), (size))
#define TPML_TAGGED_TPM_PROPERTY_Marshal(source, buffer, size)                      \
    Marshal(TPML_TAGGED_TPM_PROPERTY_MARSHAL_REF, (source), (buffer), (size))
#define TPML_TAGGED_PCR_PROPERTY_Marshal(source, buffer, size)                      \
    Marshal(TPML_TAGGED_PCR_PROPERTY_MARSHAL_REF, (source), (buffer), (size))
#define TPML_ECC_CURVE_Marshal(source, buffer, size)                                \
    Marshal(TPML_ECC_CURVE_MARSHAL_REF, (source), (buffer), (size))
#define TPML_TAGGED_POLICY_Marshal(source, buffer, size)                            \
    Marshal(TPML_TAGGED_POLICY_MARSHAL_REF, (source), (buffer), (size))
#define TPML_ACT_DATA_Marshal(source, buffer, size)                                 \
    Marshal(TPML_ACT_DATA_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_CAPABILITIES_Marshal(source, buffer, size, selector)                   \
    MarshalUnion(TPMU_CAPABILITIES_MARSHAL_REF, (source), (buffer), (size),         \
      (selector))
#define TPMS_CAPABILITY_DATA_Marshal(source, buffer, size)                          \
    Marshal(TPMS_CAPABILITY_DATA_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_CLOCK_INFO_Unmarshal(target, buffer, size)                             \
    Unmarshal(TPMS_CLOCK_INFO_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_CLOCK_INFO_Marshal(source, buffer, size)                               \
    Marshal(TPMS_CLOCK_INFO_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_TIME_INFO_Unmarshal(target, buffer, size)                              \
    Unmarshal(TPMS_TIME_INFO_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_TIME_INFO_Marshal(source, buffer, size)                                \
    Marshal(TPMS_TIME_INFO_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_TIME_ATTEST_INFO_Marshal(source, buffer, size)                         \
    Marshal(TPMS_TIME_ATTEST_INFO_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_CERTIFY_INFO_Marshal(source, buffer, size)                             \
    Marshal(TPMS_CERTIFY_INFO_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_QUOTE_INFO_Marshal(source, buffer, size)                               \
    Marshal(TPMS_QUOTE_INFO_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_COMMAND_AUDIT_INFO_Marshal(source, buffer, size)                       \
    Marshal(TPMS_COMMAND_AUDIT_INFO_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SESSION_AUDIT_INFO_Marshal(source, buffer, size)                       \
    Marshal(TPMS_SESSION_AUDIT_INFO_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_CREATION_INFO_Marshal(source, buffer, size)                            \
    Marshal(TPMS_CREATION_INFO_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_NV_CERTIFY_INFO_Marshal(source, buffer, size)                          \
    Marshal(TPMS_NV_CERTIFY_INFO_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_NV_DIGEST_CERTIFY_INFO_Marshal(source, buffer, size)                   \
    Marshal(TPMS_NV_DIGEST_CERTIFY_INFO_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ST_ATTEST_Marshal(source, buffer, size)                                \
    Marshal(TPMI_ST_ATTEST_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_ATTEST_Marshal(source, buffer, size, selector)                         \
    MarshalUnion(TPMU_ATTEST_MARSHAL_REF, (source), (buffer), (size), (selector))
#define TPMS_ATTEST_Marshal(source, buffer, size)                                   \
    Marshal(TPMS_ATTEST_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_ATTEST_Marshal(source, buffer, size)                                  \
    Marshal(TPM2B_ATTEST_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_AUTH_COMMAND_Unmarshal(target, buffer, size)                           \
    Unmarshal(TPMS_AUTH_COMMAND_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_AUTH_RESPONSE_Marshal(source, buffer, size)                            \
    Marshal(TPMS_AUTH_RESPONSE_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_TDES_KEY_BITS_Unmarshal(target, buffer, size)                          \
    Unmarshal(TPMI_TDES_KEY_BITS_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_TDES_KEY_BITS_Marshal(source, buffer, size)                            \
    Marshal(TPMI_TDES_KEY_BITS_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_AES_KEY_BITS_Unmarshal(target, buffer, size)                           \
    Unmarshal(TPMI_AES_KEY_BITS_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_AES_KEY_BITS_Marshal(source, buffer, size)                             \
    Marshal(TPMI_AES_KEY_BITS_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_SM4_KEY_BITS_Unmarshal(target, buffer, size)                           \
    Unmarshal(TPMI_SM4_KEY_BITS_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_SM4_KEY_BITS_Marshal(source, buffer, size)                             \
    Marshal(TPMI_SM4_KEY_BITS_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_CAMELLIA_KEY_BITS_Unmarshal(target, buffer, size)                      \
    Unmarshal(TPMI_CAMELLIA_KEY_BITS_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_CAMELLIA_KEY_BITS_Marshal(source, buffer, size)                        \
    Marshal(TPMI_CAMELLIA_KEY_BITS_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_SYM_KEY_BITS_Unmarshal(target, buffer, size, selector)                 \
    UnmarshalUnion(TPMU_SYM_KEY_BITS_MARSHAL_REF, (target), (buffer), (size),       \
      (selector))
#define TPMU_SYM_KEY_BITS_Marshal(source, buffer, size, selector)                   \
    MarshalUnion(TPMU_SYM_KEY_BITS_MARSHAL_REF, (source), (buffer), (size),         \
      (selector))
#define TPMU_SYM_MODE_Unmarshal(target, buffer, size, selector)                     \
    UnmarshalUnion(TPMU_SYM_MODE_MARSHAL_REF, (target), (buffer), (size),           \
      (selector))
#define TPMU_SYM_MODE_Marshal(source, buffer, size, selector)                       \
    MarshalUnion(TPMU_SYM_MODE_MARSHAL_REF, (source), (buffer), (size), (selector))
#define TPMT_SYM_DEF_Unmarshal(target, buffer, size, flag)                          \
    Unmarshal(TPMT_SYM_DEF_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer),  \
      (size))
#define TPMT_SYM_DEF_Marshal(source, buffer, size)                                  \
    Marshal(TPMT_SYM_DEF_MARSHAL_REF, (source), (buffer), (size))
#define TPMT_SYM_DEF_OBJECT_Unmarshal(target, buffer, size, flag)                   \
    Unmarshal(TPMT_SYM_DEF_OBJECT_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),     \
      (buffer), (size))
#define TPMT_SYM_DEF_OBJECT_Marshal(source, buffer, size)                           \
    Marshal(TPMT_SYM_DEF_OBJECT_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_SYM_KEY_Unmarshal(target, buffer, size)                               \
    Unmarshal(TPM2B_SYM_KEY_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_SYM_KEY_Marshal(source, buffer, size)                                 \
    Marshal(TPM2B_SYM_KEY_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SYMCIPHER_PARMS_Unmarshal(target, buffer, size)                        \
    Unmarshal(TPMS_SYMCIPHER_PARMS_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SYMCIPHER_PARMS_Marshal(source, buffer, size)                          \
    Marshal(TPMS_SYMCIPHER_PARMS_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_LABEL_Unmarshal(target, buffer, size)                                 \
    Unmarshal(TPM2B_LABEL_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_LABEL_Marshal(source, buffer, size)                                   \
    Marshal(TPM2B_LABEL_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_DERIVE_Unmarshal(target, buffer, size)                                 \
    Unmarshal(TPMS_DERIVE_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_DERIVE_Marshal(source, buffer, size)                                   \
    Marshal(TPMS_DERIVE_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_DERIVE_Unmarshal(target, buffer, size)                                \
    Unmarshal(TPM2B_DERIVE_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_DERIVE_Marshal(source, buffer, size)                                  \
    Marshal(TPM2B_DERIVE_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_SENSITIVE_DATA_Unmarshal(target, buffer, size)                        \
    Unmarshal(TPM2B_SENSITIVE_DATA_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_SENSITIVE_DATA_Marshal(source, buffer, size)                          \
    Marshal(TPM2B_SENSITIVE_DATA_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SENSITIVE_CREATE_Unmarshal(target, buffer, size)                       \
    Unmarshal(TPMS_SENSITIVE_CREATE_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_SENSITIVE_CREATE_Unmarshal(target, buffer, size)                      \
    Unmarshal(TPM2B_SENSITIVE_CREATE_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SCHEME_HASH_Unmarshal(target, buffer, size)                            \
    Unmarshal(TPMS_SCHEME_HASH_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SCHEME_HASH_Marshal(source, buffer, size)                              \
    Marshal(TPMS_SCHEME_HASH_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SCHEME_ECDAA_Unmarshal(target, buffer, size)                           \
    Unmarshal(TPMS_SCHEME_ECDAA_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SCHEME_ECDAA_Marshal(source, buffer, size)                             \
    Marshal(TPMS_SCHEME_ECDAA_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_KEYEDHASH_SCHEME_Unmarshal(target, buffer, size, flag)             \
    Unmarshal(TPMI_ALG_KEYEDHASH_SCHEME_MARSHAL_REF|(flag ? NULL_FLAG : 0),         \
      (target), (buffer), (size))
#define TPMI_ALG_KEYEDHASH_SCHEME_Marshal(source, buffer, size)                     \
    Marshal(TPMI_ALG_KEYEDHASH_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SCHEME_HMAC_Unmarshal(target, buffer, size)                            \
    Unmarshal(TPMS_SCHEME_HMAC_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SCHEME_HMAC_Marshal(source, buffer, size)                              \
    Marshal(TPMS_SCHEME_HMAC_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SCHEME_XOR_Unmarshal(target, buffer, size)                             \
    Unmarshal(TPMS_SCHEME_XOR_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SCHEME_XOR_Marshal(source, buffer, size)                               \
    Marshal(TPMS_SCHEME_XOR_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_SCHEME_KEYEDHASH_Unmarshal(target, buffer, size, selector)             \
    UnmarshalUnion(TPMU_SCHEME_KEYEDHASH_MARSHAL_REF, (target), (buffer), (size),   \
      (selector))
#define TPMU_SCHEME_KEYEDHASH_Marshal(source, buffer, size, selector)               \
    MarshalUnion(TPMU_SCHEME_KEYEDHASH_MARSHAL_REF, (source), (buffer), (size),     \
      (selector))
#define TPMT_KEYEDHASH_SCHEME_Unmarshal(target, buffer, size, flag)                 \
    Unmarshal(TPMT_KEYEDHASH_SCHEME_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),   \
      (buffer), (size))
#define TPMT_KEYEDHASH_SCHEME_Marshal(source, buffer, size)                         \
    Marshal(TPMT_KEYEDHASH_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIG_SCHEME_RSASSA_Unmarshal(target, buffer, size)                      \
    Unmarshal(TPMS_SIG_SCHEME_RSASSA_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIG_SCHEME_RSASSA_Marshal(source, buffer, size)                        \
    Marshal(TPMS_SIG_SCHEME_RSASSA_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIG_SCHEME_RSAPSS_Unmarshal(target, buffer, size)                      \
    Unmarshal(TPMS_SIG_SCHEME_RSAPSS_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIG_SCHEME_RSAPSS_Marshal(source, buffer, size)                        \
    Marshal(TPMS_SIG_SCHEME_RSAPSS_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIG_SCHEME_ECDSA_Unmarshal(target, buffer, size)                       \
    Unmarshal(TPMS_SIG_SCHEME_ECDSA_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIG_SCHEME_ECDSA_Marshal(source, buffer, size)                         \
    Marshal(TPMS_SIG_SCHEME_ECDSA_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIG_SCHEME_SM2_Unmarshal(target, buffer, size)                         \
    Unmarshal(TPMS_SIG_SCHEME_SM2_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIG_SCHEME_SM2_Marshal(source, buffer, size)                           \
    Marshal(TPMS_SIG_SCHEME_SM2_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIG_SCHEME_ECSCHNORR_Unmarshal(target, buffer, size)                   \
    Unmarshal(TPMS_SIG_SCHEME_ECSCHNORR_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIG_SCHEME_ECSCHNORR_Marshal(source, buffer, size)                     \
    Marshal(TPMS_SIG_SCHEME_ECSCHNORR_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIG_SCHEME_ECDAA_Unmarshal(target, buffer, size)                       \
    Unmarshal(TPMS_SIG_SCHEME_ECDAA_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIG_SCHEME_ECDAA_Marshal(source, buffer, size)                         \
    Marshal(TPMS_SIG_SCHEME_ECDAA_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_SIG_SCHEME_Unmarshal(target, buffer, size, selector)                   \
    UnmarshalUnion(TPMU_SIG_SCHEME_MARSHAL_REF, (target), (buffer), (size),         \
      (selector))
#define TPMU_SIG_SCHEME_Marshal(source, buffer, size, selector)                     \
    MarshalUnion(TPMU_SIG_SCHEME_MARSHAL_REF, (source), (buffer), (size),           \
      (selector))
#define TPMT_SIG_SCHEME_Unmarshal(target, buffer, size, flag)                       \
    Unmarshal(TPMT_SIG_SCHEME_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),         \
      (buffer), (size))
#define TPMT_SIG_SCHEME_Marshal(source, buffer, size)                               \
    Marshal(TPMT_SIG_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_ENC_SCHEME_OAEP_Unmarshal(target, buffer, size)                        \
    Unmarshal(TPMS_ENC_SCHEME_OAEP_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_ENC_SCHEME_OAEP_Marshal(source, buffer, size)                          \
    Marshal(TPMS_ENC_SCHEME_OAEP_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_ENC_SCHEME_RSAES_Unmarshal(target, buffer, size)                       \
    Unmarshal(TPMS_ENC_SCHEME_RSAES_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_ENC_SCHEME_RSAES_Marshal(source, buffer, size)                         \
    Marshal(TPMS_ENC_SCHEME_RSAES_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_KEY_SCHEME_ECDH_Unmarshal(target, buffer, size)                        \
    Unmarshal(TPMS_KEY_SCHEME_ECDH_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_KEY_SCHEME_ECDH_Marshal(source, buffer, size)                          \
    Marshal(TPMS_KEY_SCHEME_ECDH_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_KEY_SCHEME_ECMQV_Unmarshal(target, buffer, size)                       \
    Unmarshal(TPMS_KEY_SCHEME_ECMQV_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_KEY_SCHEME_ECMQV_Marshal(source, buffer, size)                         \
    Marshal(TPMS_KEY_SCHEME_ECMQV_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_KDF_SCHEME_MGF1_Unmarshal(target, buffer, size)                        \
    Unmarshal(TPMS_KDF_SCHEME_MGF1_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_KDF_SCHEME_MGF1_Marshal(source, buffer, size)                          \
    Marshal(TPMS_KDF_SCHEME_MGF1_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_KDF_SCHEME_KDF1_SP800_56A_Unmarshal(target, buffer, size)              \
    Unmarshal(TPMS_KDF_SCHEME_KDF1_SP800_56A_MARSHAL_REF, (target), (buffer),       \
      (size))
#define TPMS_KDF_SCHEME_KDF1_SP800_56A_Marshal(source, buffer, size)                \
    Marshal(TPMS_KDF_SCHEME_KDF1_SP800_56A_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_KDF_SCHEME_KDF2_Unmarshal(target, buffer, size)                        \
    Unmarshal(TPMS_KDF_SCHEME_KDF2_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_KDF_SCHEME_KDF2_Marshal(source, buffer, size)                          \
    Marshal(TPMS_KDF_SCHEME_KDF2_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_KDF_SCHEME_KDF1_SP800_108_Unmarshal(target, buffer, size)              \
    Unmarshal(TPMS_KDF_SCHEME_KDF1_SP800_108_MARSHAL_REF, (target), (buffer),       \
      (size))
#define TPMS_KDF_SCHEME_KDF1_SP800_108_Marshal(source, buffer, size)                \
    Marshal(TPMS_KDF_SCHEME_KDF1_SP800_108_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_KDF_SCHEME_Unmarshal(target, buffer, size, selector)                   \
    UnmarshalUnion(TPMU_KDF_SCHEME_MARSHAL_REF, (target), (buffer), (size),         \
      (selector))
#define TPMU_KDF_SCHEME_Marshal(source, buffer, size, selector)                     \
    MarshalUnion(TPMU_KDF_SCHEME_MARSHAL_REF, (source), (buffer), (size),           \
      (selector))
#define TPMT_KDF_SCHEME_Unmarshal(target, buffer, size, flag)                       \
    Unmarshal(TPMT_KDF_SCHEME_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),         \
      (buffer), (size))
#define TPMT_KDF_SCHEME_Marshal(source, buffer, size)                               \
    Marshal(TPMT_KDF_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_ASYM_SCHEME_Unmarshal(target, buffer, size, flag)                  \
    Unmarshal(TPMI_ALG_ASYM_SCHEME_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),    \
      (buffer), (size))
#define TPMI_ALG_ASYM_SCHEME_Marshal(source, buffer, size)                          \
    Marshal(TPMI_ALG_ASYM_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_ASYM_SCHEME_Unmarshal(target, buffer, size, selector)                  \
    UnmarshalUnion(TPMU_ASYM_SCHEME_MARSHAL_REF, (target), (buffer), (size),        \
      (selector))
#define TPMU_ASYM_SCHEME_Marshal(source, buffer, size, selector)                    \
    MarshalUnion(TPMU_ASYM_SCHEME_MARSHAL_REF, (source), (buffer), (size),          \
      (selector))
#define TPMI_ALG_RSA_SCHEME_Unmarshal(target, buffer, size, flag)                   \
    Unmarshal(TPMI_ALG_RSA_SCHEME_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),     \
      (buffer), (size))
#define TPMI_ALG_RSA_SCHEME_Marshal(source, buffer, size)                           \
    Marshal(TPMI_ALG_RSA_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define TPMT_RSA_SCHEME_Unmarshal(target, buffer, size, flag)                       \
    Unmarshal(TPMT_RSA_SCHEME_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),         \
      (buffer), (size))
#define TPMT_RSA_SCHEME_Marshal(source, buffer, size)                               \
    Marshal(TPMT_RSA_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_RSA_DECRYPT_Unmarshal(target, buffer, size, flag)                  \
    Unmarshal(TPMI_ALG_RSA_DECRYPT_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),    \
      (buffer), (size))
#define TPMI_ALG_RSA_DECRYPT_Marshal(source, buffer, size)                          \
    Marshal(TPMI_ALG_RSA_DECRYPT_MARSHAL_REF, (source), (buffer), (size))
#define TPMT_RSA_DECRYPT_Unmarshal(target, buffer, size, flag)                      \
    Unmarshal(TPMT_RSA_DECRYPT_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),        \
      (buffer), (size))
#define TPMT_RSA_DECRYPT_Marshal(source, buffer, size)                              \
    Marshal(TPMT_RSA_DECRYPT_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_PUBLIC_KEY_RSA_Unmarshal(target, buffer, size)                        \
    Unmarshal(TPM2B_PUBLIC_KEY_RSA_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_PUBLIC_KEY_RSA_Marshal(source, buffer, size)                          \
    Marshal(TPM2B_PUBLIC_KEY_RSA_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_RSA_KEY_BITS_Unmarshal(target, buffer, size)                           \
    Unmarshal(TPMI_RSA_KEY_BITS_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_RSA_KEY_BITS_Marshal(source, buffer, size)                             \
    Marshal(TPMI_RSA_KEY_BITS_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_PRIVATE_KEY_RSA_Unmarshal(target, buffer, size)                       \
    Unmarshal(TPM2B_PRIVATE_KEY_RSA_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_PRIVATE_KEY_RSA_Marshal(source, buffer, size)                         \
    Marshal(TPM2B_PRIVATE_KEY_RSA_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_ECC_PARAMETER_Unmarshal(target, buffer, size)                         \
    Unmarshal(TPM2B_ECC_PARAMETER_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_ECC_PARAMETER_Marshal(source, buffer, size)                           \
    Marshal(TPM2B_ECC_PARAMETER_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_ECC_POINT_Unmarshal(target, buffer, size)                              \
    Unmarshal(TPMS_ECC_POINT_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_ECC_POINT_Marshal(source, buffer, size)                                \
    Marshal(TPMS_ECC_POINT_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_ECC_POINT_Unmarshal(target, buffer, size)                             \
    Unmarshal(TPM2B_ECC_POINT_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_ECC_POINT_Marshal(source, buffer, size)                               \
    Marshal(TPM2B_ECC_POINT_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_ECC_SCHEME_Unmarshal(target, buffer, size, flag)                   \
    Unmarshal(TPMI_ALG_ECC_SCHEME_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),     \
      (buffer), (size))
#define TPMI_ALG_ECC_SCHEME_Marshal(source, buffer, size)                           \
    Marshal(TPMI_ALG_ECC_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ECC_CURVE_Unmarshal(target, buffer, size)                              \
    Unmarshal(TPMI_ECC_CURVE_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_ECC_CURVE_Marshal(source, buffer, size)                                \
    Marshal(TPMI_ECC_CURVE_MARSHAL_REF, (source), (buffer), (size))
#define TPMT_ECC_SCHEME_Unmarshal(target, buffer, size, flag)                       \
    Unmarshal(TPMT_ECC_SCHEME_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target),         \
      (buffer), (size))
#define TPMT_ECC_SCHEME_Marshal(source, buffer, size)                               \
    Marshal(TPMT_ECC_SCHEME_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_ALGORITHM_DETAIL_ECC_Marshal(source, buffer, size)                     \
    Marshal(TPMS_ALGORITHM_DETAIL_ECC_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIGNATURE_RSA_Unmarshal(target, buffer, size)                          \
    Unmarshal(TPMS_SIGNATURE_RSA_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIGNATURE_RSA_Marshal(source, buffer, size)                            \
    Marshal(TPMS_SIGNATURE_RSA_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIGNATURE_RSASSA_Unmarshal(target, buffer, size)                       \
    Unmarshal(TPMS_SIGNATURE_RSASSA_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIGNATURE_RSASSA_Marshal(source, buffer, size)                         \
    Marshal(TPMS_SIGNATURE_RSASSA_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIGNATURE_RSAPSS_Unmarshal(target, buffer, size)                       \
    Unmarshal(TPMS_SIGNATURE_RSAPSS_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIGNATURE_RSAPSS_Marshal(source, buffer, size)                         \
    Marshal(TPMS_SIGNATURE_RSAPSS_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIGNATURE_ECC_Unmarshal(target, buffer, size)                          \
    Unmarshal(TPMS_SIGNATURE_ECC_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIGNATURE_ECC_Marshal(source, buffer, size)                            \
    Marshal(TPMS_SIGNATURE_ECC_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIGNATURE_ECDAA_Unmarshal(target, buffer, size)                        \
    Unmarshal(TPMS_SIGNATURE_ECDAA_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIGNATURE_ECDAA_Marshal(source, buffer, size)                          \
    Marshal(TPMS_SIGNATURE_ECDAA_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIGNATURE_ECDSA_Unmarshal(target, buffer, size)                        \
    Unmarshal(TPMS_SIGNATURE_ECDSA_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIGNATURE_ECDSA_Marshal(source, buffer, size)                          \
    Marshal(TPMS_SIGNATURE_ECDSA_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIGNATURE_SM2_Unmarshal(target, buffer, size)                          \
    Unmarshal(TPMS_SIGNATURE_SM2_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIGNATURE_SM2_Marshal(source, buffer, size)                            \
    Marshal(TPMS_SIGNATURE_SM2_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_SIGNATURE_ECSCHNORR_Unmarshal(target, buffer, size)                    \
    Unmarshal(TPMS_SIGNATURE_ECSCHNORR_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_SIGNATURE_ECSCHNORR_Marshal(source, buffer, size)                      \
    Marshal(TPMS_SIGNATURE_ECSCHNORR_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_SIGNATURE_Unmarshal(target, buffer, size, selector)                    \
    UnmarshalUnion(TPMU_SIGNATURE_MARSHAL_REF, (target), (buffer), (size),          \
      (selector))
#define TPMU_SIGNATURE_Marshal(source, buffer, size, selector)                      \
    MarshalUnion(TPMU_SIGNATURE_MARSHAL_REF, (source), (buffer), (size), (selector))
#define TPMT_SIGNATURE_Unmarshal(target, buffer, size, flag)                        \
    Unmarshal(TPMT_SIGNATURE_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer),\
      (size))
#define TPMT_SIGNATURE_Marshal(source, buffer, size)                                \
    Marshal(TPMT_SIGNATURE_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_ENCRYPTED_SECRET_Unmarshal(target, buffer, size, selector)             \
    UnmarshalUnion(TPMU_ENCRYPTED_SECRET_MARSHAL_REF, (target), (buffer), (size),   \
      (selector))
#define TPMU_ENCRYPTED_SECRET_Marshal(source, buffer, size, selector)               \
    MarshalUnion(TPMU_ENCRYPTED_SECRET_MARSHAL_REF, (source), (buffer), (size),     \
      (selector))
#define TPM2B_ENCRYPTED_SECRET_Unmarshal(target, buffer, size)                      \
    Unmarshal(TPM2B_ENCRYPTED_SECRET_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_ENCRYPTED_SECRET_Marshal(source, buffer, size)                        \
    Marshal(TPM2B_ENCRYPTED_SECRET_MARSHAL_REF, (source), (buffer), (size))
#define TPMI_ALG_PUBLIC_Unmarshal(target, buffer, size)                             \
    Unmarshal(TPMI_ALG_PUBLIC_MARSHAL_REF, (target), (buffer), (size))
#define TPMI_ALG_PUBLIC_Marshal(source, buffer, size)                               \
    Marshal(TPMI_ALG_PUBLIC_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_PUBLIC_ID_Unmarshal(target, buffer, size, selector)                    \
    UnmarshalUnion(TPMU_PUBLIC_ID_MARSHAL_REF, (target), (buffer), (size),          \
      (selector))
#define TPMU_PUBLIC_ID_Marshal(source, buffer, size, selector)                      \
    MarshalUnion(TPMU_PUBLIC_ID_MARSHAL_REF, (source), (buffer), (size), (selector))
#define TPMS_KEYEDHASH_PARMS_Unmarshal(target, buffer, size)                        \
    Unmarshal(TPMS_KEYEDHASH_PARMS_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_KEYEDHASH_PARMS_Marshal(source, buffer, size)                          \
    Marshal(TPMS_KEYEDHASH_PARMS_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_RSA_PARMS_Unmarshal(target, buffer, size)                              \
    Unmarshal(TPMS_RSA_PARMS_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_RSA_PARMS_Marshal(source, buffer, size)                                \
    Marshal(TPMS_RSA_PARMS_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_ECC_PARMS_Unmarshal(target, buffer, size)                              \
    Unmarshal(TPMS_ECC_PARMS_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_ECC_PARMS_Marshal(source, buffer, size)                                \
    Marshal(TPMS_ECC_PARMS_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_PUBLIC_PARMS_Unmarshal(target, buffer, size, selector)                 \
    UnmarshalUnion(TPMU_PUBLIC_PARMS_MARSHAL_REF, (target), (buffer), (size),       \
      (selector))
#define TPMU_PUBLIC_PARMS_Marshal(source, buffer, size, selector)                   \
    MarshalUnion(TPMU_PUBLIC_PARMS_MARSHAL_REF, (source), (buffer), (size),         \
      (selector))
#define TPMT_PUBLIC_PARMS_Unmarshal(target, buffer, size)                           \
    Unmarshal(TPMT_PUBLIC_PARMS_MARSHAL_REF, (target), (buffer), (size))
#define TPMT_PUBLIC_PARMS_Marshal(source, buffer, size)                             \
    Marshal(TPMT_PUBLIC_PARMS_MARSHAL_REF, (source), (buffer), (size))
#define TPMT_PUBLIC_Unmarshal(target, buffer, size, flag)                           \
    Unmarshal(TPMT_PUBLIC_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer),   \
      (size))
#define TPMT_PUBLIC_Marshal(source, buffer, size)                                   \
    Marshal(TPMT_PUBLIC_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_PUBLIC_Unmarshal(target, buffer, size, flag)                          \
    Unmarshal(TPM2B_PUBLIC_MARSHAL_REF|(flag ? NULL_FLAG : 0), (target), (buffer),  \
      (size))
#define TPM2B_PUBLIC_Marshal(source, buffer, size)                                  \
    Marshal(TPM2B_PUBLIC_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_TEMPLATE_Unmarshal(target, buffer, size)                              \
    Unmarshal(TPM2B_TEMPLATE_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_TEMPLATE_Marshal(source, buffer, size)                                \
    Marshal(TPM2B_TEMPLATE_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_PRIVATE_VENDOR_SPECIFIC_Unmarshal(target, buffer, size)               \
    Unmarshal(TPM2B_PRIVATE_VENDOR_SPECIFIC_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_PRIVATE_VENDOR_SPECIFIC_Marshal(source, buffer, size)                 \
    Marshal(TPM2B_PRIVATE_VENDOR_SPECIFIC_MARSHAL_REF, (source), (buffer), (size))
#define TPMU_SENSITIVE_COMPOSITE_Unmarshal(target, buffer, size, selector)          \
    UnmarshalUnion(TPMU_SENSITIVE_COMPOSITE_MARSHAL_REF, (target), (buffer), (size),\
      (selector))
#define TPMU_SENSITIVE_COMPOSITE_Marshal(source, buffer, size, selector)            \
    MarshalUnion(TPMU_SENSITIVE_COMPOSITE_MARSHAL_REF, (source), (buffer), (size),  \
      (selector))
#define TPMT_SENSITIVE_Unmarshal(target, buffer, size)                              \
    Unmarshal(TPMT_SENSITIVE_MARSHAL_REF, (target), (buffer), (size))
#define TPMT_SENSITIVE_Marshal(source, buffer, size)                                \
    Marshal(TPMT_SENSITIVE_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_SENSITIVE_Unmarshal(target, buffer, size)                             \
    Unmarshal(TPM2B_SENSITIVE_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_SENSITIVE_Marshal(source, buffer, size)                               \
    Marshal(TPM2B_SENSITIVE_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_PRIVATE_Unmarshal(target, buffer, size)                               \
    Unmarshal(TPM2B_PRIVATE_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_PRIVATE_Marshal(source, buffer, size)                                 \
    Marshal(TPM2B_PRIVATE_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_ID_OBJECT_Unmarshal(target, buffer, size)                             \
    Unmarshal(TPM2B_ID_OBJECT_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_ID_OBJECT_Marshal(source, buffer, size)                               \
    Marshal(TPM2B_ID_OBJECT_MARSHAL_REF, (source), (buffer), (size))
#define TPM_NV_INDEX_Marshal(source, buffer, size)                                  \
    Marshal(TPM_NV_INDEX_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_NV_PIN_COUNTER_PARAMETERS_Unmarshal(target, buffer, size)              \
    Unmarshal(TPMS_NV_PIN_COUNTER_PARAMETERS_MARSHAL_REF, (target), (buffer),       \
      (size))
#define TPMS_NV_PIN_COUNTER_PARAMETERS_Marshal(source, buffer, size)                \
    Marshal(TPMS_NV_PIN_COUNTER_PARAMETERS_MARSHAL_REF, (source), (buffer), (size))
#define TPMA_NV_Unmarshal(target, buffer, size)                                     \
    Unmarshal(TPMA_NV_MARSHAL_REF, (target), (buffer), (size))
#define TPMA_NV_Marshal(source, buffer, size)                                       \
    Marshal(TPMA_NV_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_NV_PUBLIC_Unmarshal(target, buffer, size)                              \
    Unmarshal(TPMS_NV_PUBLIC_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_NV_PUBLIC_Marshal(source, buffer, size)                                \
    Marshal(TPMS_NV_PUBLIC_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_NV_PUBLIC_Unmarshal(target, buffer, size)                             \
    Unmarshal(TPM2B_NV_PUBLIC_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_NV_PUBLIC_Marshal(source, buffer, size)                               \
    Marshal(TPM2B_NV_PUBLIC_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_CONTEXT_SENSITIVE_Unmarshal(target, buffer, size)                     \
    Unmarshal(TPM2B_CONTEXT_SENSITIVE_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_CONTEXT_SENSITIVE_Marshal(source, buffer, size)                       \
    Marshal(TPM2B_CONTEXT_SENSITIVE_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_CONTEXT_DATA_Unmarshal(target, buffer, size)                           \
    Unmarshal(TPMS_CONTEXT_DATA_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_CONTEXT_DATA_Marshal(source, buffer, size)                             \
    Marshal(TPMS_CONTEXT_DATA_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_CONTEXT_DATA_Unmarshal(target, buffer, size)                          \
    Unmarshal(TPM2B_CONTEXT_DATA_MARSHAL_REF, (target), (buffer), (size))
#define TPM2B_CONTEXT_DATA_Marshal(source, buffer, size)                            \
    Marshal(TPM2B_CONTEXT_DATA_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_CONTEXT_Unmarshal(target, buffer, size)                                \
    Unmarshal(TPMS_CONTEXT_MARSHAL_REF, (target), (buffer), (size))
#define TPMS_CONTEXT_Marshal(source, buffer, size)                                  \
    Marshal(TPMS_CONTEXT_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_CREATION_DATA_Marshal(source, buffer, size)                            \
    Marshal(TPMS_CREATION_DATA_MARSHAL_REF, (source), (buffer), (size))
#define TPM2B_CREATION_DATA_Marshal(source, buffer, size)                           \
    Marshal(TPM2B_CREATION_DATA_MARSHAL_REF, (source), (buffer), (size))
#define TPM_AT_Unmarshal(target, buffer, size)                                      \
    Unmarshal(TPM_AT_MARSHAL_REF, (target), (buffer), (size))
#define TPM_AT_Marshal(source, buffer, size)                                        \
    Marshal(TPM_AT_MARSHAL_REF, (source), (buffer), (size))
#define TPM_AE_Marshal(source, buffer, size)                                        \
    Marshal(TPM_AE_MARSHAL_REF, (source), (buffer), (size))
#define TPMS_AC_OUTPUT_Marshal(source, buffer, size)                                \
    Marshal(TPMS_AC_OUTPUT_MARSHAL_REF, (source), (buffer), (size))
#define TPML_AC_CAPABILITIES_Marshal(source, buffer, size)                          \
    Marshal(TPML_AC_CAPABILITIES_MARSHAL_REF, (source), (buffer), (size))

#endif // _TABLE_MARSHAL_DEFINES_H_
