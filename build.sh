#!/bin/bash

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WORKSPACE_ROOT="$(cd "$PROJECT_ROOT/.." && pwd)"

CC_MIPS="$WORKSPACE_ROOT/toolchain/mips-buildroot-linux-uclibc_sdk-buildroot/bin/mips-linux-gcc"

echo "---------------------------------------------------------"
echo "Собрать сервер для:"
echo "1) Ubuntu (x86_64) -> build/mms_server_ubuntu"
echo "2) MIPS (Realtek) -> build/mms_server_mips"
read -p "Ваш выбор: " BUILD_TARGET

# Общие инклуды для обеих сборок
INCLUDES_BASE="-I$PROJECT_ROOT/lib/libiec61850/src/iec61850/inc \
               -I$PROJECT_ROOT/lib/libiec61850/src/mms/inc \
               -I$PROJECT_ROOT/lib/libiec61850/src/common/inc \
               -I$PROJECT_ROOT/lib/libiec61850/src/logging \
               -I$PROJECT_ROOT/lib/libiec61850/hal/inc \
               -I$PROJECT_ROOT/lib/libiec61850/hal/api \
               -I$PROJECT_ROOT/src"

LIB_BASE="$PROJECT_ROOT/lib/libiec61850/build/libiec61850.a"

if [ "$BUILD_TARGET" == "1" ]; then
    echo "Компиляция под Ubuntu..."
    gcc $INCLUDES_BASE $PROJECT_ROOT/src/main.c $PROJECT_ROOT/src/static_model.c \
        -o "$PROJECT_ROOT/build/mms_server_ubuntu" $LIB_BASE -lpthread -lrt -lm

    if [ $? -eq 0 ]; then
        echo "✅ УСПЕХ: Файл готов в build/mms_server_ubuntu"
        echo "Можете запустить его командой: sudo ./build/mms_server_ubuntu"
    else
        echo "❌ ОШИБКА компиляции"
    fi

elif [ "$BUILD_TARGET" == "2" ]; then
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
else
    echo "❌ Неверный выбор."
fi
