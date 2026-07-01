#!/bin/bash

PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." && pwd )"
WORKSPACE_ROOT="$(cd "$PROJECT_ROOT/.." && pwd)"

LIB_DIR="$PROJECT_ROOT/lib"
LIB_PATH="$LIB_DIR/libiec61850"
LIB_TOOLCHAIN="$WORKSPACE_ROOT/toolchain"
BUILD_DIR="$PROJECT_ROOT/build"
OBJ_DIR="$BUILD_DIR/obj"   # папка для объектных файлов

CC_MIPS="$LIB_TOOLCHAIN/mips-buildroot-linux-uclibc_sdk-buildroot/bin/mips-linux-gcc"
AR_MIPS="$LIB_TOOLCHAIN/mips-buildroot-linux-uclibc_sdk-buildroot/bin/mips-linux-ar"

echo "---------------------------------------------------------"
echo "Выбрана сборка под MIPS"
echo "Корень проекта: $PROJECT_ROOT"

# Очистка старой сборки
if [ -d "$LIB_PATH" ]; then
    cd "$LIB_PATH" && make clean >/dev/null 2>&1 && cd "$PROJECT_ROOT"
fi

# Пути инклудов (добавлен путь к заголовкам модулей)
INCLUDES_IEC="-I$LIB_PATH/src/iec61850/inc \
              -I$LIB_PATH/src/mms/inc \
              -I$LIB_PATH/src/common/inc \
              -I$LIB_PATH/src/logging \
              -I$LIB_PATH/hal/inc \
              -I$LIB_PATH/hal/api \
              -I$PROJECT_ROOT/src \
              -I$PROJECT_ROOT/src/models/include"

mkdir -p "$BUILD_DIR"
mkdir -p "$OBJ_DIR"

echo "--- Сборка библиотеки libiec61850 под MIPS ---"
cd "$LIB_PATH" && make CC="$CC_MIPS" &>/dev/null && cd "$PROJECT_ROOT"

# Находим все .c файлы в src/ (рекурсивно), исключаем main.c, static_model.c и все *ports_logic*
MODULE_SRCS=$(find "$PROJECT_ROOT/src" -name "*.c" \
              ! -name "main.c" ! -name "static_model.c" \
              ! -name "*ports_logic*")

if [ -z "$MODULE_SRCS" ]; then
    echo "⚠️ Не найдены файлы модулей! Проверьте пути."
    exit 1
fi

echo "--- Сборка модулей портов (MIPS) ---"
for src in $MODULE_SRCS; do
    obj="$OBJ_DIR/$(basename ${src%.c}).o"
    echo "Компиляция: $src -> $obj"
    $CC_MIPS -c "$src" -o "$obj" $INCLUDES_IEC -std=c99 -DTARGET_MIPS
    if [ $? -ne 0 ]; then
        echo "❌ Ошибка компиляции $src"
        exit 1
    fi
done

# Собираем архив из объектных файлов
$AR_MIPS rcs "$LIB_DIR/libmyports.a" $OBJ_DIR/*.o
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
    exit 1
fi