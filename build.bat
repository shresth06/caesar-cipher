@echo off

set SOURCE_DIR=.\src
set BIN_DIR=.\bin
set EXECUTABLE_NAME=encryptor

rem Create the "bin" folder if it doesn't exist
if not exist %BIN_DIR%\ mkdir %BIN_DIR%\

cd %SOURCE_DIR%
clang++ encryptor.cpp -o ..\%BIN_DIR%\%EXECUTABLE_NAME%
..\%BIN_DIR%\%EXECUTABLE_NAME%
