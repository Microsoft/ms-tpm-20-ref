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
 *  Date: Mar  4, 2020  Time: 02:36:45PM
 */

#ifndef    _SIMULATOR_FP_H_
#define    _SIMULATOR_FP_H_

//** From TcpServer.c

#ifdef _MSC_VER
#elif defined(__unix__)
#endif

//*** PlatformServer()
// This function processes incoming platform requests.
bool
PlatformServer(
    SOCKET           s
);

//*** PlatformSvcRoutine()
// This function is called to set up the socket interfaces to listen for
// commands.
DWORD WINAPI
PlatformSvcRoutine(
    LPVOID           port
);

//*** PlatformSignalService()
// This function starts a new thread waiting for platform signals.
// Platform signals are processed one at a time in the order in which they are
// received.
int
PlatformSignalService(
    int              PortNumber
);

//*** RegularCommandService()
// This function services regular commands.
int
RegularCommandService(
    int              PortNumber
);

//*** StartTcpServer()
// This is the main entry-point to the TCP server.  The server listens on port
// specified.
//
// Note that there is no way to specify the network interface in this implementation.
int
StartTcpServer(
    int              PortNumber
);

//*** ReadBytes()
// This function reads the indicated number of bytes ('NumBytes') into buffer
// from the indicated socket.
bool
ReadBytes(
    SOCKET           s,
    char            *buffer,
    int              NumBytes
);

//*** WriteBytes()
// This function will send the indicated number of bytes ('NumBytes') to the
// indicated socket
bool
WriteBytes(
    SOCKET           s,
    char            *buffer,
    int              NumBytes
);

//*** WriteUINT32()
// Send 4 byte integer
bool
WriteUINT32(
    SOCKET           s,
    uint32_t         val
);

//*** ReadUINT32()
// Function to read 4 byte integer from socket.
bool
ReadUINT32(
    SOCKET           s,
    uint32_t        *val
);

//*** ReadVarBytes()
// Get a uint32-length-prepended binary array.  Note that the 4-byte length is
// in network byte order (big-endian).
bool
ReadVarBytes(
    SOCKET           s,
    char            *buffer,
    uint32_t        *BytesReceived,
    int              MaxLen
);

//*** WriteVarBytes()
// Send a UINT32-length-prepended binary array.  Note that the 4-byte length is
// in network byte order (big-endian).
bool
WriteVarBytes(
    SOCKET           s,
    char            *buffer,
    int              BytesToSend
);

//*** TpmServer()
// Processing incoming TPM command requests using the protocol / interface
// defined above.
bool
TpmServer(
    SOCKET           s
);


//** From TPMCmdp.c

#ifdef _MSC_VER
#elif defined(__unix__)
#endif

//*** Signal_PowerOn()
// This function processes a power-on indication. Among other things, it
// calls the _TPM_Init() handler.
void
_rpc__Signal_PowerOn(
    bool        isReset
);

//*** Signal_Restart()
// This function processes the clock restart indication. All it does is call
// the platform function.
void
_rpc__Signal_Restart(
    void
);

//***Signal_PowerOff()
// This function processes the power off indication. Its primary function is
// to set a flag indicating that the next power on indication should cause
// _TPM_Init() to be called.
void
_rpc__Signal_PowerOff(
    void
);

//*** _rpc__ForceFailureMode()
// This function is used to debug the Failure Mode logic of the TPM. It will set
// a flag in the TPM code such that the next call to TPM2_SelfTest() will result
// in a failure, putting the TPM into Failure Mode.
void
_rpc__ForceFailureMode(
    void
);

//*** _rpc__Signal_PhysicalPresenceOn()
// This function is called to simulate activation of the physical presence "pin".
void
_rpc__Signal_PhysicalPresenceOn(
    void
);

//*** _rpc__Signal_PhysicalPresenceOff()
// This function is called to simulate deactivation of the physical presence "pin".
void
_rpc__Signal_PhysicalPresenceOff(
    void
);

//*** _rpc__Signal_Hash_Start()
// This function is called to simulate a _TPM_Hash_Start event. It will call
//
void
_rpc__Signal_Hash_Start(
    void
);

//*** _rpc__Signal_Hash_Data()
// This function is called to simulate a _TPM_Hash_Data event.
void
_rpc__Signal_Hash_Data(
    _IN_BUFFER       input
);

//*** _rpc__Signal_HashEnd()
// This function is called to simulate a _TPM_Hash_End event.
void
_rpc__Signal_HashEnd(
    void
);

//*** _rpc__Send_Command()
// This is the interface to the TPM code.
//  Return Type: void
void
_rpc__Send_Command(
    unsigned char    locality,
    _IN_BUFFER       request,
    _OUT_BUFFER     *response
);

//*** _rpc__Signal_CancelOn()
// This function is used to turn on the indication to cancel a command in process.
// An executing command is not interrupted. The command code may periodically check
// this indication to see if it should abort the current command processing and
// returned TPM_RC_CANCELLED.
void
_rpc__Signal_CancelOn(
    void
);

//*** _rpc__Signal_CancelOff()
// This function is used to turn off the indication to cancel a command in process.
void
_rpc__Signal_CancelOff(
    void
);

//*** _rpc__Signal_NvOn()
// In a system where the NV memory used by the TPM is not within the TPM, the
// NV may not always be available. This function turns on the indicator that
// indicates that NV is available.
void
_rpc__Signal_NvOn(
    void
);

//*** _rpc__Signal_NvOff()
// This function is used to set the indication that NV memory is no
// longer available.
void
_rpc__Signal_NvOff(
    void
);

//*** _rpc__RsaKeyCacheControl()
// This function is used to enable/disable the use of the RSA key cache during
// simulation.
void
_rpc__RsaKeyCacheControl(
    int              state
);

//*** _rpc__ACT_GetSignaled()
// This function is used to count the ACT second tick.
bool
_rpc__ACT_GetSignaled(
    uint32_t actHandle
);


//** From TPMCmds.c

//*** main()
// This is the main entry point for the simulator.
// It registers the interface and starts listening for clients
int
main(
    int              argc,
    char            *argv[]
);

#endif  // _SIMULATOR_FP_H_
