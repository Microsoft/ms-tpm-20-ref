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
#include <stdio.h>
#include <time.h>
#include "Platform.h"

#if CERTIFYX509_DEBUG

const char      *debugFileName = "DebugFile.txt";

//*** fileOpen()
// This exists to allow use of the 'safe' version of fopen() with a MS runtime.
static FILE *
fileOpen(
    const char      *fn,
    const char      *mode
)
{
    FILE        *f;
#   if defined _MSC_VER
    if(fopen_s(&f, fn, mode) != 0)
        f = NULL;
#   else
    f = fopen(fn, mode);
#   endif
    return f;
}

//*** DebugFileInit()
// This function initializes the file containing the debug data with the time of the
// file creation.
//  Return Type: int
//   0              success
//  != 0            error
int
DebugFileInit(
    void
)
{
    FILE            *f = NULL;
    time_t           t = time(NULL);
//
    // Get current date and time.
#   if defined _MSC_VER
    char                 timeString[100];
    ctime_s(timeString, (size_t)sizeof(timeString), &t);
#   else
    char                *timeString;
    timeString = ctime(&t);
#   endif
    // Try to open the debug file
    f = fileOpen(debugFileName, "w");
    if(f)
    {
        // Initialize the contents with the time.
        fprintf(f, "%s\n", timeString);
        fclose(f);
        return 0;
    }
    return -1;
}

//*** DebugDumpBuffer()
void
DebugDumpBuffer(
    int             size,
    unsigned char   *buf,
    const char      *identifier
)
{
    int              i;
//
    FILE *f = fileOpen(debugFileName, "a");
    if(!f)
        return;
    if(identifier)
        fprintf(f, "%s\n", identifier);
    if(buf)
    {
        for(i = 0; i < size; i++)
        {
            if(((i % 16) == 0) && (i))
                fprintf(f, "\n");
            fprintf(f, " %02X", buf[i]);
        }
        if((size % 16) != 0)
            fprintf(f, "\n");
    }
    fclose(f);
}

#endif // CERTIFYX509_DEBUG
