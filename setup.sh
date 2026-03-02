#!/bin/bash
PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
WORKSPACE_ROOT="$( cd "$PROJECT_ROOT/.." && pwd )"
LIB_DIR="$PROJECT_ROOT/lib"
LIB_PATH="$PROJECT_ROOT/lib/libiec61850"
LIB_TOOLCHAIN="$WORKSPACE_ROOT/toolchain"
CC_MIPS="$WORKSPACE_ROOT/toolchain/mips-buildroot-linux-uclibc_sdk-buildroot/bin/mips-linux-gcc"
# Для сборки статичной модели
GEN_JAR="lib/libiec61850/tools/model_generator/genmodel.jar"
ICD_FILE="src/model.icd"


echo "=== Запуск настройки окружения ==="
######################################################################  
#Очищаем старые файлы
echo "Очистка старых сборок библиотеки..."
if [ -d "$LIB_PATH" ]; then
    cd "$LIB_PATH"
    make clean > /dev/null 2>&1
    cd "$PROJECT_ROOT"
fi
######################################################################
#Создаем папки build, toolchain
if [ ! -d "build" ]; then
    echo "Идет создание build..."
    mkdir build
    echo "✅ Папка build создана."

    echo "Идет создание lib..."
    mkdir lib
    echo "✅ Папка lib создана."

    echo "Идет создание realtek..."
    cd "$LIB_DIR"
    mkdir realtek
    echo "✅ Папка realtek создана."

    echo "Идет создание toolchain..."
    cd "$WORKSPACE_ROOT"
    mkdir toolchain
    echo "✅ Папка toolchain создана."
    cd "$PROJECT_ROOT"
fi
######################################################################
#Загружаем библиотеку libiec61850
echo "Загрузка библиотеки libiec61850..."
if [ ! -d "$LIB_PATH/lib" ]; then
    cd "$LIB_DIR"
    echo "Начало загрузки..."
    git clone https://github.com/mz-automation/libiec61850.git &> /dev/null
    if [ $? -eq 0 ]; then
        echo "✅ Библиотека libiec61850 успешно загружена."
    else
        echo "❌ ОШИБКА загрузки библиотеки."
        exit 1
    fi
fi
######################################################################
# Проверка наличия wget или curl, загрузка sdk, компилятора, библиотек .a
echo "Проверка наличия wget..." 
if command -v wget &> /dev/null
then
    echo "wget уже установлен. Переходим к загрузке нужных файлов..."
    cd "$LIB_DIR"
    ######################################################################
    # Загрузка sdk.rar
    echo "Загрузка sdk.rar..."
    wget https://github.com/Voltarer/mms_server_linux/releases/download/2.0/sdk.rar &> /dev/null
    if [ $? -eq 0 ] &> /dev/null; then
        echo "✅ Файл sdk.rar успешно загружен."
    else
        echo "❌ ОШИБКА загрузки файла sdk.rar."
        exit 1
    fi
    ######################################################################
    # Распаковка sdk.rar
    echo "Начинается распаковка файла sdk.rar..."
    unrar x -y sdk.rar &> /dev/null
    if [ $? -eq 0 ]; then
        echo "✅ Файл sdk успешно распакован."
    else
        echo "❌ ОШИБКА распаковки файла sdk."
        exit 1
    fi
    ######################################################################
    # Загрузка компилятора
    echo "Загрузка компилятора..."
    cd "$LIB_TOOLCHAIN"
    wget https://github.com/Voltarer/mms_server_linux/releases/download/2.0/mips-buildroot-linux-uclibc_sdk-buildroot.tar.xz &> /dev/null
    if [ $? -eq 0 ] &> /dev/null; then
       echo "✅ Файл mips-buildroot-linux-uclibc_sdk-buildroot.tar.xz успешно загружен."
       echo "Начинается распаковка файла mips-buildroot-linux-uclibc_sdk-buildroot.tar.xz..."
       tar -xvf mips-buildroot-linux-uclibc_sdk-buildroot.tar.xz &> /dev/null
    else
       echo "❌ ОШИБКА загрузки файла mips-buildroot-linux-uclibc_sdk-buildroot.tar.xz"
       exit 1
    fi
    ######################################################################
    # Загрузка библиотек
    echo "Загрузка библиотек..."
    cd "$LIB_DIR/realtek"
    wget https://github.com/Voltarer/mms_server_linux/releases/download/2.0/librtcore.a &> /dev/null
    wget https://github.com/Voltarer/mms_server_linux/releases/download/2.0/librtk.a &> /dev/null
    wget https://github.com/Voltarer/mms_server_linux/releases/download/2.0/librtnic.a &> /dev/null
    wget https://github.com/Voltarer/mms_server_linux/releases/download/2.0/librtusr.a &> /dev/null
    if [ $? -eq 0 ] &> /dev/null; then
        echo "✅ Библиотеки успешно загружены."
    else
        echo "❌ ОШИБКА загрузки библиотек."
        exit 1
    fi
else
    echo "wget не найден. Проверяем наличие curl"
    if command -v curl &> /dev/null
    then
        echo "curl уже установлен."
    else
        echo "curl не найден."
        echo "Установите curl или wget."
        exit 1
    fi
fi
######################################################################
#Собираем библиотеку под MIPS
echo "Сборка libiec61850 под архитектуру MIPS..."
if [ -f "$CC_MIPS" ]; then
    cd "$LIB_PATH"
    make CC="$CC_MIPS" &> /dev/null
    if [ $? -eq 0 ]; then
        echo "✅ Библиотека успешно собрана под MIPS."
    else
        echo "❌ ОШИБКА сборки библиотеки."
        exit 1
    fi
    cd "$PROJECT_ROOT"
else
    echo "⚠️ Кросс-компилятор не найден..."
    exit 1
fi
######################################################################
# Сборка статичной модели
if [ -f "$GEN_JAR" ]; then
    echo "Генерация статической модели из $ICD_FILE..."
    java -jar "$GEN_JAR" "$ICD_FILE"
    mv "$PROJECT_ROOT/static_model.c" "$PROJECT_ROOT/src"
    mv "$PROJECT_ROOT/static_model.h" "$PROJECT_ROOT/src"
    echo "Готово!"
else
    echo "ОШИБКА: genmodel.jar не найден по пути $GEN_JAR"
fi
######################################################################
# Удаление лишних файлов
echo "Удаление лишних файлов..."
rm -rf $LIB_DIR/sdk.rar
rm -rf $LIB_TOOLCHAIN/mips-buildroot-linux-uclibc_sdk-buildroot.tar.xz
######################################################################
echo "---------------------------------------------------------"
echo "ПОДГОТОВКА ЗАВЕРШЕНА!"
echo "---------------------------------------------------------"
echo "Инструкция для сборки под MIPS:"
echo "Запустите ./build.sh"
echo "---------------------------------------------------------"