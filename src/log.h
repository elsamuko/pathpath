// Copyright 2012 FD Imaging
// All rights reserved.
//
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.

#pragma once

#include <string>

#define LOG(A) writeLog( __LINE__, __FUNCTION__, A )
#define LOGEND(A) writeLog( __LINE__, __FUNCTION__, A, false )
#define LOGBEGIN(A) writeLog( __LINE__, __FUNCTION__, A, false )

unsigned long getTime();
void writeLog( int line, const char* function, std::string content, bool trim = true );


