@setlocal enableextensions enabledelayedexpansion
@echo off

:: check for admin rights
NET SESSION >nul 2>&1
IF %ERRORLEVEL% EQU 0 (

	cd %~dp0
	pathpath.exe write
    PAUSE

) ELSE (
	echo.
	echo.
	echo ##########################################################
	echo ####### ERROR: ADMINISTRATOR PRIVILEGES REQUIRED #########
	echo ##########################################################
	echo.
	echo.
	PAUSE
	EXIT /B 1
)

@echo ON
