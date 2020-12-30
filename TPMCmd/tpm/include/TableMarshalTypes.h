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

#ifndef _TABLE_MARSHAL_TYPES_H_
#define _TABLE_MARSHAL_TYPES_H_

typedef UINT16      marshalIndex_t;

//*** Structure Entries
// A structure contains a list of elements to unmarshal. Each of the entries is a
// UINT16. The structure descriptor is:

// The 'values' array contains indicators for the things to marshal. The 'elements'
// parameter indicates how many different entities are unmarshaled. This number
// nominally corresponds to the number of rows in the Part 2 table that describes
// the structure (the number of rows minus the title row and any error code rows).

// A schematic of a simple structure entry is shown here but the values are not
// actually in a structure. As shown, the third value is the offset in the structure
// where the value is placed when unmarshaled, or fetched from when marshaling. This
// is sufficient when the element type indicated by 'index' is always a simple type
// and never a union or array.This is just shown for illustrative purposes.
typedef struct simpleStructureEntry_t {
    UINT16          qualifiers;         // indicates the type of entry (array, union
                                        // etc.)
    marshalIndex_t  index;              // the index into the appropriate array of
                                        //  the descriptor of this type
    UINT16          offset;             // where this comes from or is placed
} simpleStructureEntry_t;

typedef const struct UintMarshal_mst
{
    UINT8           marshalType;        // UINT_MTYPE
    UINT8           modifiers;          // size and signed indicator.
} UintMarshal_mst;

typedef struct UnionMarshal_mst
{
    UINT8           countOfselectors;
    UINT8           modifiers;          // NULL_SELECTOR
    UINT16          offsetOfUnmarshalTypes;
    UINT32          selectors[1];
//    UINT16          marshalingTypes[1]; // This is not part of the prototypical
                                          //    entry. It is here to show where the
                                          //    marshaling types will be in a union
} UnionMarshal_mst;

typedef struct NullUnionMarshal_mst
{
    UINT8           count;
} NullUnionMarshal_mst;

typedef struct MarshalHeader_mst
{
    UINT8           marshalType;        // VALUES_MTYPE
    UINT8           modifiers;
    UINT8           errorCode;
} MarshalHeader_mst;

typedef const struct ArrayMarshal_mst   // used in a structure
{
    marshalIndex_t  type;
    UINT16          stride;
} ArrayMarshal_mst;

typedef const struct StructMarshal_mst
{
    UINT8           marshalType;        // STRUCTURE_MTYPE
    UINT8           elements;
    UINT16          values[1];          // three times elements
} StructMarshal_mst;

typedef const struct ValuesMarshal_mst
{
    UINT8           marshalType;        // VALUES_MTYPE
    UINT8           modifiers;
    UINT8           errorCode;
    UINT8           ranges;
    UINT8           singles;
    UINT32          values[1];
} ValuesMarshal_mst;

typedef const struct TableMarshal_mst
{
    UINT8           marshalType;        // TABLE_MTYPE
    UINT8           modifiers;
    UINT8           errorCode;
    UINT8           singles;
    UINT32          values[1];
} TableMarshal_mst;

typedef const struct MinMaxMarshal_mst
{
    UINT8           marshalType;        // MIN_MAX_MTYPE
    UINT8           modifiers;
    UINT8           errorCode;
    UINT32          values[2];
} MinMaxMarshal_mst;

typedef const struct Tpm2bMarshal_mst
{
    UINT8           unmarshalType;      // TPM2B_MTYPE
    UINT16          sizeIndex;          // reference to type for this size value
} Tpm2bMarshal_mst;

typedef const struct Tpm2bsMarshal_mst
{
    UINT8           unmarshalType;      // TPM2BS_MTYPE
    UINT8           modifiers;          // size= and offset (2 - 7)
    UINT16          sizeIndex;          // index of the size value;
    UINT16          dataIndex;          // the structure
} Tpm2bsMarshal_mst;

typedef const struct ListMarshal_mst
{
    UINT8           unmarshalType;      // LIST_MTYPE (for TPML)
    UINT8           modifiers;          // size offset 2-7
    UINT16          sizeIndex;          // reference to the minmax structure that
                                        //      unmarshals the size parameter
    UINT16          arrayRef;           // reference to an array definition (type
                                        //  and stride)
} ListMarshal_mst;

typedef const struct AttributesMarshal_mst
{
    UINT8           unmarashalType;     // ATTRIBUTE_MTYPE
    UINT8           modifiers;          // size (ONE_BYTES, TWO_BYTES, or FOUR_BYTES
    UINT32          attributeMask;      // the values that must be zero.
} AttributesMarshal_mst;

typedef const struct CompositeMarshal_mst
{
    UINT8           unmashalType;       // COMPOSITE_MTYPE
    UINT8           modifiers;          // number of entries and size
    marshalIndex_t  types[1];           // array of unmarshaling types
} CompositeMarshal_mst;

typedef const struct TPM_ECC_CURVE_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[4];
} TPM_ECC_CURVE_mst;

typedef const struct TPM_CLOCK_ADJUST_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} TPM_CLOCK_ADJUST_mst;

typedef const struct TPM_EO_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} TPM_EO_mst;

typedef const struct TPM_SU_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[2];
} TPM_SU_mst;

typedef const struct TPM_SE_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[3];
} TPM_SE_mst;

typedef const struct TPM_CAP_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         ranges;
    UINT8         singles;
    UINT32        values[3];
} TPM_CAP_mst;

typedef const struct TPMI_YES_NO_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[2];
} TPMI_YES_NO_mst;

typedef const struct TPMI_DH_OBJECT_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         ranges;
    UINT8         singles;
    UINT32        values[5];
} TPMI_DH_OBJECT_mst;

typedef const struct TPMI_DH_PARENT_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         ranges;
    UINT8         singles;
    UINT32        values[8];
} TPMI_DH_PARENT_mst;

typedef const struct TPMI_DH_PERSISTENT_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} TPMI_DH_PERSISTENT_mst;

typedef const struct TPMI_DH_ENTITY_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         ranges;
    UINT8         singles;
    UINT32        values[15];
} TPMI_DH_ENTITY_mst;

typedef const struct TPMI_DH_PCR_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[3];
} TPMI_DH_PCR_mst;

typedef const struct TPMI_SH_AUTH_SESSION_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         ranges;
    UINT8         singles;
    UINT32        values[5];
} TPMI_SH_AUTH_SESSION_mst;

typedef const struct TPMI_SH_HMAC_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} TPMI_SH_HMAC_mst;

typedef const struct TPMI_SH_POLICY_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} TPMI_SH_POLICY_mst;

typedef const struct TPMI_DH_CONTEXT_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         ranges;
    UINT8         singles;
    UINT32        values[6];
} TPMI_DH_CONTEXT_mst;

typedef const struct TPMI_DH_SAVED_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         ranges;
    UINT8         singles;
    UINT32        values[7];
} TPMI_DH_SAVED_mst;

typedef const struct TPMI_RH_HIERARCHY_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[4];
} TPMI_RH_HIERARCHY_mst;

typedef const struct TPMI_RH_ENABLES_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[5];
} TPMI_RH_ENABLES_mst;

typedef const struct TPMI_RH_HIERARCHY_AUTH_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[4];
} TPMI_RH_HIERARCHY_AUTH_mst;

typedef const struct TPMI_RH_HIERARCHY_POLICY_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         ranges;
    UINT8         singles;
    UINT32        values[6];
} TPMI_RH_HIERARCHY_POLICY_mst;

typedef const struct TPMI_RH_PLATFORM_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[1];
} TPMI_RH_PLATFORM_mst;

typedef const struct TPMI_RH_OWNER_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[2];
} TPMI_RH_OWNER_mst;

typedef const struct TPMI_RH_ENDORSEMENT_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[2];
} TPMI_RH_ENDORSEMENT_mst;

typedef const struct TPMI_RH_PROVISION_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[2];
} TPMI_RH_PROVISION_mst;

typedef const struct TPMI_RH_CLEAR_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[2];
} TPMI_RH_CLEAR_mst;

typedef const struct TPMI_RH_NV_AUTH_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         ranges;
    UINT8         singles;
    UINT32        values[4];
} TPMI_RH_NV_AUTH_mst;

typedef const struct TPMI_RH_LOCKOUT_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[1];
} TPMI_RH_LOCKOUT_mst;

typedef const struct TPMI_RH_NV_INDEX_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} TPMI_RH_NV_INDEX_mst;

typedef const struct TPMI_RH_AC_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} TPMI_RH_AC_mst;

typedef const struct TPMI_RH_ACT_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} TPMI_RH_ACT_mst;

typedef const struct TPMI_ALG_HASH_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[5];
} TPMI_ALG_HASH_mst;

typedef const struct TPMI_ALG_ASYM_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[5];
} TPMI_ALG_ASYM_mst;

typedef const struct TPMI_ALG_SYM_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[5];
} TPMI_ALG_SYM_mst;

typedef const struct TPMI_ALG_SYM_OBJECT_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[5];
} TPMI_ALG_SYM_OBJECT_mst;

typedef const struct TPMI_ALG_SYM_MODE_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[4];
} TPMI_ALG_SYM_MODE_mst;

typedef const struct TPMI_ALG_KDF_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[4];
} TPMI_ALG_KDF_mst;

typedef const struct TPMI_ALG_SIG_SCHEME_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[4];
} TPMI_ALG_SIG_SCHEME_mst;

typedef const struct TPMI_ECC_KEY_EXCHANGE_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[4];
} TPMI_ECC_KEY_EXCHANGE_mst;

typedef const struct TPMI_ST_COMMAND_TAG_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[2];
} TPMI_ST_COMMAND_TAG_mst;

typedef const struct TPMI_ALG_MAC_SCHEME_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[5];
} TPMI_ALG_MAC_SCHEME_mst;

typedef const struct TPMI_ALG_CIPHER_MODE_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[4];
} TPMI_ALG_CIPHER_MODE_mst;

typedef const struct TPMS_EMPTY_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[3];
} TPMS_EMPTY_mst;

typedef const struct TPMS_ALGORITHM_DESCRIPTION_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_ALGORITHM_DESCRIPTION_mst;

typedef struct TPMU_HA_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[9];
    UINT16        marshalingTypes[9];
} TPMU_HA_mst;

typedef const struct TPMT_HA_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMT_HA_mst;

typedef const struct TPMS_PCR_SELECT_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_PCR_SELECT_mst;

typedef const struct TPMS_PCR_SELECTION_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[9];
} TPMS_PCR_SELECTION_mst;

typedef const struct TPMT_TK_CREATION_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[9];
} TPMT_TK_CREATION_mst;

typedef const struct TPMT_TK_VERIFIED_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[9];
} TPMT_TK_VERIFIED_mst;

typedef const struct TPMT_TK_AUTH_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[9];
} TPMT_TK_AUTH_mst;

typedef const struct TPMT_TK_HASHCHECK_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[9];
} TPMT_TK_HASHCHECK_mst;

typedef const struct TPMS_ALG_PROPERTY_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_ALG_PROPERTY_mst;

typedef const struct TPMS_TAGGED_PROPERTY_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_TAGGED_PROPERTY_mst;

typedef const struct TPMS_TAGGED_PCR_SELECT_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[9];
} TPMS_TAGGED_PCR_SELECT_mst;

typedef const struct TPMS_TAGGED_POLICY_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_TAGGED_POLICY_mst;

typedef const struct TPMS_ACT_DATA_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[9];
} TPMS_ACT_DATA_mst;

typedef struct TPMU_CAPABILITIES_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[11];
    UINT16        marshalingTypes[11];
} TPMU_CAPABILITIES_mst;

typedef const struct TPMS_CAPABILITY_DATA_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_CAPABILITY_DATA_mst;

typedef const struct TPMS_CLOCK_INFO_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[12];
} TPMS_CLOCK_INFO_mst;

typedef const struct TPMS_TIME_INFO_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_TIME_INFO_mst;

typedef const struct TPMS_TIME_ATTEST_INFO_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_TIME_ATTEST_INFO_mst;

typedef const struct TPMS_CERTIFY_INFO_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_CERTIFY_INFO_mst;

typedef const struct TPMS_QUOTE_INFO_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_QUOTE_INFO_mst;

typedef const struct TPMS_COMMAND_AUDIT_INFO_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[12];
} TPMS_COMMAND_AUDIT_INFO_mst;

typedef const struct TPMS_SESSION_AUDIT_INFO_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_SESSION_AUDIT_INFO_mst;

typedef const struct TPMS_CREATION_INFO_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_CREATION_INFO_mst;

typedef const struct TPMS_NV_CERTIFY_INFO_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[9];
} TPMS_NV_CERTIFY_INFO_mst;

typedef const struct TPMS_NV_DIGEST_CERTIFY_INFO_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_NV_DIGEST_CERTIFY_INFO_mst;

typedef const struct TPMI_ST_ATTEST_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         ranges;
    UINT8         singles;
    UINT32        values[3];
} TPMI_ST_ATTEST_mst;

typedef struct TPMU_ATTEST_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[8];
    UINT16        marshalingTypes[8];
} TPMU_ATTEST_mst;

typedef const struct TPMS_ATTEST_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[21];
} TPMS_ATTEST_mst;

typedef const struct TPMS_AUTH_COMMAND_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[12];
} TPMS_AUTH_COMMAND_mst;

typedef const struct TPMS_AUTH_RESPONSE_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[9];
} TPMS_AUTH_RESPONSE_mst;

typedef const struct TPMI_TDES_KEY_BITS_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[1];
} TPMI_TDES_KEY_BITS_mst;

typedef const struct TPMI_AES_KEY_BITS_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[3];
} TPMI_AES_KEY_BITS_mst;

typedef const struct TPMI_SM4_KEY_BITS_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[1];
} TPMI_SM4_KEY_BITS_mst;

typedef const struct TPMI_CAMELLIA_KEY_BITS_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[3];
} TPMI_CAMELLIA_KEY_BITS_mst;

typedef struct TPMU_SYM_KEY_BITS_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[6];
    UINT16        marshalingTypes[6];
} TPMU_SYM_KEY_BITS_mst;

typedef struct TPMU_SYM_MODE_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[6];
    UINT16        marshalingTypes[6];
} TPMU_SYM_MODE_mst;

typedef const struct TPMT_SYM_DEF_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[9];
} TPMT_SYM_DEF_mst;

typedef const struct TPMT_SYM_DEF_OBJECT_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[9];
} TPMT_SYM_DEF_OBJECT_mst;

typedef const struct TPMS_SYMCIPHER_PARMS_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[3];
} TPMS_SYMCIPHER_PARMS_mst;

typedef const struct TPMS_DERIVE_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_DERIVE_mst;

typedef const struct TPMS_SENSITIVE_CREATE_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_SENSITIVE_CREATE_mst;

typedef const struct TPMS_SCHEME_HASH_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[3];
} TPMS_SCHEME_HASH_mst;

typedef const struct TPMS_SCHEME_ECDAA_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_SCHEME_ECDAA_mst;

typedef const struct TPMI_ALG_KEYEDHASH_SCHEME_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[4];
} TPMI_ALG_KEYEDHASH_SCHEME_mst;

typedef const struct TPMS_SCHEME_XOR_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_SCHEME_XOR_mst;

typedef struct TPMU_SCHEME_KEYEDHASH_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[3];
    UINT16        marshalingTypes[3];
} TPMU_SCHEME_KEYEDHASH_mst;

typedef const struct TPMT_KEYEDHASH_SCHEME_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMT_KEYEDHASH_SCHEME_mst;

typedef struct TPMU_SIG_SCHEME_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[8];
    UINT16        marshalingTypes[8];
} TPMU_SIG_SCHEME_mst;

typedef const struct TPMT_SIG_SCHEME_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMT_SIG_SCHEME_mst;

typedef struct TPMU_KDF_SCHEME_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[5];
    UINT16        marshalingTypes[5];
} TPMU_KDF_SCHEME_mst;

typedef const struct TPMT_KDF_SCHEME_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMT_KDF_SCHEME_mst;

typedef const struct TPMI_ALG_ASYM_SCHEME_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[4];
} TPMI_ALG_ASYM_SCHEME_mst;

typedef struct TPMU_ASYM_SCHEME_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[11];
    UINT16        marshalingTypes[11];
} TPMU_ASYM_SCHEME_mst;

typedef const struct TPMI_ALG_RSA_SCHEME_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[4];
} TPMI_ALG_RSA_SCHEME_mst;

typedef const struct TPMT_RSA_SCHEME_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMT_RSA_SCHEME_mst;

typedef const struct TPMI_ALG_RSA_DECRYPT_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[4];
} TPMI_ALG_RSA_DECRYPT_mst;

typedef const struct TPMT_RSA_DECRYPT_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMT_RSA_DECRYPT_mst;

typedef const struct TPMI_RSA_KEY_BITS_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[3];
} TPMI_RSA_KEY_BITS_mst;

typedef const struct TPMS_ECC_POINT_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_ECC_POINT_mst;

typedef const struct TPMI_ALG_ECC_SCHEME_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[4];
} TPMI_ALG_ECC_SCHEME_mst;

typedef const struct TPMI_ECC_CURVE_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[3];
} TPMI_ECC_CURVE_mst;

typedef const struct TPMT_ECC_SCHEME_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMT_ECC_SCHEME_mst;

typedef const struct TPMS_ALGORITHM_DETAIL_ECC_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[33];
} TPMS_ALGORITHM_DETAIL_ECC_mst;

typedef const struct TPMS_SIGNATURE_RSA_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_SIGNATURE_RSA_mst;

typedef const struct TPMS_SIGNATURE_ECC_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[9];
} TPMS_SIGNATURE_ECC_mst;

typedef struct TPMU_SIGNATURE_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[8];
    UINT16        marshalingTypes[8];
} TPMU_SIGNATURE_mst;

typedef const struct TPMT_SIGNATURE_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMT_SIGNATURE_mst;

typedef struct TPMU_ENCRYPTED_SECRET_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[4];
    UINT16        marshalingTypes[4];
} TPMU_ENCRYPTED_SECRET_mst;

typedef const struct TPMI_ALG_PUBLIC_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[4];
} TPMI_ALG_PUBLIC_mst;

typedef struct TPMU_PUBLIC_ID_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[4];
    UINT16        marshalingTypes[4];
} TPMU_PUBLIC_ID_mst;

typedef const struct TPMS_KEYEDHASH_PARMS_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[3];
} TPMS_KEYEDHASH_PARMS_mst;

typedef const struct TPMS_RSA_PARMS_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[12];
} TPMS_RSA_PARMS_mst;

typedef const struct TPMS_ECC_PARMS_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[12];
} TPMS_ECC_PARMS_mst;

typedef struct TPMU_PUBLIC_PARMS_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[4];
    UINT16        marshalingTypes[4];
} TPMU_PUBLIC_PARMS_mst;

typedef const struct TPMT_PUBLIC_PARMS_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMT_PUBLIC_PARMS_mst;

typedef const struct TPMT_PUBLIC_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[18];
} TPMT_PUBLIC_mst;

typedef struct TPMU_SENSITIVE_COMPOSITE_mst
{
    BYTE            countOfselectors;
    BYTE            modifiers;
    UINT16        offsetOfUnmarshalTypes;
    UINT32        selectors[4];
    UINT16        marshalingTypes[4];
} TPMU_SENSITIVE_COMPOSITE_mst;

typedef const struct TPMT_SENSITIVE_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[12];
} TPMT_SENSITIVE_mst;

typedef const struct TPMS_NV_PIN_COUNTER_PARAMETERS_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_NV_PIN_COUNTER_PARAMETERS_mst;

typedef const struct TPMS_NV_PUBLIC_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[15];
} TPMS_NV_PUBLIC_mst;

typedef const struct TPMS_CONTEXT_DATA_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_CONTEXT_DATA_mst;

typedef const struct TPMS_CONTEXT_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[12];
} TPMS_CONTEXT_mst;

typedef const struct TPMS_CREATION_DATA_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[21];
} TPMS_CREATION_DATA_mst;

typedef const struct TPM_AT_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[4];
} TPM_AT_mst;

typedef const struct TPMS_AC_OUTPUT_mst
{
    UINT8     marshalType;
    UINT8     elements;
    UINT16    values[6];
} TPMS_AC_OUTPUT_mst;

typedef const struct Type02_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type02_mst;

typedef const struct Type03_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type03_mst;

typedef const struct Type04_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type04_mst;

typedef const struct Type06_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type06_mst;

typedef const struct Type08_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type08_mst;

typedef const struct Type10_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[1];
} Type10_mst;

typedef const struct Type11_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[1];
} Type11_mst;

typedef const struct Type12_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[2];
} Type12_mst;

typedef const struct Type13_mst {
    UINT8         marshalType;
    UINT8         modifiers;
    UINT8         errorCode;
    UINT8         entries;
    UINT32        values[1];
} Type13_mst;

typedef const struct Type15_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type15_mst;

typedef const struct Type17_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type17_mst;

typedef const struct Type18_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type18_mst;

typedef const struct Type19_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type19_mst;

typedef const struct Type20_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type20_mst;

typedef const struct Type22_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type22_mst;

typedef const struct Type23_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type23_mst;

typedef const struct Type24_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type24_mst;

typedef const struct Type25_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type25_mst;

typedef const struct Type26_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type26_mst;

typedef const struct Type27_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type27_mst;

typedef const struct Type29_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type29_mst;

typedef const struct Type30_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type30_mst;

typedef const struct Type33_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type33_mst;

typedef const struct Type34_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type34_mst;

typedef const struct Type35_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type35_mst;

typedef const struct Type38_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type38_mst;

typedef const struct Type41_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type41_mst;

typedef const struct Type42_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type42_mst;

typedef const struct Type44_mst {
    UINT8       marshalType;
    UINT8       modifiers;
    UINT8       errorCode;
    UINT32      values[2];
} Type44_mst;

// This structure combines all the individual marshaling structures to build
// something that can be referenced by offset rather than full address
typedef const struct MarshalData_st {
    UintMarshal_mst                 UINT8_DATA;
    UintMarshal_mst                 UINT16_DATA;
    UintMarshal_mst                 UINT32_DATA;
    UintMarshal_mst                 UINT64_DATA;
    UintMarshal_mst                 INT8_DATA;
    UintMarshal_mst                 INT16_DATA;
    UintMarshal_mst                 INT32_DATA;
    UintMarshal_mst                 INT64_DATA;
    UintMarshal_mst                 UINT0_DATA;
    TPM_ECC_CURVE_mst               TPM_ECC_CURVE_DATA;
    TPM_CLOCK_ADJUST_mst            TPM_CLOCK_ADJUST_DATA;
    TPM_EO_mst                      TPM_EO_DATA;
    TPM_SU_mst                      TPM_SU_DATA;
    TPM_SE_mst                      TPM_SE_DATA;
    TPM_CAP_mst                     TPM_CAP_DATA;
    AttributesMarshal_mst           TPMA_ALGORITHM_DATA;
    AttributesMarshal_mst           TPMA_OBJECT_DATA;
    AttributesMarshal_mst           TPMA_SESSION_DATA;
    AttributesMarshal_mst           TPMA_ACT_DATA;
    TPMI_YES_NO_mst                 TPMI_YES_NO_DATA;
    TPMI_DH_OBJECT_mst              TPMI_DH_OBJECT_DATA;
    TPMI_DH_PARENT_mst              TPMI_DH_PARENT_DATA;
    TPMI_DH_PERSISTENT_mst          TPMI_DH_PERSISTENT_DATA;
    TPMI_DH_ENTITY_mst              TPMI_DH_ENTITY_DATA;
    TPMI_DH_PCR_mst                 TPMI_DH_PCR_DATA;
    TPMI_SH_AUTH_SESSION_mst        TPMI_SH_AUTH_SESSION_DATA;
    TPMI_SH_HMAC_mst                TPMI_SH_HMAC_DATA;
    TPMI_SH_POLICY_mst              TPMI_SH_POLICY_DATA;
    TPMI_DH_CONTEXT_mst             TPMI_DH_CONTEXT_DATA;
    TPMI_DH_SAVED_mst               TPMI_DH_SAVED_DATA;
    TPMI_RH_HIERARCHY_mst           TPMI_RH_HIERARCHY_DATA;
    TPMI_RH_ENABLES_mst             TPMI_RH_ENABLES_DATA;
    TPMI_RH_HIERARCHY_AUTH_mst      TPMI_RH_HIERARCHY_AUTH_DATA;
    TPMI_RH_HIERARCHY_POLICY_mst    TPMI_RH_HIERARCHY_POLICY_DATA;
    TPMI_RH_PLATFORM_mst            TPMI_RH_PLATFORM_DATA;
    TPMI_RH_OWNER_mst               TPMI_RH_OWNER_DATA;
    TPMI_RH_ENDORSEMENT_mst         TPMI_RH_ENDORSEMENT_DATA;
    TPMI_RH_PROVISION_mst           TPMI_RH_PROVISION_DATA;
    TPMI_RH_CLEAR_mst               TPMI_RH_CLEAR_DATA;
    TPMI_RH_NV_AUTH_mst             TPMI_RH_NV_AUTH_DATA;
    TPMI_RH_LOCKOUT_mst             TPMI_RH_LOCKOUT_DATA;
    TPMI_RH_NV_INDEX_mst            TPMI_RH_NV_INDEX_DATA;
    TPMI_RH_AC_mst                  TPMI_RH_AC_DATA;
    TPMI_RH_ACT_mst                 TPMI_RH_ACT_DATA;
    TPMI_ALG_HASH_mst               TPMI_ALG_HASH_DATA;
    TPMI_ALG_ASYM_mst               TPMI_ALG_ASYM_DATA;
    TPMI_ALG_SYM_mst                TPMI_ALG_SYM_DATA;
    TPMI_ALG_SYM_OBJECT_mst         TPMI_ALG_SYM_OBJECT_DATA;
    TPMI_ALG_SYM_MODE_mst           TPMI_ALG_SYM_MODE_DATA;
    TPMI_ALG_KDF_mst                TPMI_ALG_KDF_DATA;
    TPMI_ALG_SIG_SCHEME_mst         TPMI_ALG_SIG_SCHEME_DATA;
    TPMI_ECC_KEY_EXCHANGE_mst       TPMI_ECC_KEY_EXCHANGE_DATA;
    TPMI_ST_COMMAND_TAG_mst         TPMI_ST_COMMAND_TAG_DATA;
    TPMI_ALG_MAC_SCHEME_mst         TPMI_ALG_MAC_SCHEME_DATA;
    TPMI_ALG_CIPHER_MODE_mst        TPMI_ALG_CIPHER_MODE_DATA;
    TPMS_EMPTY_mst                  TPMS_EMPTY_DATA;
    TPMS_ALGORITHM_DESCRIPTION_mst  TPMS_ALGORITHM_DESCRIPTION_DATA;
    TPMU_HA_mst                     TPMU_HA_DATA;
    TPMT_HA_mst                     TPMT_HA_DATA;
    Tpm2bMarshal_mst                TPM2B_DIGEST_DATA;
    Tpm2bMarshal_mst                TPM2B_DATA_DATA;
    Tpm2bMarshal_mst                TPM2B_EVENT_DATA;
    Tpm2bMarshal_mst                TPM2B_MAX_BUFFER_DATA;
    Tpm2bMarshal_mst                TPM2B_MAX_NV_BUFFER_DATA;
    Tpm2bMarshal_mst                TPM2B_TIMEOUT_DATA;
    Tpm2bMarshal_mst                TPM2B_IV_DATA;
    NullUnionMarshal_mst            NULL_UNION_DATA;
    Tpm2bMarshal_mst                TPM2B_NAME_DATA;
    TPMS_PCR_SELECT_mst             TPMS_PCR_SELECT_DATA;
    TPMS_PCR_SELECTION_mst          TPMS_PCR_SELECTION_DATA;
    TPMT_TK_CREATION_mst            TPMT_TK_CREATION_DATA;
    TPMT_TK_VERIFIED_mst            TPMT_TK_VERIFIED_DATA;
    TPMT_TK_AUTH_mst                TPMT_TK_AUTH_DATA;
    TPMT_TK_HASHCHECK_mst           TPMT_TK_HASHCHECK_DATA;
    TPMS_ALG_PROPERTY_mst           TPMS_ALG_PROPERTY_DATA;
    TPMS_TAGGED_PROPERTY_mst        TPMS_TAGGED_PROPERTY_DATA;
    TPMS_TAGGED_PCR_SELECT_mst      TPMS_TAGGED_PCR_SELECT_DATA;
    TPMS_TAGGED_POLICY_mst          TPMS_TAGGED_POLICY_DATA;
    TPMS_ACT_DATA_mst               TPMS_ACT_DATA_DATA;
    ListMarshal_mst                 TPML_CC_DATA;
    ListMarshal_mst                 TPML_CCA_DATA;
    ListMarshal_mst                 TPML_ALG_DATA;
    ListMarshal_mst                 TPML_HANDLE_DATA;
    ListMarshal_mst                 TPML_DIGEST_DATA;
    ListMarshal_mst                 TPML_DIGEST_VALUES_DATA;
    ListMarshal_mst                 TPML_PCR_SELECTION_DATA;
    ListMarshal_mst                 TPML_ALG_PROPERTY_DATA;
    ListMarshal_mst                 TPML_TAGGED_TPM_PROPERTY_DATA;
    ListMarshal_mst                 TPML_TAGGED_PCR_PROPERTY_DATA;
    ListMarshal_mst                 TPML_ECC_CURVE_DATA;
    ListMarshal_mst                 TPML_TAGGED_POLICY_DATA;
    ListMarshal_mst                 TPML_ACT_DATA_DATA;
    TPMU_CAPABILITIES_mst           TPMU_CAPABILITIES_DATA;
    TPMS_CAPABILITY_DATA_mst        TPMS_CAPABILITY_DATA_DATA;
    TPMS_CLOCK_INFO_mst             TPMS_CLOCK_INFO_DATA;
    TPMS_TIME_INFO_mst              TPMS_TIME_INFO_DATA;
    TPMS_TIME_ATTEST_INFO_mst       TPMS_TIME_ATTEST_INFO_DATA;
    TPMS_CERTIFY_INFO_mst           TPMS_CERTIFY_INFO_DATA;
    TPMS_QUOTE_INFO_mst             TPMS_QUOTE_INFO_DATA;
    TPMS_COMMAND_AUDIT_INFO_mst     TPMS_COMMAND_AUDIT_INFO_DATA;
    TPMS_SESSION_AUDIT_INFO_mst     TPMS_SESSION_AUDIT_INFO_DATA;
    TPMS_CREATION_INFO_mst          TPMS_CREATION_INFO_DATA;
    TPMS_NV_CERTIFY_INFO_mst        TPMS_NV_CERTIFY_INFO_DATA;
    TPMS_NV_DIGEST_CERTIFY_INFO_mst TPMS_NV_DIGEST_CERTIFY_INFO_DATA;
    TPMI_ST_ATTEST_mst              TPMI_ST_ATTEST_DATA;
    TPMU_ATTEST_mst                 TPMU_ATTEST_DATA;
    TPMS_ATTEST_mst                 TPMS_ATTEST_DATA;
    Tpm2bMarshal_mst                TPM2B_ATTEST_DATA;
    TPMS_AUTH_COMMAND_mst           TPMS_AUTH_COMMAND_DATA;
    TPMS_AUTH_RESPONSE_mst          TPMS_AUTH_RESPONSE_DATA;
    TPMI_TDES_KEY_BITS_mst          TPMI_TDES_KEY_BITS_DATA;
    TPMI_AES_KEY_BITS_mst           TPMI_AES_KEY_BITS_DATA;
    TPMI_SM4_KEY_BITS_mst           TPMI_SM4_KEY_BITS_DATA;
    TPMI_CAMELLIA_KEY_BITS_mst      TPMI_CAMELLIA_KEY_BITS_DATA;
    TPMU_SYM_KEY_BITS_mst           TPMU_SYM_KEY_BITS_DATA;
    TPMU_SYM_MODE_mst               TPMU_SYM_MODE_DATA;
    TPMT_SYM_DEF_mst                TPMT_SYM_DEF_DATA;
    TPMT_SYM_DEF_OBJECT_mst         TPMT_SYM_DEF_OBJECT_DATA;
    Tpm2bMarshal_mst                TPM2B_SYM_KEY_DATA;
    TPMS_SYMCIPHER_PARMS_mst        TPMS_SYMCIPHER_PARMS_DATA;
    Tpm2bMarshal_mst                TPM2B_LABEL_DATA;
    TPMS_DERIVE_mst                 TPMS_DERIVE_DATA;
    Tpm2bMarshal_mst                TPM2B_DERIVE_DATA;
    Tpm2bMarshal_mst                TPM2B_SENSITIVE_DATA_DATA;
    TPMS_SENSITIVE_CREATE_mst       TPMS_SENSITIVE_CREATE_DATA;
    Tpm2bsMarshal_mst               TPM2B_SENSITIVE_CREATE_DATA;
    TPMS_SCHEME_HASH_mst            TPMS_SCHEME_HASH_DATA;
    TPMS_SCHEME_ECDAA_mst           TPMS_SCHEME_ECDAA_DATA;
    TPMI_ALG_KEYEDHASH_SCHEME_mst   TPMI_ALG_KEYEDHASH_SCHEME_DATA;
    TPMS_SCHEME_XOR_mst             TPMS_SCHEME_XOR_DATA;
    TPMU_SCHEME_KEYEDHASH_mst       TPMU_SCHEME_KEYEDHASH_DATA;
    TPMT_KEYEDHASH_SCHEME_mst       TPMT_KEYEDHASH_SCHEME_DATA;
    TPMU_SIG_SCHEME_mst             TPMU_SIG_SCHEME_DATA;
    TPMT_SIG_SCHEME_mst             TPMT_SIG_SCHEME_DATA;
    TPMU_KDF_SCHEME_mst             TPMU_KDF_SCHEME_DATA;
    TPMT_KDF_SCHEME_mst             TPMT_KDF_SCHEME_DATA;
    TPMI_ALG_ASYM_SCHEME_mst        TPMI_ALG_ASYM_SCHEME_DATA;
    TPMU_ASYM_SCHEME_mst            TPMU_ASYM_SCHEME_DATA;
    TPMI_ALG_RSA_SCHEME_mst         TPMI_ALG_RSA_SCHEME_DATA;
    TPMT_RSA_SCHEME_mst             TPMT_RSA_SCHEME_DATA;
    TPMI_ALG_RSA_DECRYPT_mst        TPMI_ALG_RSA_DECRYPT_DATA;
    TPMT_RSA_DECRYPT_mst            TPMT_RSA_DECRYPT_DATA;
    Tpm2bMarshal_mst                TPM2B_PUBLIC_KEY_RSA_DATA;
    TPMI_RSA_KEY_BITS_mst           TPMI_RSA_KEY_BITS_DATA;
    Tpm2bMarshal_mst                TPM2B_PRIVATE_KEY_RSA_DATA;
    Tpm2bMarshal_mst                TPM2B_ECC_PARAMETER_DATA;
    TPMS_ECC_POINT_mst              TPMS_ECC_POINT_DATA;
    Tpm2bsMarshal_mst               TPM2B_ECC_POINT_DATA;
    TPMI_ALG_ECC_SCHEME_mst         TPMI_ALG_ECC_SCHEME_DATA;
    TPMI_ECC_CURVE_mst              TPMI_ECC_CURVE_DATA;
    TPMT_ECC_SCHEME_mst             TPMT_ECC_SCHEME_DATA;
    TPMS_ALGORITHM_DETAIL_ECC_mst   TPMS_ALGORITHM_DETAIL_ECC_DATA;
    TPMS_SIGNATURE_RSA_mst          TPMS_SIGNATURE_RSA_DATA;
    TPMS_SIGNATURE_ECC_mst          TPMS_SIGNATURE_ECC_DATA;
    TPMU_SIGNATURE_mst              TPMU_SIGNATURE_DATA;
    TPMT_SIGNATURE_mst              TPMT_SIGNATURE_DATA;
    TPMU_ENCRYPTED_SECRET_mst       TPMU_ENCRYPTED_SECRET_DATA;
    Tpm2bMarshal_mst                TPM2B_ENCRYPTED_SECRET_DATA;
    TPMI_ALG_PUBLIC_mst             TPMI_ALG_PUBLIC_DATA;
    TPMU_PUBLIC_ID_mst              TPMU_PUBLIC_ID_DATA;
    TPMS_KEYEDHASH_PARMS_mst        TPMS_KEYEDHASH_PARMS_DATA;
    TPMS_RSA_PARMS_mst              TPMS_RSA_PARMS_DATA;
    TPMS_ECC_PARMS_mst              TPMS_ECC_PARMS_DATA;
    TPMU_PUBLIC_PARMS_mst           TPMU_PUBLIC_PARMS_DATA;
    TPMT_PUBLIC_PARMS_mst           TPMT_PUBLIC_PARMS_DATA;
    TPMT_PUBLIC_mst                 TPMT_PUBLIC_DATA;
    Tpm2bsMarshal_mst               TPM2B_PUBLIC_DATA;
    Tpm2bMarshal_mst                TPM2B_TEMPLATE_DATA;
    Tpm2bMarshal_mst                TPM2B_PRIVATE_VENDOR_SPECIFIC_DATA;
    TPMU_SENSITIVE_COMPOSITE_mst    TPMU_SENSITIVE_COMPOSITE_DATA;
    TPMT_SENSITIVE_mst              TPMT_SENSITIVE_DATA;
    Tpm2bsMarshal_mst               TPM2B_SENSITIVE_DATA;
    Tpm2bMarshal_mst                TPM2B_PRIVATE_DATA;
    Tpm2bMarshal_mst                TPM2B_ID_OBJECT_DATA;
    TPMS_NV_PIN_COUNTER_PARAMETERS_mst TPMS_NV_PIN_COUNTER_PARAMETERS_DATA;
    AttributesMarshal_mst           TPMA_NV_DATA;
    TPMS_NV_PUBLIC_mst              TPMS_NV_PUBLIC_DATA;
    Tpm2bsMarshal_mst               TPM2B_NV_PUBLIC_DATA;
    Tpm2bMarshal_mst                TPM2B_CONTEXT_SENSITIVE_DATA;
    TPMS_CONTEXT_DATA_mst           TPMS_CONTEXT_DATA_DATA;
    Tpm2bMarshal_mst                TPM2B_CONTEXT_DATA_DATA;
    TPMS_CONTEXT_mst                TPMS_CONTEXT_DATA;
    TPMS_CREATION_DATA_mst          TPMS_CREATION_DATA_DATA;
    Tpm2bsMarshal_mst               TPM2B_CREATION_DATA_DATA;
    TPM_AT_mst                      TPM_AT_DATA;
    TPMS_AC_OUTPUT_mst              TPMS_AC_OUTPUT_DATA;
    ListMarshal_mst                 TPML_AC_CAPABILITIES_DATA;
    MinMaxMarshal_mst               Type00_DATA;
    MinMaxMarshal_mst               Type01_DATA;
    Type02_mst                      Type02_DATA;
    Type03_mst                      Type03_DATA;
    Type04_mst                      Type04_DATA;
    MinMaxMarshal_mst               Type05_DATA;
    Type06_mst                      Type06_DATA;
    MinMaxMarshal_mst               Type07_DATA;
    Type08_mst                      Type08_DATA;
    Type10_mst                      Type10_DATA;
    Type11_mst                      Type11_DATA;
    Type12_mst                      Type12_DATA;
    Type13_mst                      Type13_DATA;
    Type15_mst                      Type15_DATA;
    Type17_mst                      Type17_DATA;
    Type18_mst                      Type18_DATA;
    Type19_mst                      Type19_DATA;
    Type20_mst                      Type20_DATA;
    Type22_mst                      Type22_DATA;
    Type23_mst                      Type23_DATA;
    Type24_mst                      Type24_DATA;
    Type25_mst                      Type25_DATA;
    Type26_mst                      Type26_DATA;
    Type27_mst                      Type27_DATA;
    MinMaxMarshal_mst               Type28_DATA;
    Type29_mst                      Type29_DATA;
    Type30_mst                      Type30_DATA;
    MinMaxMarshal_mst               Type31_DATA;
    MinMaxMarshal_mst               Type32_DATA;
    Type33_mst                      Type33_DATA;
    Type34_mst                      Type34_DATA;
    Type35_mst                      Type35_DATA;
    MinMaxMarshal_mst               Type36_DATA;
    MinMaxMarshal_mst               Type37_DATA;
    Type38_mst                      Type38_DATA;
    MinMaxMarshal_mst               Type39_DATA;
    MinMaxMarshal_mst               Type40_DATA;
    Type41_mst                      Type41_DATA;
    Type42_mst                      Type42_DATA;
    MinMaxMarshal_mst               Type43_DATA;
    Type44_mst                      Type44_DATA;
} MarshalData_st;

#endif // _TABLE_MARSHAL_TYPES_H_
