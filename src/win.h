// Copyright 2012 FD Imaging
// All rights reserved.
//
// THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.

#pragma once

#include <vector>
#include <string>

std::string toString( const std::wstring& wide );
std::wstring fromString( const std::string& multi );

std::vector< std::string > readPath();
void writePath( const std::vector< std::string >& paths );
