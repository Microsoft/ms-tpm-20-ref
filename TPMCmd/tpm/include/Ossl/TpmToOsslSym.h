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
//
// This header file is used to 'splice' the OpenSSL library into the TPM code.
//
// The support required of a library are a hash module, a block cipher module and
// portions of a big number library.

// All of the library-dependent headers should have the same guard to that only the
// first one gets defined.
#ifndef SYM_LIB_DEFINED
#define SYM_LIB_DEFINED

#define SYM_LIB_OSSL

#include <openssl/aes.h>

#if ALG_TDES
#include <openssl/des.h>
#endif

#if ALG_SM4
#   if defined(OPENSSL_NO_SM4) || OPENSSL_VERSION_NUMBER < 0x10101010L
#       undef ALG_SM4
#       define ALG_SM4  ALG_NO
#   elif OPENSSL_VERSION_NUMBER >= 0x10200000L
#       include <openssl/sm4.h>
#   else
        // OpenSSL 1.1.1 keeps smX.h headers in the include/crypto directory,
        // and they do not get installed as part of the libssl package

#       define SM4_KEY_SCHEDULE  32

        typedef struct SM4_KEY_st {
            uint32_t rk[SM4_KEY_SCHEDULE];
        } SM4_KEY;

        int SM4_set_key(const uint8_t *key, SM4_KEY *ks);
        void SM4_encrypt(const uint8_t *in, uint8_t *out, const SM4_KEY *ks);
        void SM4_decrypt(const uint8_t *in, uint8_t *out, const SM4_KEY *ks);
#   endif // OpenSSL < 1.2
#endif // ALG_SM4

#if ALG_CAMELLIA
#include <openssl/camellia.h>
#endif

#include <openssl/bn.h>
#include <openssl/ossl_typ.h>

//***************************************************************
//** Links to the OpenSSL symmetric algorithms.
//***************************************************************

// The Crypt functions that call the block encryption function use the parameters
// in the order:
//  1) keySchedule
//  2) in buffer
//  3) out buffer
// Since open SSL uses the order in encryptoCall_t above, need to swizzle the
// values to the order required by the library.
#define SWIZZLE(keySchedule, in, out)                                               \
    (const BYTE *)(in), (BYTE *)(out), (void *)(keySchedule)

// Define the order of parameters to the library functions that do block encryption
// and decryption.
typedef void(*TpmCryptSetSymKeyCall_t)(
    const BYTE  *in,
    BYTE        *out,
    void *keySchedule
    );

#define SYM_ALIGNMENT   RADIX_BYTES

//***************************************************************
//** Links to the OpenSSL AES code
//***************************************************************
// Macros to set up the encryption/decryption key schedules
//
// AES:
#define TpmCryptSetEncryptKeyAES(key, keySizeInBits, schedule)                      \
    AES_set_encrypt_key((key), (keySizeInBits), (tpmKeyScheduleAES *)(schedule))
#define TpmCryptSetDecryptKeyAES(key, keySizeInBits, schedule)                      \
    AES_set_decrypt_key((key), (keySizeInBits), (tpmKeyScheduleAES *)(schedule))

// Macros to alias encryption calls to specific algorithms. This should be used
// sparingly. Currently, only used by CryptSym.c and CryptRand.c
//
// When using these calls, to call the AES block encryption code, the caller
// should use:
//      TpmCryptEncryptAES(SWIZZLE(keySchedule, in, out));
#define TpmCryptEncryptAES          AES_encrypt
#define TpmCryptDecryptAES          AES_decrypt
#define tpmKeyScheduleAES           AES_KEY


//***************************************************************
//** Links to the OpenSSL DES code
//***************************************************************
#if ALG_TDES
#include "TpmToOsslDesSupport_fp.h"
#endif

#define TpmCryptSetEncryptKeyTDES(key, keySizeInBits, schedule)                     \
    TDES_set_encrypt_key((key), (keySizeInBits), (tpmKeyScheduleTDES *)(schedule))
#define TpmCryptSetDecryptKeyTDES(key, keySizeInBits, schedule)                     \
    TDES_set_encrypt_key((key), (keySizeInBits), (tpmKeyScheduleTDES *)(schedule))

// Macros to alias encryption calls to specific algorithms. This should be used
// sparingly. Currently, only used by CryptRand.c
#define TpmCryptEncryptTDES         TDES_encrypt
#define TpmCryptDecryptTDES         TDES_decrypt
#define tpmKeyScheduleTDES          DES_key_schedule


//***************************************************************
//** Links to the OpenSSL SM4 code
//***************************************************************
// Macros to set up the encryption/decryption key schedules
#define TpmCryptSetEncryptKeySM4(key, keySizeInBits, schedule)                      \
    SM4_set_key((key), (tpmKeyScheduleSM4 *)(schedule))
#define TpmCryptSetDecryptKeySM4(key, keySizeInBits, schedule)                      \
    SM4_set_key((key), (tpmKeyScheduleSM4 *)(schedule))

// Macros to alias encryption calls to specific algorithms. This should be used
// sparingly.
#define TpmCryptEncryptSM4          SM4_encrypt
#define TpmCryptDecryptSM4          SM4_decrypt
#define tpmKeyScheduleSM4           SM4_KEY


//***************************************************************
//** Links to the OpenSSL CAMELLIA code
//***************************************************************
// Macros to set up the encryption/decryption key schedules
#define TpmCryptSetEncryptKeyCAMELLIA(key, keySizeInBits, schedule)                 \
    Camellia_set_key((key), (keySizeInBits), (tpmKeyScheduleCAMELLIA *)(schedule))
#define TpmCryptSetDecryptKeyCAMELLIA(key, keySizeInBits, schedule)                 \
    Camellia_set_key((key), (keySizeInBits), (tpmKeyScheduleCAMELLIA *)(schedule))

// Macros to alias encryption calls to specific algorithms. This should be used
// sparingly.
#define TpmCryptEncryptCAMELLIA          Camellia_encrypt
#define TpmCryptDecryptCAMELLIA          Camellia_decrypt
#define tpmKeyScheduleCAMELLIA           CAMELLIA_KEY

// Forward reference

typedef union tpmCryptKeySchedule_t tpmCryptKeySchedule_t;

// This definition would change if there were something to report
#define SymLibSimulationEnd()

#endif // SYM_LIB_DEFINED
