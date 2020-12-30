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
 *  Created by TpmPrototypes; Version 3.0 July 18, 2017
 *  Date: Aug 30, 2019  Time: 02:11:54PM
 */

#ifndef    _CRYPT_PRIME_FP_H_
#define    _CRYPT_PRIME_FP_H_

//*** IsPrimeInt()
// This will do a test of a word of up to 32-bits in size.
BOOL
IsPrimeInt(
    uint32_t            n
);

//*** BnIsProbablyPrime()
// This function is used when the key sieve is not implemented. This function
// Will try to eliminate some of the obvious things before going on
// to perform MillerRabin as a final verification of primeness.
BOOL
BnIsProbablyPrime(
    bigNum          prime,           // IN:
    RAND_STATE      *rand            // IN: the random state just
                                     //     in case Miller-Rabin is required
);

//*** MillerRabinRounds()
// Function returns the number of Miller-Rabin rounds necessary to give an
// error probability equal to the security strength of the prime. These values
// are from FIPS 186-3.
UINT32
MillerRabinRounds(
    UINT32           bits           // IN: Number of bits in the RSA prime
);

//*** MillerRabin()
// This function performs a Miller-Rabin test from FIPS 186-3. It does
// 'iterations' trials on the number. In all likelihood, if the number
// is not prime, the first test fails.
//  Return Type: BOOL
//      TRUE(1)         probably prime
//      FALSE(0)        composite
BOOL
MillerRabin(
    bigNum           bnW,
    RAND_STATE      *rand
);
#if ALG_RSA

//*** RsaCheckPrime()
// This will check to see if a number is prime and appropriate for an
// RSA prime.
//
// This has different functionality based on whether we are using key
// sieving or not. If not, the number checked to see if it is divisible by
// the public exponent, then the number is adjusted either up or down
// in order to make it a better candidate. It is then checked for being
// probably prime.
//
// If sieving is used, the number is used to root a sieving process.
//
TPM_RC
RsaCheckPrime(
    bigNum           prime,
    UINT32           exponent,
    RAND_STATE      *rand
);

//*** RsaAdjustPrimeCandiate()
// For this math, we assume that the RSA numbers are fixed-point numbers with
// the decimal point to the "left" of the most significant bit. This approach helps
// make it clear what is happening with the MSb of the values.
// The two RSA primes have to be large enough so that their product will be a number
// with the necessary number of significant bits. For example, we want to be able
// to multiply two 1024-bit numbers to produce a number with 2028 significant bits. If
// we accept any 1024-bit prime that has its MSb set, then it is possible to produce a
// product that does not have the MSb SET. For example, if we use tiny keys of 16 bits
// and have two 8-bit 'primes' of 0x80, then the public key would be 0x4000 which is
// only 15-bits. So, what we need to do is made sure that each of the primes is large
// enough so that the product of the primes is twice as large as each prime. A little
// arithmetic will show that the only way to do this is to make sure that each of the
// primes is no less than root(2)/2. That's what this functions does.
// This function adjusts the candidate prime so that it is odd and >= root(2)/2.
// This allows the product of these two numbers to be .5, which, in fixed point
// notation means that the most significant bit is 1.
// For this routine, the root(2)/2 (0.7071067811865475) approximated with 0xB505
// which is, in fixed point, 0.7071075439453125 or an error of 0.000108%. Just setting
// the upper two bits would give a value > 0.75 which is an error of > 6%. Given the
// amount of time all the other computations take, reducing the error is not much of
// a cost, but it isn't totally required either.
//
// This function can be replaced with a function that just sets the two most
// significant bits of each prime candidate without introducing any computational
// issues.
//
LIB_EXPORT void
RsaAdjustPrimeCandidate(
    bigNum          prime
);

//***BnGeneratePrimeForRSA()
// Function to generate a prime of the desired size with the proper attributes
// for an RSA prime.
TPM_RC
BnGeneratePrimeForRSA(
    bigNum          prime,          // IN/OUT: points to the BN that will get the
                                    //  random value
    UINT32          bits,           // IN: number of bits to get
    UINT32          exponent,       // IN: the exponent
    RAND_STATE      *rand           // IN: the random state
);
#endif // ALG_RSA

#endif  // _CRYPT_PRIME_FP_H_
