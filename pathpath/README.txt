// Copyright 2012 FD Imaging
// All rights reserved.
//
// THIS CODE AND EXECUTABLE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
// KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.


Introduction
============
pathpath.exe is a simple tool, which simplifies reading and setting the %PATH% environment variable under Microsoft Windows operating systems.


Usage
============
Read the %PATH% environment variable from the registry and save it as newline separated entries in "path.txt":
C:\>pathpath.exe read

Write the %PATH% environment variable to the registry from "path.txt":
This requires Admin rights.
C:\>pathpath.exe write

You can use the program via batch script as in the read.bat write.bat examples.


Files
============
src          - contains the source code of pathpath.exe
pathpath.exe - The program
read.bat     - Sample batch file to read the %PATH% environment variable 
write.bat    - Sample batch file to write the %PATH% environment variable
README.txt   - This file


Build
============
You can compile this program on your own.
To build this program, you need Visual Studio, qmake and the BOOST C++ library.


