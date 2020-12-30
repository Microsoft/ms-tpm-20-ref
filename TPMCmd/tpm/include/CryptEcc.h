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
// This file contains structure definitions used for ECC. The
// structures in this file are only used internally. The ECC-related structures
// that cross the TPM interface are defined in TpmTypes.h
//

#ifndef _CRYPT_ECC_H
#define _CRYPT_ECC_H

//** Structures

typedef struct ECC_CURVE
{
    const TPM_ECC_CURVE          curveId;
    const UINT16                 keySizeBits;
    const TPMT_KDF_SCHEME        kdf;
    const TPMT_ECC_SCHEME        sign;
    const ECC_CURVE_DATA        *curveData; // the address of the curve data
    const BYTE                  *OID;
} ECC_CURVE;

//*** Macros

// This macro is used to instance an ECC_CURVE_DATA structure for the curve. This
// structure is referenced by the ECC_CURVE structure
#define CURVE_DATA_DEF(CURVE)                                                       \
const ECC_CURVE_DATA CURVE = {                                                      \
    (bigNum)&CURVE##_p_DATA, (bigNum)&CURVE##_n_DATA, (bigNum)&CURVE##_h_DATA,      \
    (bigNum)&CURVE##_a_DATA, (bigNum)&CURVE##_b_DATA,                               \
    {(bigNum)&CURVE##_gX_DATA, (bigNum)&CURVE##_gY_DATA, (bigNum)&BN_ONE} };


extern const ECC_CURVE eccCurves[ECC_CURVE_COUNT];

#define CURVE_DEF(CURVE)                                                \
{                                                                       \
    TPM_ECC_##CURVE,                                                    \
    CURVE##_KEY_SIZE,                                                   \
    CURVE##_KDF,                                                        \
    CURVE##_SIGN,                                                       \
    &##CURVE,                                                           \
    OID_ECC_##CURVE                                                     \
}

#define CURVE_NAME(N)



#endif
