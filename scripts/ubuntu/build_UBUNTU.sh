#!/bin/bash

# Определяем пути
PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." && pwd )"
LIB_DIR="$PROJECT_ROOT/lib"
LIB_PATH="$LIB_DIR/libiec61850"
BUILD_DIR="$PROJECT_ROOT/build"
OBJ_DIR="$BUILD_DIR/obj"   # Папка для объектных файлов (перенесено из MIPS)

CC="gcc"
AR="ar"

echo "---------------------------------------------------------"
echo "Выбрана сборка под Ubuntu (x86_64)"
echo "Корень проекта: $PROJECT_ROOT"
echo "---------------------------------------------------------"

# 1. Очистка старой сборки
if [ -d "$LIB_PATH" ]; then
    cd "$LIB_PATH" && make clean >/dev/null 2>&1 && cd "$PROJECT_ROOT"
fi

# Полностью удаляем директорию build со всем содержимым
rm -rf "$BUILD_DIR"
# Удаляем старую библиотеку модулей
rm -f "$LIB_DIR/libmyports.a"

# 2. Пути инклудов (исправлено: убран невалидный путь с переменной $mod)
INCLUDES_IEC="-I$LIB_PATH/src/iec61850/inc \
              -I$LIB_PATH/src/mms/inc \
              -I$LIB_PATH/src/common/inc \
              -I$LIB_PATH/src/logging \
              -I$LIB_PATH/hal/inc \
              -I$LIB_PATH/hal/api \
              -I$PROJECT_ROOT/src \
              -I$PROJECT_ROOT/src/models/include"

# Создаем чистые папки для новой сборки
mkdir -p "$BUILD_DIR"
mkdir -p "$OBJ_DIR"

# 3. Сборка libiec61850
echo "--- Сборка библиотеки libiec61850 (Native) ---"
cd "$LIB_PATH" && make CC="$CC" &>/dev/null && cd "$PROJECT_ROOT"

# 4. Динамический поиск файлов модулей (вместо захардкоженного списка)
MODULE_SRCS=$(find "$PROJECT_ROOT/src" -name "*.c" \
              ! -name "main.c" ! -name "static_model.c" \
              ! -name "*ports_logic*")

if [ -z "$MODULE_SRCS" ]; then
    echo "⚠️ Не найдены файлы модулей! Проверьте пути."
    exit 1
fi

echo "--- Сборка модулей портов (Native) ---"
for src in $MODULE_SRCS; do
    obj="$OBJ_DIR/$(basename ${src%.c}).o"
    echo "Компиляция: $src -> $obj"
    $CC -c "$src" -o "$obj" $INCLUDES_IEC -std=c99
    if [ $? -ne 0 ]; then
        echo "❌ Ошибка компиляции $src"
        exit 1
    fi
done

# Собираем архив из объектных файлов в изолированной папке obj
$AR rcs "$LIB_DIR/libmyports.a" $OBJ_DIR/*.o
echo "✅ Библиотека libmyports.a готова."

# 5. Финальная сборка сервера
echo "--- Финальная сборка mms_server ---"
$CC -o "$BUILD_DIR/mms_server" \
    "$PROJECT_ROOT/src/main.c" \
    "$PROJECT_ROOT/src/static_model.c" \
    $INCLUDES_IEC \
    -L"$LIB_DIR" -lmyports \
    "$LIB_PATH/build/libiec61850.a" \
    -std=c99 -lpthread

if [ $? -eq 0 ]; then
    echo "🚀 УСПЕХ: Файл готов в build/mms_server"
    file "$BUILD_DIR/mms_server"
else
    echo "❌ ОШИБКА компиляции"
    exit 1
fi