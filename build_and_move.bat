@echo off
setlocal enabledelayedexpansion

if not exist "exe_folder" mkdir "exe_folder"

for /r %%f in (*.cpp) do (
    @REM echo Compiling %%~nxf...
    
    set "relPath=%%~dpf"
    set "relPath=!relPath:%CD%=!"
    
    @REM g++ "%%f" -o "%%~dpnf.exe"

    if not "!relPath!"=="" (
            if not exist "exe_folder!relPath!" mkdir "exe_folder!relPath!"
        )
        
    move "%%~dpnf.exe" "exe_folder!relPath!"
    
    echo.
)

echo All done!
pause