#!/bin/bash
PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/.." && pwd )"
WORKSPACE_ROOT="$(cd "$PROJECT_ROOT/.." && pwd)"
LIB_DIR="$PROJECT_ROOT/lib"
LIB_PATH="$PROJECT_ROOT/lib/libiec61850"
LIB_TOOLCHAIN="$WORKSPACE_ROOT/toolchain"
# Для сборки статичной модели
GEN_JAR="lib/libiec61850/tools/model_generator/genmodel.jar"
ICD_FILE="src/model.icd"

echo "=== Запуск настройки окружения ==="
######################################################################
# Очищаем старые файлы
echo "Очистка старых сборок библиотеки..."
if [ -d "$LIB_PATH" ]; then
    cd "$LIB_PATH"
    make clean >/dev/null 2>&1
    cd "$PROJECT_ROOT"
fi
######################################################################
# Создаем папки build, toolchain, lib, realtek
echo "Проверка структуры папок..."
if [ ! -d "build" ]; then
    mkdir build
    echo "✅ Папка build создана."
fi
if [ ! -d "lib" ]; then
    mkdir lib
    echo "✅ Папка lib создана."
fi
if [ ! -d "$LIB_DIR/realtek" ]; then
    mkdir -p "$LIB_DIR/realtek"
    echo "✅ Папка realtek создана."
fi
if [ ! -d "$LIB_TOOLCHAIN" ]; then
    mkdir -p "$LIB_TOOLCHAIN"
    echo "✅ Папка toolchain создана."
fi
######################################################################
# Загружаем библиотеку libiec61850
echo "Проверка библиотеки libiec61850..."

# Убеждаемся, что мы находимся в корне проекта перед созданием папки
cd "$PROJECT_ROOT"

if [ ! -d "$LIB_PATH" ]; then
    # Создаем целевую директорию, если её нет
    mkdir -p "$LIB_DIR" 
    cd "$LIB_DIR"
    
    echo "Начало загрузки в $(pwd)..."
    git clone https://github.com/mz-automation/libiec61850.git
    
    if [ $? -eq 0 ]; then
        echo "✅ Библиотека libiec61850 успешно загружена."
    else
        echo "❌ ОШИБКА загрузки библиотеки."
        exit 1
    fi
    # Возвращаемся в корень проекта
    cd "$PROJECT_ROOT"
else
    echo "✅ Библиотека libiec61850 уже присутствует по пути: $LIB_PATH"
fi
######################################################################
# Проверка наличия wget или curl
echo "Проверка наличия wget/curl..."
if ! command -v wget &>/dev/null && ! command -v curl &>/dev/null; then
    echo "❌ wget или curl не найдены. Установите один из них."
    exit 1
fi
echo "✅ wget/curl найдены."
######################################################################
rm -f "$PROJECT_ROOT/src/static_model.c"  # Удаляем старую версию static_model.c, если она существует

rm -f "$PROJECT_ROOT/src/static_model.h"  # Удаляем старую версию static_model.h, если она существует

# Сборка статичной модели
if [ -f "$GEN_JAR" ]; then
    echo "Генерация статической модели из $ICD_FILE..."
    java -jar "$GEN_JAR" "$ICD_FILE"
    if [ -f "$PROJECT_ROOT/static_model.c" ] && [ -f "$PROJECT_ROOT/static_model.h" ]; then
        mv "$PROJECT_ROOT/static_model.c" "$PROJECT_ROOT/src"
        mv "$PROJECT_ROOT/static_model.h" "$PROJECT_ROOT/src"
        echo "✅ Модель сгенерирована и перемещена в src/."
    else
        echo "❌ ОШИБКА: Файлы модели не сгенерировались."
        exit 1
    fi
else
    echo "❌ ОШИБКА: genmodel.jar не найден по пути $GEN_JAR"
    exit 1
fi

