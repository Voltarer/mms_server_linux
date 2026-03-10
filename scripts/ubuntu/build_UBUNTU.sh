#!/bin/bash

PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WORKSPACE_ROOT="$(cd "$PROJECT_ROOT/.." && pwd)"

echo "---------------------------------------------------------"
echo "Выбрана сборка под Ubuntu"
######################################################################
# Очистка старой сборки при смене платформы
if [ -d "$LIB_PATH" ]; then
    cd "$LIB_PATH" && make clean >/dev/null 2>&1 && cd "$PROJECT_ROOT"
fi
######################################################################
#cборка библиотеки под Ubuntu
echo "--- Настройка библиотеки для Ubuntu ---"
cd "$LIB_PATH" && make &>/dev/null && cd "$PROJECT_ROOT"
echo "✅ Библиотека собрана под Ubuntu."
# Общие инклуды для обеих сборок
INCLUDES_BASE="-I$PROJECT_ROOT/lib/libiec61850/src/iec61850/inc \
               -I$PROJECT_ROOT/lib/libiec61850/src/mms/inc \
               -I$PROJECT_ROOT/lib/libiec61850/src/common/inc \
               -I$PROJECT_ROOT/lib/libiec61850/src/logging \
               -I$PROJECT_ROOT/lib/libiec61850/hal/inc \
               -I$PROJECT_ROOT/lib/libiec61850/hal/api \
               -I$PROJECT_ROOT/src"

LIB_BASE="$PROJECT_ROOT/lib/libiec61850/build/libiec61850.a"

echo "Компиляция под Ubuntu..."
gcc $INCLUDES_BASE $PROJECT_ROOT/src/main.c $PROJECT_ROOT/src/static_model.c \
    -o "$PROJECT_ROOT/build/mms_server_ubuntu" $LIB_BASE -lpthread -lrt -lm

if [ $? -eq 0 ]; then
    echo "✅ УСПЕХ: Файл готов в build/mms_server_ubuntu"
    echo "Можете запустить его командой: sudo ./build/mms_server_ubuntu"
else
    echo "❌ ОШИБКА компиляции"
fi
