#!/bin/bash

# Останавливаем скрипт при любой ошибке
set -e

# Определяем путь к папке, где лежит сам скрипт
PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

echo "--- 1. Очистка старых данных в $PROJECT_ROOT ---"
rm -rf "$PROJECT_ROOT/lib/libiec61850"
rm -rf "$PROJECT_ROOT/build"
mkdir -p "$PROJECT_ROOT/lib"
mkdir -p "$PROJECT_ROOT/build"

echo "--- 2. Загрузка библиотеки ---"
cd "$PROJECT_ROOT/lib"
git clone --depth 1 https://github.com/mz-automation/libiec61850.git
cd libiec61850
rm -rf .git

echo "--- 3. Сборка статической библиотеки ---"
make

# Проверка файла
if [ -f build/libiec61850.a ]; then
    echo ">>> Библиотека готова."
else
    echo "Ошибка: библиотека не собралась!"
    exit 1
fi

echo "--- 4. Сборка основного сервера ---"
cd "$PROJECT_ROOT/build"
cmake ..
make

echo "------------------------------------------------"
echo "СБОРКА ЗАВЕРШЕНА УСПЕШНО!"
echo "------------------------------------------------"

# Универсальный переход в папку build для любого пользователя
cd "$PROJECT_ROOT/build"

# Запускаем новую оболочку в этой папке, чтобы пользователь там и остался
exec bash --rcfile <(echo "cd $PROJECT_ROOT/build; PS1='\[\e[32m\]mms-project-build:\w\$ \[\e[m\]'")