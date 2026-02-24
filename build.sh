#!/bin/bash

PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
WORKSPACE_ROOT="$( cd "$PROJECT_ROOT/.." && pwd )"

CC="$WORKSPACE_ROOT/toolchain/bin/mips-linux-gcc"

# Проверки
if [ ! -f "$CC" ]; then
    echo "ОШИБКА: Компилятор не найден в ../toolchain/bin/"
    exit 1
fi

if [ ! -d "$PROJECT_ROOT/lib/sdk/include" ]; then
    echo "ОШИБКА: Папка sdk/include не найдена в lib/sdk/"
    exit 1
fi

# Инклуды (учитываем, что папка называется sdk)
INCLUDES="-I$PROJECT_ROOT/lib/libiec61850/src/iec61850/inc \
          -I$PROJECT_ROOT/lib/libiec61850/src/mms/inc \
          -I$PROJECT_ROOT/lib/libiec61850/src/common/inc \
          -I$PROJECT_ROOT/lib/libiec61850/src/hal/inc \
          -I$PROJECT_ROOT/lib/sdk/include \
          -I$PROJECT_ROOT/lib/sdk/system/include \
          -I$PROJECT_ROOT/src"

# Библиотеки (уже лежат в lib/realtek)
LIBS="$PROJECT_ROOT/lib/libiec61850/build/libiec61850.a \
      $PROJECT_ROOT/lib/realtek/librtk.a \
      $PROJECT_ROOT/lib/realtek/librtnic.a \
      $PROJECT_ROOT/lib/realtek/librtcore.a \
      $PROJECT_ROOT/lib/realtek/librtusr.a"

echo "Кросс-компиляция сервера..."
$CC $INCLUDES $PROJECT_ROOT/src/main.c $PROJECT_ROOT/src/static_model.c \
    -o "$PROJECT_ROOT/build/mms_server_mips" $LIBS -lpthread -lrt -lm

if [ $? -eq 0 ]; then
    echo "УСПЕХ: Файл готов в build/mms_server_mips"
else
    echo "ОШИБКА компиляции"
fi