@echo off
setlocal

:: Check if pkg-config is available
where pkg-config >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo Error: pkg-config is not in your PATH. Make sure MSYS2 is properly installed and in your system PATH.
    echo Please run this script from MSYS2 MinGW 64-bit terminal.
    pause
    exit /b 1
)

:: Compile the program
echo Compiling Basic_Calc_gui.c...
gcc Basic_Calc_gui.c -o Basic_Calc_gui.exe `pkg-config --cflags --libs gtk+-3.0`

if %ERRORLEVEL% EQU 0 (
    echo.
    echo Build successful! Run Basic_Calc_gui.exe to start the application.
) else (
    echo.
    echo Build failed with error code %ERRORLEVEL%
)

pause
