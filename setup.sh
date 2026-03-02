#!/bin/bash
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
WORKSPACE_ROOT="$(cd "$PROJECT_ROOT/.." && pwd)"
LIB_DIR="$PROJECT_ROOT/lib"
LIB_PATH="$PROJECT_ROOT/lib/libiec61850"
LIB_TOOLCHAIN="$WORKSPACE_ROOT/toolchain"
CC_MIPS="$WORKSPACE_ROOT/toolchain/mips-buildroot-linux-uclibc_sdk-buildroot/bin/mips-linux-gcc"
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
if [ ! -d "$LIB_PATH" ]; then
    cd "$LIB_DIR"
    echo "Начало загрузки..."
    git clone https://github.com/mz-automation/libiec61850.git &>/dev/null
    if [ $? -eq 0 ]; then
        echo "✅ Библиотека libiec61850 успешно загружена."
    else
        echo "❌ ОШИБКА загрузки библиотеки."
        exit 1
    fi
    cd "$PROJECT_ROOT"
else
    echo "✅ Библиотека libiec61850 уже присутствует."
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
# Загрузка и распаковка sdk.rar
echo "Проверка sdk..."
if [ ! -d "$LIB_DIR/sdk" ]; then
    cd "$LIB_DIR"
    echo "Загрузка sdk.rar..."
    wget https://github.com/Voltarer/mms_server_linux/releases/download/2.0/sdk.rar &>/dev/null

    if [ $? -eq 0 ]; then
        echo "✅ Файл sdk.rar успешно загружен."
        echo "Начинается распаковка файла sdk.rar..."
        unrar x -y sdk.rar &>/dev/null
        if [ $? -eq 0 ]; then
            echo "✅ Файл sdk успешно распакован."
            rm -f sdk.rar # Удаляем архив после распаковки
        else
            echo "❌ ОШИБКА распаковки файла sdk."
            exit 1
        fi
    else
        echo "❌ ОШИБКА загрузки файла sdk.rar."
        exit 1
    fi
    cd "$PROJECT_ROOT"
else
    echo "✅ SDK уже распакован."
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
# Собираем библиотеку под MIPS
echo "Сборка libiec61850 под архитектуру MIPS..."
if [ -f "$CC_MIPS" ]; then
    cd "$LIB_PATH"
    # Проверяем, собрана ли уже либа, чтобы не тратить время
    if [ ! -f "build/libiec61850.a" ]; then
        make CC="$CC_MIPS" &>/dev/null
        if [ $? -eq 0 ]; then
            echo "✅ Библиотека успешно собрана под MIPS."
        else
            echo "❌ ОШИБКА сборки библиотеки."
            exit 1
        fi
    else
        echo "✅ Библиотека libiec61850 уже собрана."
    fi
    cd "$PROJECT_ROOT"
else
    echo "❌ Кросс-компилятор не найден: $CC_MIPS"
    exit 1
fi
######################################################################
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
######################################################################
echo "---------------------------------------------------------"
echo "ПОДГОТОВКА ЗАВЕРШЕНА!"
echo "---------------------------------------------------------"
echo "Инструкция для сборки под MIPS:"
echo "Запустите ./build.sh"
echo "---------------------------------------------------------"
