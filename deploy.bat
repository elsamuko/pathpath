@setlocal enableextensions enabledelayedexpansion
@echo off

:: remove old version
DEL %CD%\pathpath.zip


:: copy source code
IF NOT EXIST "%CD%\pathpath\src\" (
	MKDIR %CD%\pathpath\src\
)
XCOPY %CD%\src           %CD%\pathpath\src /E /Y


:: copy binary and sample scripts
COPY %CD%\bin\pathpath.exe %CD%\pathpath\pathpath.exe
COPY %CD%\bin\read.bat     %CD%\pathpath\read.bat
COPY %CD%\bin\write.bat    %CD%\pathpath\write.bat


:: zip package
CScript zip.vbs  %CD%\pathpath  %CD%\pathpath.zip


@echo ON
