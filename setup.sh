#!/bin/bash
set -e

PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
WORKSPACE_ROOT="$( cd "$PROJECT_ROOT/.." && pwd )"

echo "--- 1. Создание структуры директорий ---"
mkdir -p "$WORKSPACE_ROOT/toolchain"
mkdir -p "$PROJECT_ROOT/build"

echo "--- 2. Загрузка libiec61850 ---"
if [ ! -d "$PROJECT_ROOT/lib/libiec61850" ]; then
    cd "$PROJECT_ROOT/lib"
    git clone --depth 1 https://github.com/mz-automation/libiec61850.git
    cd libiec61850 && make
else
    echo "Библиотека libiec61850 уже на месте."
fi

echo "---------------------------------------------------------"
echo "ПОДГОТОВКА ЗАВЕРШЕНА!"
echo "---------------------------------------------------------"
echo "Инструкция для сборки под MIPS:"
echo "1. Распакуйте компилятор в: $WORKSPACE_ROOT/toolchain/"
echo "2. Положите папку SDK (папку include и др.) в: $PROJECT_ROOT/lib/"
echo "3. Запустите ./build.sh"
echo "---------------------------------------------------------"