#!/bin/bash

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WORKSPACE_ROOT="$(cd "$PROJECT_ROOT/.." && pwd)"

CC_MIPS="$WORKSPACE_ROOT/toolchain/mips-buildroot-linux-uclibc_sdk-buildroot/bin/mips-linux-gcc"

echo "---------------------------------------------------------"
echo "Выбрана сборка под MIPS"
######################################################################
# Очистка старой сборки при смене платформы
if [ -d "$LIB_PATH" ]; then
    cd "$LIB_PATH" && make clean >/dev/null 2>&1 && cd "$PROJECT_ROOT"
fi
######################################################################
#cборка библиотеки под MIPS
echo "--- Настройка библиотеки для MIPS ---"
cd "$LIB_PATH" && make CC="$CC_MIPS" &>/dev/null && cd "$PROJECT_ROOT"
echo "✅ Библиотека собрана под MIPS."
# Загрузка и распаковка sdk.rar
echo "Проверка sdk..."
# 1. Проверяем, не распакован ли уже SDK
if [ ! -d "$LIB_DIR/sdk" ]; then
    cd "$LIB_DIR"

    # 2. Проверяем, нет ли уже скачанного архива sdk.rar
    if [ ! -f "sdk.rar" ]; then
        echo "sdk.rar не найден. Загрузка..."
        wget https://github.com/Voltarer/mms_server_linux/releases/download/2.0/sdk.rar &>/dev/null
        if [ $? -ne 0 ]; then
            echo "❌ ОШИБКА загрузки файла sdk.rar."
            exit 1
        fi
        echo "✅ Файл sdk.rar успешно загружен."
    else
        echo "📦 Архив sdk.rar уже на месте, загрузка не требуется."
    fi

    # 3. Распаковка
    echo "Начинается распаковка файла sdk.rar..."
    if command -v unrar &>/dev/null; then
        unrar x -y sdk.rar &>/dev/null
    elif command -v 7z &>/dev/null; then
        7z x -y sdk.rar &>/dev/null
    else
        echo "❌ ОШИБКА: Не найден unrar или 7z. Установи: sudo apt install unrar"
        exit 1
    fi

    if [ $? -eq 0 ]; then
        echo "✅ Файл sdk успешно распакован."
        rm -f sdk.rar
    else
        echo "❌ ОШИБКА распаковки файла sdk."
        exit 1
    fi
    cd "$PROJECT_ROOT"
else
    echo "✅ SDK уже распакован в папку lib/sdk."
fi
######################################################################
# Загрузка компилятора
echo "Проверка компилятора..."
if [ ! -d "$LIB_TOOLCHAIN/mips-buildroot-linux-uclibc_sdk-buildroot" ]; then
    cd "$LIB_TOOLCHAIN"
    echo "Загрузка компилятора..."
    wget https://github.com/Voltarer/mms_server_linux/releases/download/2.0/mips-buildroot-linux-uclibc_sdk-buildroot.tar.xz &>/dev/null
    if [ $? -eq 0 ]; then
        echo "✅ Файл компилятора успешно загружен."
        echo "Начинается распаковка компилятора..."
        tar -xvf mips-buildroot-linux-uclibc_sdk-buildroot.tar.xz &>/dev/null
        if [ $? -eq 0 ]; then
            echo "✅ Компилятор распакован."
            rm -f mips-buildroot-linux-uclibc_sdk-buildroot.tar.xz
        else
            echo "❌ ОШИБКА распаковки компилятора."
            exit 1
        fi
    else
        echo "❌ ОШИБКА загрузки компилятора."
        exit 1
    fi
    cd "$PROJECT_ROOT"
else
    echo "✅ Компилятор уже присутствует."
fi
######################################################################
# Загрузка библиотек .a
echo "Проверка библиотек realtek..."
LIBS_MISSING=0
cd "$LIB_DIR/realtek"
for lib in librtcore.a librtk.a librtnic.a librtusr.a; do
    if [ ! -f "$lib" ]; then
        echo "Загрузка $lib..."
        wget "https://github.com/Voltarer/mms_server_linux/releases/download/2.0/$lib" &>/dev/null
        if [ $? -ne 0 ]; then
            echo "❌ ОШИБКА загрузки $lib."
            LIBS_MISSING=1
        fi
    fi
done
if [ $LIBS_MISSING -eq 1 ]; then
    echo "❌ Не удалось загрузить все библиотеки."
    exit 1
else
    echo "✅ Все библиотеки realtek присутствуют."
fi
cd "$PROJECT_ROOT"
######################################################################
# Общие инклуды для обеих сборок
INCLUDES_BASE="-I$PROJECT_ROOT/lib/libiec61850/src/iec61850/inc \
               -I$PROJECT_ROOT/lib/libiec61850/src/mms/inc \
               -I$PROJECT_ROOT/lib/libiec61850/src/common/inc \
               -I$PROJECT_ROOT/lib/libiec61850/src/logging \
               -I$PROJECT_ROOT/lib/libiec61850/hal/inc \
               -I$PROJECT_ROOT/lib/libiec61850/hal/api \
               -I$PROJECT_ROOT/src"

LIB_BASE="$PROJECT_ROOT/lib/libiec61850/build/libiec61850.a"

echo "Кросс-компиляция под MIPS..."
INCLUDES_MIPS="$INCLUDES_BASE \
                -I$PROJECT_ROOT/lib/sdk/include \
                -I$PROJECT_ROOT/lib/sdk/system/include"

LIBS_MIPS="$LIB_BASE \
            $PROJECT_ROOT/lib/realtek/librtk.a \
            $PROJECT_ROOT/lib/realtek/librtnic.a \
            $PROJECT_ROOT/lib/realtek/librtcore.a \
            $PROJECT_ROOT/lib/realtek/librtusr.a"

LDFLAGS="-Wl,-dynamic-linker,/usr/local/lib/ld-uClibc.so.0"

$CC_MIPS -DTARGET_MIPS $INCLUDES_MIPS $PROJECT_ROOT/src/main.c $PROJECT_ROOT/src/static_model.c \
    -o "$PROJECT_ROOT/build/mms_server_mips" $LIBS_MIPS -lpthread -lrt -lm $LDFLAGS

if [ $? -eq 0 ]; then
    echo "✅ УСПЕХ: Файл готов в build/mms_server_mips"
else
    echo "❌ ОШИБКА компиляции"
fi
