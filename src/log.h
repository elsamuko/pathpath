#pragma once

#include <string>

#define LOG(A) writeLog( __LINE__, __FUNCTION__, A )
#define LOGEND(A) writeLog( __LINE__, __FUNCTION__, A, false )
#define LOGBEGIN(A) writeLog( __LINE__, __FUNCTION__, A, false )

unsigned long getTime();
void writeLog( int line, const char* function, std::string content, bool trim = true );


