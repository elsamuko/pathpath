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
CP %CD%\bin\pathpath.exe %CD%\pathpath\pathpath.exe
CP %CD%\bin\read.bat     %CD%\pathpath\read.bat
CP %CD%\bin\write.bat    %CD%\pathpath\write.bat


:: copy redistributables
IF "%PROCESSOR_ARCHITECTURE%" == "AMD64" (
	CP %SYSTEMROOT%\SysWOW64\msvcp100.dll %CD%\pathpath\msvcp100.dll
	CP %SYSTEMROOT%\SysWOW64\msvcr100.dll %CD%\pathpath\msvcr100.dll
) ELSE (
	CP %SYSTEMROOT%\System32\msvcp100.dll %CD%\pathpath\msvcp100.dll
	CP %SYSTEMROOT%\System32\msvcr100.dll %CD%\pathpath\msvcr100.dll
)


:: zip package
CScript zip.vbs  %CD%\pathpath  %CD%\pathpath.zip


@echo ON
