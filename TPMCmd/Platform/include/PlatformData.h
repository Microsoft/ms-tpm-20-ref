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
// This file contains the instance data for the Platform module. It is collected
// in this file so that the state of the module is easier to manage.

#ifndef _PLATFORM_DATA_H_
#define _PLATFORM_DATA_H_

#ifdef  _PLATFORM_DATA_C_
#define EXTERN
#else
#define EXTERN  extern
#endif

// From Cancel.c
// Cancel flag.  It is initialized as FALSE, which indicate the command is not
// being canceled
EXTERN int     s_isCanceled;

#ifndef HARDWARE_CLOCK
typedef uint64_t     clock64_t;
// This is the value returned the last time that the system clock was read. This
// is only relevant for a simulator or virtual TPM.
EXTERN clock64_t       s_realTimePrevious;

// These values are used to try to synthesize a long lived version of clock().
EXTERN clock64_t        s_lastSystemTime;
EXTERN clock64_t        s_lastReportedTime;

// This is the rate adjusted value that is the equivalent of what would be read from
// a hardware register that produced rate adjusted time.
EXTERN clock64_t        s_tpmTime;
#endif // HARDWARE_CLOCK

// This value indicates that the timer was reset
EXTERN int               s_timerReset;
// This value indicates that the timer was stopped. It causes a clock discontinuity.
EXTERN int               s_timerStopped;

// This variable records the time when _plat__TimerReset is called.  This mechanism
// allow us to subtract the time when TPM is power off from the total
// time reported by clock() function
EXTERN uint64_t        s_initClock;

// This variable records the timer adjustment factor.
EXTERN unsigned int         s_adjustRate;

// For LocalityPlat.c
// Locality of current command
EXTERN unsigned char s_locality;

// For NVMem.c
// Choose if the NV memory should be backed by RAM or by file.
// If this macro is defined, then a file is used as NV.  If it is not defined,
// then RAM is used to back NV memory. Comment out to use RAM.

#if (!defined VTPM) || ((VTPM != NO) && (VTPM != YES))
#   undef VTPM
#   define      VTPM            YES                 // Default: Either YES or NO
#endif

// For a simulation, use a file to back up the NV
#if (!defined FILE_BACKED_NV) || ((FILE_BACKED_NV != NO) && (FILE_BACKED_NV != YES))
#   undef   FILE_BACKED_NV
#   define  FILE_BACKED_NV          (VTPM && YES)     // Default: Either YES or NO
#endif

#if SIMULATION
#   undef       FILE_BACKED_NV
#   define      FILE_BACKED_NV          YES
#endif // SIMULATION

EXTERN unsigned char     s_NV[NV_MEMORY_SIZE];
EXTERN int               s_NvIsAvailable;
EXTERN int               s_NV_unrecoverable;
EXTERN int               s_NV_recoverable;

// For PPPlat.c
// Physical presence.  It is initialized to FALSE
EXTERN int              s_physicalPresence;

// From Power
EXTERN int              s_powerLost;

// For Entropy.c
EXTERN uint32_t         lastEntropy;

#define DEFINE_ACT(N)   EXTERN ACT_DATA ACT_##N;
    FOR_EACH_ACT(DEFINE_ACT)

EXTERN int              actTicksAllowed;

#endif // _PLATFORM_DATA_H_
