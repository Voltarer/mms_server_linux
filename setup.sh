#!/bin/bash

PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
WORKSPACE_ROOT="$( cd "$PROJECT_ROOT/.." && pwd )"
LIB_PATH="$PROJECT_ROOT/lib/libiec61850"
CC_MIPS="$WORKSPACE_ROOT/toolchain/bin/mips-linux-gcc"

echo "=== Запуск настройки окружения ==="

echo "Очистка старых сборок библиотеки..."
if [ -d "$LIB_PATH" ]; then
    cd "$LIB_PATH"
    make clean > /dev/null 2>&1
    cd "$PROJECT_ROOT"
fi

echo "Сборка libiec61850 под архитектуру MIPS..."
if [ -f "$CC_MIPS" ]; then
    cd "$LIB_PATH"
    # Передаем наш кросс-компилятор в make
    make CC="$CC_MIPS"
    if [ $? -eq 0 ]; then
        echo "✅ Библиотека успешно собрана под MIPS."
    else
        echo "❌ ОШИБКА сборки библиотеки."
        exit 1
    fi
    cd "$PROJECT_ROOT"
else
    echo "⚠️ Кросс-компилятор не найден..."

fi

# 3. Создание папки build, если её нет
if [ ! -d "build" ]; then
    mkdir build
    echo "Папка build создана."
fi

echo "---------------------------------------------------------"
echo "ПОДГОТОВКА ЗАВЕРШЕНА!"
echo "---------------------------------------------------------"
echo "Инструкция для сборки под MIPS:"
echo "1. Распакуйте компилятор в: $WORKSPACE_ROOT/toolchain/"
echo "2. Положите папку SDK (папку include и др.) в: $PROJECT_ROOT/lib/"
echo "3. Запустите ./build.sh"
echo "---------------------------------------------------------"