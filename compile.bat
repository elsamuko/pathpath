@setlocal enableextensions enabledelayedexpansion
@echo off

call "%VS110COMNTOOLS%..\..\VC\bin\vcvars32.bat" > NUL

qmake pathpath.pro -r -spec win32-msvc2012
jom clean
jom

PAUSE

@echo ON
