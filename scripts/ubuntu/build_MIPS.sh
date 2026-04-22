#!/bin/bash

PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." && pwd )"
WORKSPACE_ROOT="$(cd "$PROJECT_ROOT/.." && pwd)"

LIB_DIR="$PROJECT_ROOT/lib"
LIB_PATH="$LIB_DIR/libiec61850"
LIB_TOOLCHAIN="$WORKSPACE_ROOT/toolchain"
BUILD_DIR="$PROJECT_ROOT/build"

CC_MIPS="$LIB_TOOLCHAIN/mips-buildroot-linux-uclibc_sdk-buildroot/bin/mips-linux-gcc"
AR_MIPS="$LIB_TOOLCHAIN/mips-buildroot-linux-uclibc_sdk-buildroot/bin/mips-linux-ar"

echo "---------------------------------------------------------"
echo "Выбрана сборка под MIPS"
echo "Корень проекта: $PROJECT_ROOT"

echo "---------------------------------------------------------"
echo "Выбрана сборка под MIPS"
######################################################################
# Очистка старой сборки при смене платформы
if [ -d "$LIB_PATH" ]; then
    cd "$LIB_PATH" && make clean >/dev/null 2>&1 && cd "$PROJECT_ROOT"
fi
######################################################################


# Настройка путей для libiec61850
INCLUDES_IEC="-I$LIB_PATH/src/iec61850/inc \
              -I$LIB_PATH/src/mms/inc \
              -I$LIB_PATH/src/common/inc \
              -I$LIB_PATH/src/logging \
              -I$LIB_PATH/hal/inc \
              -I$LIB_PATH/hal/api \
              -I$PROJECT_ROOT/src"

mkdir -p "$BUILD_DIR"

echo "--- Сборка библиотеки libiec61850 под MIPS ---"
cd "$LIB_PATH" && make CC="$CC_MIPS" &>/dev/null && cd "$PROJECT_ROOT"

echo "--- Сборка библиотеки портов (Netlink) ---"
$CC_MIPS -c "$PROJECT_ROOT/src/ports_logic.c" \
    -o "$BUILD_DIR/ports_logic.o" \
    $INCLUDES_IEC -std=c99 -DTARGET_MIPS

$AR_MIPS rcs "$LIB_DIR/libmyports.a" "$BUILD_DIR/ports_logic.o"
echo "✅ Библиотека libmyports.a готова."

echo "--- Финальная сборка mms_server (Static) ---"
$CC_MIPS -static \
    -o "$BUILD_DIR/mms_server" \
    "$PROJECT_ROOT/src/main.c" \
    "$PROJECT_ROOT/src/static_model.c" \
    $INCLUDES_IEC \
    -L"$LIB_DIR" -lmyports \
    "$LIB_PATH/build/libiec61850.a" \
    -std=c99 -DTARGET_MIPS -lpthread

if [ $? -eq 0 ]; then
    echo "🚀 УСПЕХ: Файл готов в build/mms_server"
    file "$BUILD_DIR/mms_server"
else
    echo "❌ ОШИБКА компиляции"
fi