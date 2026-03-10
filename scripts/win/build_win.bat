@echo off
set PROJECT_DIR=%CD%
set LIB_DIR=%PROJECT_DIR%\lib\libiec61850
set BUILD_DIR=%LIB_DIR%\build_win\src

echo --- Building an MMS server for Windows ---

:: Проверка наличия библиотеки .a
if not exist "%BUILD_DIR%\libiec61850.a" (
    echo ERROR: %BUILD_DIR%\libiec61850.a file was not found.
    echo First, build the library via cmake and mingw32-make.
    pause
    exit /b
)

:: Пути к HAL файлам
set MEMORY_C=%LIB_DIR%\hal\memory\lib_memory.c
set TIME_C=%LIB_DIR%\hal\time\win32\time.c
set THREAD_C=%LIB_DIR%\hal\thread\win32\thread_win32.c
set SOCKET_C=%LIB_DIR%\hal\socket\win32\socket_win32.c
set FILESYSTEM_C=%LIB_DIR%\hal\filesystem\win32\file_provider_win32.c

:: Компиляция (все флаги в одну строку для надежности)
gcc -D_WIN32_WINNT=0x0600 -DWIN32_LEAN_AND_MEAN -I"%LIB_DIR%\src\iec61850\inc" -I"%LIB_DIR%\src\mms\inc" -I"%LIB_DIR%\src\common\inc" -I"%LIB_DIR%\hal\api" -I"%LIB_DIR%\hal\inc" -I"%LIB_DIR%\src\logging\api" -I"%LIB_DIR%\src\logging" -I"%LIB_DIR%\src\logging\inc" -I"%PROJECT_DIR%\src" "src\main.c" "src\static_model.c" "%MEMORY_C%" "%TIME_C%" "%THREAD_C%" "%SOCKET_C%" "%FILESYSTEM_C%" -o mms_server.exe "%BUILD_DIR%\libiec61850.a" -lws2_32 -lmswsock -lpthread -static

if %ERRORLEVEL% EQU 0 (
    echo --- SUCCESS: mms_server.exe Ready ---
) else (
    echo --- BUILD Error ---
)