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
 *  Created by TpmStructures; Version 4.4 Mar 26, 2019
 *  Date: Feb 28, 2020  Time: 03:04:47PM
 */

#ifndef _COMMANDS_H_
#define _COMMANDS_H_


// Start-up
#if CC_Startup
#include "Startup_fp.h"
#endif
#if CC_Shutdown
#include "Shutdown_fp.h"
#endif

// Testing
#if CC_SelfTest
#include "SelfTest_fp.h"
#endif
#if CC_IncrementalSelfTest
#include "IncrementalSelfTest_fp.h"
#endif
#if CC_GetTestResult
#include "GetTestResult_fp.h"
#endif

// Session Commands
#if CC_StartAuthSession
#include "StartAuthSession_fp.h"
#endif
#if CC_PolicyRestart
#include "PolicyRestart_fp.h"
#endif

// Object Commands
#if CC_Create
#include "Create_fp.h"
#endif
#if CC_Load
#include "Load_fp.h"
#endif
#if CC_LoadExternal
#include "LoadExternal_fp.h"
#endif
#if CC_ReadPublic
#include "ReadPublic_fp.h"
#endif
#if CC_ActivateCredential
#include "ActivateCredential_fp.h"
#endif
#if CC_MakeCredential
#include "MakeCredential_fp.h"
#endif
#if CC_Unseal
#include "Unseal_fp.h"
#endif
#if CC_ObjectChangeAuth
#include "ObjectChangeAuth_fp.h"
#endif
#if CC_CreateLoaded
#include "CreateLoaded_fp.h"
#endif

// Duplication Commands
#if CC_Duplicate
#include "Duplicate_fp.h"
#endif
#if CC_Rewrap
#include "Rewrap_fp.h"
#endif
#if CC_Import
#include "Import_fp.h"
#endif

// Asymmetric Primitives
#if CC_RSA_Encrypt
#include "RSA_Encrypt_fp.h"
#endif
#if CC_RSA_Decrypt
#include "RSA_Decrypt_fp.h"
#endif
#if CC_ECDH_KeyGen
#include "ECDH_KeyGen_fp.h"
#endif
#if CC_ECDH_ZGen
#include "ECDH_ZGen_fp.h"
#endif
#if CC_ECC_Parameters
#include "ECC_Parameters_fp.h"
#endif
#if CC_ZGen_2Phase
#include "ZGen_2Phase_fp.h"
#endif
#if CC_ECC_Encrypt
#include "ECC_Encrypt_fp.h"
#endif
#if CC_ECC_Decrypt
#include "ECC_Decrypt_fp.h"
#endif

// Symmetric Primitives
#if CC_EncryptDecrypt
#include "EncryptDecrypt_fp.h"
#endif
#if CC_EncryptDecrypt2
#include "EncryptDecrypt2_fp.h"
#endif
#if CC_Hash
#include "Hash_fp.h"
#endif
#if CC_HMAC
#include "HMAC_fp.h"
#endif
#if CC_MAC
#include "MAC_fp.h"
#endif

// Random Number Generator
#if CC_GetRandom
#include "GetRandom_fp.h"
#endif
#if CC_StirRandom
#include "StirRandom_fp.h"
#endif

// Hash/HMAC/Event Sequences
#if CC_HMAC_Start
#include "HMAC_Start_fp.h"
#endif
#if CC_MAC_Start
#include "MAC_Start_fp.h"
#endif
#if CC_HashSequenceStart
#include "HashSequenceStart_fp.h"
#endif
#if CC_SequenceUpdate
#include "SequenceUpdate_fp.h"
#endif
#if CC_SequenceComplete
#include "SequenceComplete_fp.h"
#endif
#if CC_EventSequenceComplete
#include "EventSequenceComplete_fp.h"
#endif

// Attestation Commands
#if CC_Certify
#include "Certify_fp.h"
#endif
#if CC_CertifyCreation
#include "CertifyCreation_fp.h"
#endif
#if CC_Quote
#include "Quote_fp.h"
#endif
#if CC_GetSessionAuditDigest
#include "GetSessionAuditDigest_fp.h"
#endif
#if CC_GetCommandAuditDigest
#include "GetCommandAuditDigest_fp.h"
#endif
#if CC_GetTime
#include "GetTime_fp.h"
#endif
#if CC_CertifyX509
#include "CertifyX509_fp.h"
#endif

// Ephemeral EC Keys
#if CC_Commit
#include "Commit_fp.h"
#endif
#if CC_EC_Ephemeral
#include "EC_Ephemeral_fp.h"
#endif

// Signing and Signature Verification
#if CC_VerifySignature
#include "VerifySignature_fp.h"
#endif
#if CC_Sign
#include "Sign_fp.h"
#endif

// Command Audit
#if CC_SetCommandCodeAuditStatus
#include "SetCommandCodeAuditStatus_fp.h"
#endif

// Integrity Collection (PCR)
#if CC_PCR_Extend
#include "PCR_Extend_fp.h"
#endif
#if CC_PCR_Event
#include "PCR_Event_fp.h"
#endif
#if CC_PCR_Read
#include "PCR_Read_fp.h"
#endif
#if CC_PCR_Allocate
#include "PCR_Allocate_fp.h"
#endif
#if CC_PCR_SetAuthPolicy
#include "PCR_SetAuthPolicy_fp.h"
#endif
#if CC_PCR_SetAuthValue
#include "PCR_SetAuthValue_fp.h"
#endif
#if CC_PCR_Reset
#include "PCR_Reset_fp.h"
#endif

// Enhanced Authorization (EA) Commands
#if CC_PolicySigned
#include "PolicySigned_fp.h"
#endif
#if CC_PolicySecret
#include "PolicySecret_fp.h"
#endif
#if CC_PolicyTicket
#include "PolicyTicket_fp.h"
#endif
#if CC_PolicyOR
#include "PolicyOR_fp.h"
#endif
#if CC_PolicyPCR
#include "PolicyPCR_fp.h"
#endif
#if CC_PolicyLocality
#include "PolicyLocality_fp.h"
#endif
#if CC_PolicyNV
#include "PolicyNV_fp.h"
#endif
#if CC_PolicyCounterTimer
#include "PolicyCounterTimer_fp.h"
#endif
#if CC_PolicyCommandCode
#include "PolicyCommandCode_fp.h"
#endif
#if CC_PolicyPhysicalPresence
#include "PolicyPhysicalPresence_fp.h"
#endif
#if CC_PolicyCpHash
#include "PolicyCpHash_fp.h"
#endif
#if CC_PolicyNameHash
#include "PolicyNameHash_fp.h"
#endif
#if CC_PolicyDuplicationSelect
#include "PolicyDuplicationSelect_fp.h"
#endif
#if CC_PolicyAuthorize
#include "PolicyAuthorize_fp.h"
#endif
#if CC_PolicyAuthValue
#include "PolicyAuthValue_fp.h"
#endif
#if CC_PolicyPassword
#include "PolicyPassword_fp.h"
#endif
#if CC_PolicyGetDigest
#include "PolicyGetDigest_fp.h"
#endif
#if CC_PolicyNvWritten
#include "PolicyNvWritten_fp.h"
#endif
#if CC_PolicyTemplate
#include "PolicyTemplate_fp.h"
#endif
#if CC_PolicyAuthorizeNV
#include "PolicyAuthorizeNV_fp.h"
#endif

// Hierarchy Commands
#if CC_CreatePrimary
#include "CreatePrimary_fp.h"
#endif
#if CC_HierarchyControl
#include "HierarchyControl_fp.h"
#endif
#if CC_SetPrimaryPolicy
#include "SetPrimaryPolicy_fp.h"
#endif
#if CC_ChangePPS
#include "ChangePPS_fp.h"
#endif
#if CC_ChangeEPS
#include "ChangeEPS_fp.h"
#endif
#if CC_Clear
#include "Clear_fp.h"
#endif
#if CC_ClearControl
#include "ClearControl_fp.h"
#endif
#if CC_HierarchyChangeAuth
#include "HierarchyChangeAuth_fp.h"
#endif

// Dictionary Attack Functions
#if CC_DictionaryAttackLockReset
#include "DictionaryAttackLockReset_fp.h"
#endif
#if CC_DictionaryAttackParameters
#include "DictionaryAttackParameters_fp.h"
#endif

// Miscellaneous Management Functions
#if CC_PP_Commands
#include "PP_Commands_fp.h"
#endif
#if CC_SetAlgorithmSet
#include "SetAlgorithmSet_fp.h"
#endif

// Field Upgrade
#if CC_FieldUpgradeStart
#include "FieldUpgradeStart_fp.h"
#endif
#if CC_FieldUpgradeData
#include "FieldUpgradeData_fp.h"
#endif
#if CC_FirmwareRead
#include "FirmwareRead_fp.h"
#endif

// Context Management
#if CC_ContextSave
#include "ContextSave_fp.h"
#endif
#if CC_ContextLoad
#include "ContextLoad_fp.h"
#endif
#if CC_FlushContext
#include "FlushContext_fp.h"
#endif
#if CC_EvictControl
#include "EvictControl_fp.h"
#endif

// Clocks and Timers
#if CC_ReadClock
#include "ReadClock_fp.h"
#endif
#if CC_ClockSet
#include "ClockSet_fp.h"
#endif
#if CC_ClockRateAdjust
#include "ClockRateAdjust_fp.h"
#endif

// Capability Commands
#if CC_GetCapability
#include "GetCapability_fp.h"
#endif
#if CC_TestParms
#include "TestParms_fp.h"
#endif

// Non-volatile Storage
#if CC_NV_DefineSpace
#include "NV_DefineSpace_fp.h"
#endif
#if CC_NV_UndefineSpace
#include "NV_UndefineSpace_fp.h"
#endif
#if CC_NV_UndefineSpaceSpecial
#include "NV_UndefineSpaceSpecial_fp.h"
#endif
#if CC_NV_ReadPublic
#include "NV_ReadPublic_fp.h"
#endif
#if CC_NV_Write
#include "NV_Write_fp.h"
#endif
#if CC_NV_Increment
#include "NV_Increment_fp.h"
#endif
#if CC_NV_Extend
#include "NV_Extend_fp.h"
#endif
#if CC_NV_SetBits
#include "NV_SetBits_fp.h"
#endif
#if CC_NV_WriteLock
#include "NV_WriteLock_fp.h"
#endif
#if CC_NV_GlobalWriteLock
#include "NV_GlobalWriteLock_fp.h"
#endif
#if CC_NV_Read
#include "NV_Read_fp.h"
#endif
#if CC_NV_ReadLock
#include "NV_ReadLock_fp.h"
#endif
#if CC_NV_ChangeAuth
#include "NV_ChangeAuth_fp.h"
#endif
#if CC_NV_Certify
#include "NV_Certify_fp.h"
#endif

// Attached Components
#if CC_AC_GetCapability
#include "AC_GetCapability_fp.h"
#endif
#if CC_AC_Send
#include "AC_Send_fp.h"
#endif
#if CC_Policy_AC_SendSelect
#include "Policy_AC_SendSelect_fp.h"
#endif

// Authenticated Countdown Timer
#if CC_ACT_SetTimeout
#include "ACT_SetTimeout_fp.h"
#endif

// Vendor Specific
#if CC_Vendor_TCG_Test
#include "Vendor_TCG_Test_fp.h"
#endif

#endif
