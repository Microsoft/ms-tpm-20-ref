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
//** Description
//
//    This file contains the NV read and write access methods.  This implementation
//    uses RAM/file and does not manage the RAM/file as NV blocks.
//    The implementation may become more sophisticated over time.
//

//** Includes and Local
#include <memory.h>
#include <string.h>
#include <assert.h>
#include "Platform.h"
#if FILE_BACKED_NV
#   include         <stdio.h>
static FILE         *s_NvFile = NULL;
static int           s_NeedsManufacture = FALSE;
#endif

//**Functions

#if FILE_BACKED_NV

//*** NvFileOpen()
// This function opens the file used to hold the NV image.
//  Return Type: int
//  >= 0        success
//  -1          error
static int
NvFileOpen(
    const char      *mode
)
{
#if defined(NV_FILE_PATH)
#   define TO_STRING(s) TO_STRING_IMPL(s)
#   define TO_STRING_IMPL(s) #s
    const char* s_NvFilePath = TO_STRING(NV_FILE_PATH);
#   undef TO_STRING
#   undef TO_STRING_IMPL
#else
    const char* s_NvFilePath = "NVChip";
#endif

    // Try to open an exist NVChip file for read/write
#   if defined _MSC_VER && 1
    if(fopen_s(&s_NvFile, s_NvFilePath, mode) != 0)
        s_NvFile = NULL;
#   else
    s_NvFile = fopen(s_NvFilePath, mode);
#   endif
    return (s_NvFile == NULL) ? -1 : 0;
}

//*** NvFileCommit()
// Write all of the contents of the NV image to a file.
//  Return Type: int
//      TRUE(1)         success
//      FALSE(0)        failure
static int
NvFileCommit(
    void
)
{
    int         OK;
    // If NV file is not available, return failure
    if(s_NvFile == NULL)
        return 1;
    // Write RAM data to NV
    fseek(s_NvFile, 0, SEEK_SET);
    OK = (NV_MEMORY_SIZE == fwrite(s_NV, 1, NV_MEMORY_SIZE, s_NvFile));
    OK = OK && (0 == fflush(s_NvFile));
    assert(OK);
    return OK;
}

//*** NvFileSize()
// This function gets the size of the NV file and puts the file pointer where desired
// using the seek method values. SEEK_SET => beginning; SEEK_CUR => current position
// and SEEK_END => to the end of the file.
static long
NvFileSize(
    int         leaveAt
)
{
    long    fileSize;
    long    filePos = ftell(s_NvFile);
//
    assert(NULL != s_NvFile);

    int fseek_result = fseek(s_NvFile, 0, SEEK_END);
    NOT_REFERENCED(fseek_result); // Fix compiler warning for NDEBUG
    assert(fseek_result == 0);
    fileSize = ftell(s_NvFile);
    assert(fileSize >= 0);
    switch(leaveAt)
    {
        case SEEK_SET:
            filePos = 0;
        case SEEK_CUR:
            fseek(s_NvFile, filePos, SEEK_SET);
            break;
        case SEEK_END:
            break;
        default:
            assert(FALSE);
            break;
    }
    return fileSize;
}
#endif

//*** _plat__NvErrors()
// This function is used by the simulator to set the error flags in the NV
// subsystem to simulate an error in the NV loading process
LIB_EXPORT void
_plat__NvErrors(
    int              recoverable,
    int              unrecoverable
    )
{
    s_NV_unrecoverable = unrecoverable;
    s_NV_recoverable = recoverable;
}

//***_plat__NVEnable()
// Enable NV memory.
//
// This version just pulls in data from a file. In a real TPM, with NV on chip,
// this function would verify the integrity of the saved context. If the NV
// memory was not on chip but was in something like RPMB, the NV state would be
// read in, decrypted and integrity checked.
//
// The recovery from an integrity failure depends on where the error occurred. It
// it was in the state that is discarded by TPM Reset, then the error is
// recoverable if the TPM is reset. Otherwise, the TPM must go into failure mode.
//  Return Type: int
//      0           if success
//      > 0         if receive recoverable error
//      <0          if unrecoverable error
LIB_EXPORT int
_plat__NVEnable(
    void            *platParameter  // IN: platform specific parameters
    )
{
    NOT_REFERENCED(platParameter);          // to keep compiler quiet
//
    // Start assuming everything is OK
    s_NV_unrecoverable = FALSE;
    s_NV_recoverable = FALSE;
#if FILE_BACKED_NV
    if(s_NvFile != NULL)
        return 0;
    // Initialize all the bytes in the ram copy of the NV
    _plat__NvMemoryClear(0, NV_MEMORY_SIZE);

    // If the file exists
    if(NvFileOpen("r+b") >= 0)
    {
        long    fileSize = NvFileSize(SEEK_SET);    // get the file size and leave the
                                                    // file pointer at the start
//
        // If the size is right, read the data
        if (NV_MEMORY_SIZE == fileSize)
        {
            s_NeedsManufacture =
                fread(s_NV, 1, NV_MEMORY_SIZE, s_NvFile) != NV_MEMORY_SIZE;
        }
        else
        {
            NvFileCommit();     // for any other size, initialize it
            s_NeedsManufacture = TRUE;
        }
    }
    // If NVChip file does not exist, try to create it for read/write.
    else if(NvFileOpen("w+b") >= 0)
    {
        NvFileCommit();             // Initialize the file
        s_NeedsManufacture = TRUE;
    }
    assert(NULL != s_NvFile);       // Just in case we are broken for some reason.
#endif
    // NV contents have been initialized and the error checks have been performed. For
    // simulation purposes, use the signaling interface to indicate if an error is
    // to be simulated and the type of the error.
    if(s_NV_unrecoverable)
        return -1;
    return s_NV_recoverable;
}

//***_plat__NVDisable()
// Disable NV memory
LIB_EXPORT void
_plat__NVDisable(
    int              delete           // IN: If TRUE, delete the NV contents.
    )
{
#if  FILE_BACKED_NV
    if(NULL != s_NvFile)
    {
        fclose(s_NvFile);    // Close NV file
        // Alternative to deleting the file is to set its size to 0. This will not
        // match the NV size so the TPM will need to be remanufactured.
        if(delete)
        {
            // Open for writing at the start. Sets the size to zero.
            if(NvFileOpen("w") >= 0)
            {
                fflush(s_NvFile);
                fclose(s_NvFile);
            }
        }
    }
    s_NvFile = NULL;        // Set file handle to NULL
#endif
    return;
}

//***_plat__IsNvAvailable()
// Check if NV is available
//  Return Type: int
//      0               NV is available
//      1               NV is not available due to write failure
//      2               NV is not available due to rate limit
LIB_EXPORT int
_plat__IsNvAvailable(
    void
    )
{
    int         retVal = 0;
    // NV is not available if the TPM is in failure mode
    if(!s_NvIsAvailable)
        retVal = 1;
#if FILE_BACKED_NV
    else
        retVal = (s_NvFile == NULL);
#endif
    return retVal;
}

//***_plat__NvMemoryRead()
// Function: Read a chunk of NV memory
LIB_EXPORT void
_plat__NvMemoryRead(
    unsigned int     startOffset,   // IN: read start
    unsigned int     size,          // IN: size of bytes to read
    void            *data           // OUT: data buffer
    )
{
    assert(startOffset + size <= NV_MEMORY_SIZE);
    memcpy(data, &s_NV[startOffset], size);     // Copy data from RAM
    return;
}

//*** _plat__NvIsDifferent()
// This function checks to see if the NV is different from the test value. This is
// so that NV will not be written if it has not changed.
//  Return Type: int
//      TRUE(1)         the NV location is different from the test value
//      FALSE(0)        the NV location is the same as the test value
LIB_EXPORT int
_plat__NvIsDifferent(
    unsigned int     startOffset,   // IN: read start
    unsigned int     size,          // IN: size of bytes to read
    void            *data           // IN: data buffer
    )
{
    return (memcmp(&s_NV[startOffset], data, size) != 0);
}

//***_plat__NvMemoryWrite()
// This function is used to update NV memory. The "write" is to a memory copy of
// NV. At the end of the current command, any changes are written to
// the actual NV memory.
// NOTE: A useful optimization would be for this code to compare the current
// contents of NV with the local copy and note the blocks that have changed. Then
// only write those blocks when _plat__NvCommit() is called.
LIB_EXPORT int
_plat__NvMemoryWrite(
    unsigned int     startOffset,   // IN: write start
    unsigned int     size,          // IN: size of bytes to write
    void            *data           // OUT: data buffer
    )
{
    if(startOffset + size <= NV_MEMORY_SIZE)
    {
        memcpy(&s_NV[startOffset], data, size);     // Copy the data to the NV image
        return TRUE;
    }
    return FALSE;
}

//***_plat__NvMemoryClear()
// Function is used to set a range of NV memory bytes to an implementation-dependent
// value. The value represents the erase state of the memory.
LIB_EXPORT void
_plat__NvMemoryClear(
    unsigned int     start,         // IN: clear start
    unsigned int     size           // IN: number of bytes to clear
    )
{
    assert(start + size <= NV_MEMORY_SIZE);
    // In this implementation, assume that the erase value for NV is all 1s
    memset(&s_NV[start], 0xff, size);
}

//***_plat__NvMemoryMove()
// Function: Move a chunk of NV memory from source to destination
//      This function should ensure that if there overlap, the original data is
//      copied before it is written
LIB_EXPORT void
_plat__NvMemoryMove(
    unsigned int     sourceOffset,  // IN: source offset
    unsigned int     destOffset,    // IN: destination offset
    unsigned int     size           // IN: size of data being moved
    )
{
    assert(sourceOffset + size <= NV_MEMORY_SIZE);
    assert(destOffset + size <= NV_MEMORY_SIZE);
    memmove(&s_NV[destOffset], &s_NV[sourceOffset], size);      // Move data in RAM
    return;
}

//***_plat__NvCommit()
// This function writes the local copy of NV to NV for permanent store. It will write
// NV_MEMORY_SIZE bytes to NV. If a file is use, the entire file is written.
//  Return Type: int
//  0       NV write success
//  non-0   NV write fail
LIB_EXPORT int
_plat__NvCommit(
    void
    )
{
#if FILE_BACKED_NV
    return (NvFileCommit() ? 0 : 1);
#else
    return 0;
#endif
}

//***_plat__SetNvAvail()
// Set the current NV state to available.  This function is for testing purpose
// only.  It is not part of the platform NV logic
LIB_EXPORT void
_plat__SetNvAvail(
    void
    )
{
    s_NvIsAvailable = TRUE;
    return;
}

//***_plat__ClearNvAvail()
// Set the current NV state to unavailable.  This function is for testing purpose
// only.  It is not part of the platform NV logic
LIB_EXPORT void
_plat__ClearNvAvail(
    void
    )
{
    s_NvIsAvailable = FALSE;
    return;
}

//*** _plat__NVNeedsManufacture()
// This function is used by the simulator to determine when the TPM's NV state
// needs to be manufactured.
LIB_EXPORT int
_plat__NVNeedsManufacture(
    void
    )
{
#if FILE_BACKED_NV
    return s_NeedsManufacture;
#else
    return FALSE;
#endif
}
