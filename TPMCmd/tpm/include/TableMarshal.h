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

#ifndef _TABLE_MARSHAL_H_
#define _TABLE_MARSHAL_H_

// These are the basic unmarshaling types. This is in the first byte of
// each structure descriptor that is passed to Marshal()/Unmarshal() for processing.
#define UINT_MTYPE          0
#define VALUES_MTYPE        (UINT_MTYPE + 1)
#define TABLE_MTYPE         (VALUES_MTYPE + 1)
#define MIN_MAX_MTYPE       (TABLE_MTYPE + 1)
#define ATTRIBUTES_MTYPE    (MIN_MAX_MTYPE + 1)
#define STRUCTURE_MTYPE     (ATTRIBUTES_MTYPE + 1)
#define TPM2B_MTYPE         (STRUCTURE_MTYPE + 1)
#define TPM2BS_MTYPE        (TPM2B_MTYPE + 1)
#define LIST_MTYPE          (TPM2BS_MTYPE + 1) // TPML
#define ERROR_MTYPE         (LIST_MTYPE + 1)
#define NULL_MTYPE          (ERROR_MTYPE + 1)
#define COMPOSITE_MTYPE     (NULL_MTYPE + 1)

//*** The Marshal Index
// A structure is used to hold the values that guide the marshaling/unmarshaling of
// each of the types. Each structure has a name and an address. For a structure to
// define a TPMS_name, the structure is a TPMS_name_MARSHAL_STRUCT and its
// index is TPMS_name_MARSHAL_INDEX. So, to get the proper structure, use the
// associated marshal index. The marshal index is passed to Marshal() or Unmarshal()
// and those functions look up the proper structure.
//
// To handle structures that allow a null value, the upper bit of each marshal
// index indicates if the null value is allowed. This is the NULL_FLAG. It is defined
// in TableMarshalIndex.h because it is needed by code outside of the marshaling
// code.

// A structure will have a list of marshal indexes to indicate what to unmarshal. When
// that index appears in a structure/union, the value will contain a flag to indicate
// that the NULL_FLAG should be SET on the call to Unmarshal() to unmarshal the type.
// The caller simply takes the entry and passes it to Unmarshal() to indicate that the
// NULL_FLAG is SET. There is also the opportunity to SET the NULL_FLAG in the called
// structure if the NULL_FLAG was set in the call to the calling structure. This is
// indicated by:
#define NULL_MASK       ~(NULL_FLAG)

// When looking up the value to marshal, the upper bit of the marshal index is
// masked to yield the actual index. The MSb is the flag bit that indicates if a
// null flag is set. Code does not verify that the bit is clear when the called object
// does not take a flag as this is a benign error.

// the modifier byte as used by each MTYPE shown as a structure. They are expressed
// as a bit maps below. However, the code uses masking and not bit fields. The types
// show below are just to help in understanding.
// NOTE: LSb0 bit numbering is assumed in these typedefs.
//
// When used in an UINT_MTYPE
typedef struct integerModifier {
    unsigned            size : 2;
    unsigned            sign : 1;
    unsigned            unused : 7;
} integerModifier;

// When used in a VALUES_MTYPE
typedef struct valuesModifier {
    unsigned            size : 2;
    unsigned            sign : 1;
    unsigned            unused : 5;
    unsigned            takesNull : 1;
} valuesModifier;

// When used in a TABLE_MTYPE
typedef struct tableModifier {
    unsigned            size : 2;
    unsigned            sign : 1;
    unsigned            unused : 3;
    unsigned            hasBits : 1;
    unsigned            takesNull : 1;
} tableModifier;

// the modifier byte for MIN_MAX_MTYPE
typedef struct minMaxModifier {
    unsigned            size : 2;
    unsigned            sign : 1;
    unsigned            unused : 3;
    unsigned            hasBits : 1;
    unsigned            takesNull : 1;
} minMaxModifier;

// the modifier byte for ATTRIBUTES_MTYPE
typedef struct attributesModifier {
    unsigned            size : 2;
    unsigned            sign : 1;
    unsigned            unused : 5;
} attributesModifier;

// the modifier byte is not present in a STRUCTURE_MTYPE or an TPM2B_MTYPE

// the modifier byte for a TPM2BS_MTYPE
typedef struct tpm2bsModifier {
    unsigned            offset : 4;
    unsigned            unused : 2;
    unsigned            sizeEqual : 1;
    unsigned            propigateNull : 1;
} tpm2bsModifier;

// the modifier byte for a LIST_MTYPE
typedef struct listModifier {
    unsigned            offset : 4;
    unsigned            unused : 2;
    unsigned            sizeEqual : 1;
    unsigned            propigateNull : 1;
} listModifier;


//*** Modifier Octet Values
// These are in used in anything that is an integer value. Theses would not be in
// structure modifier bytes (they would be used in values in structures but not the
// STRUCTURE_MTYPE header.
#define ONE_BYTES           (0)
#define TWO_BYTES           (1)
#define FOUR_BYTES          (2)
#define EIGHT_BYTES         (3)
#define SIZE_MASK           (0x3)
#define IS_SIGNED           (1 << 2)    // when the unmarshaled type is a signed value
#define SIGNED_MASK         (SIZE_MASK | IS_SIGNED)

// This may be used for any type except a UINT_MTYPE
#define TAKES_NULL          (1 << 7)    // when the type takes a null

// When referencing a structure, this flag indicates if a null is to be propagated
// to the referenced structure or type.
#define PROPAGATE_NULL      (TAKES_NULL)

// Can be used in min-max or table structures.
#define HAS_BITS            (1 << 6)    // when bit mask is present

// In a union, we need to know if this is a union of constant arrays.
#define IS_ARRAY_UNION      (1 << 6)

// In a TPM2BS_MTYPE
#define SIZE_EQUAL          (1 << 6)
#define OFFSET_MASK         (0xF)

// Right now, there are three spare bits in the modifiers field.

// Within the descriptor word of each entry in a StructMarsh_mst, there is a selector
// field to determine which of the sub-types the entry represents and a field that is
// used to reference another structure entry. This is a 6-bit field allowing a
// structure to have 64 entries. This should be more than enough as the structures are
// not that long. As of now, only 10-bits of the descriptor word leaving room for
// expansion.

// These are the values used in a STRUCTURE_MTYPE to identify the sub-type of the
// thing being processed
#define SIMPLE_STYPE                0
#define UNION_STYPE                 1
#define ARRAY_STYPE                 2

// The code used GET_ to get the element type and the compiler uses SET_ to initialize
// the value. The element type is the three bits (2:0).
#define GET_ELEMENT_TYPE(val)       (val & 7)
#define SET_ELEMENT_TYPE(val)       (val & 7)

// When an entry is an array or union, this references the structure entry that
// contains the dimension or selector value. The code then uses this number to look up
// the structure entry for that element to find out what it and where is it in memory.
// When this is not a reference, it is a simple type and it could be used as an array
// value or a union selector. When a simple value, this field contains the size
// of the associated value (ONE_BYTES, TWO_BYTES ...)
//
// The entry size/number is 6 bits (13:8).
#define GET_ELEMENT_NUMBER(val)     (((val) >> 8) & 0x3F)
#define SET_ELEMENT_NUMBER(val)     (((val) & 0x3F) << 8)
#define GET_ELEMENT_SIZE(val)       GET_ELEMENT_NUMBER(val)
#define SET_ELEMENT_SIZE(val)       SET_ELEMENT_NUMBER(val)
// This determines if the null flag is propagated to this type. If generate, the
// NULL_FLAG is SET in the index value. This flag is one bit (7)
#define ELEMENT_PROPAGATE           (PROPAGATE_NULL)

#define INDEX_MASK                  ((UINT16)NULL_MASK)

// This is used in all bit-field checks. These are used when a value that is checked
// is conditional (dependent on the compilation). For example, if AES_128 is (NO),
// then the bit associated with AES_128 will be 0. In some cases, the bit value is
// found by checking that the input is within the range of the table, and then using
// the (val - min) value to index the bit. This would be used when verifying that
// a particular algorithm is implemented. In other cases, there is a bit for each
// value in a table. For example, if checking the key sizes, there is a list of
// possible key sizes allowed by the algorithm registry and a bit field to indicate
// if that key size is allowed in the implementation. The smallest bit field has
// 32-bits because it is implemented as part of the 'values' array in structures
// that allow bit fields.
#define IS_BIT_SET32(bit, bits)                                                     \
                        ((((UINT32 *)bits)[bit >> 5] & (1 << (bit & 0x1F))) != 0)

// For a COMPOSITE_MTYPE, the qualifiers byte has an element size and count.
#define SET_ELEMENT_COUNT(count)    ((count & 0x1F) << 3)
#define GET_ELEMENT_COUNT(val)      ((val  >> 3) & 0x1F)

#endif // _TABLE_MARSHAL_H_
