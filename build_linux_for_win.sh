#!/bin/bash

PROJECT_DIR="$HOME/Документы/MMS_SERVER_LUNIX/mms_server_linux"
LIB_DIR="$PROJECT_DIR/lib/libiec61850"
BUILD_DIR="$LIB_DIR/build_win/src"

echo "--- Кросс-компиляция сервера для Windows ---"

MEMORY_C="$LIB_DIR/hal/memory/lib_memory.c"
TIME_C="$LIB_DIR/hal/time/win32/time.c"
THREAD_C="$LIB_DIR/hal/thread/win32/thread_win32.c"
SOCKET_C="$LIB_DIR/hal/socket/win32/socket_win32.c"

FILESYSTEM_C="$LIB_DIR/hal/filesystem/win32/file_provider_win32.c"

x86_64-w64-mingw32-gcc \
    -D_WIN32_WINNT=0x0600 \
    -DWIN32_LEAN_AND_MEAN \
    -I"$LIB_DIR/src/iec61850/inc" \
    -I"$LIB_DIR/hal/api" \
    -I"$LIB_DIR/hal/inc" \
    -I"$LIB_DIR/src/mms/inc" \
    -I"$LIB_DIR/src/common/inc" \
    -I"$LIB_DIR/src/logging/api" \
    -I"$LIB_DIR/src/logging/" \
    -I"$PROJECT_DIR/src" \
    "$PROJECT_DIR/src/main.c" \
    "$PROJECT_DIR/src/static_model.c" \
    "$MEMORY_C" \
    "$TIME_C" \
    "$THREAD_C" \
    "$SOCKET_C" \
    "$FILESYSTEM_C" \
    -o mms_server.exe \
    "$BUILD_DIR/libiec61850.a" \
    -lws2_32 -lmswsock -lpthread -static

if [ $? -eq 0 ]; then
    echo "--- Успех! mms_server.exe готов ---"
else
    echo "--- Ошибка сборки ---"
fi
