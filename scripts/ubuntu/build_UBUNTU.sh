#!/bin/bash

# Определяем пути
PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/../.." && pwd )"
LIB_DIR="$PROJECT_ROOT/lib"
LIB_PATH="$LIB_DIR/libiec61850"
BUILD_DIR="$PROJECT_ROOT/build"

CC="gcc"
AR="ar"

echo "---------------------------------------------------------"
echo "Выбрана сборка под Ubuntu (x86_64)"
echo "Корень проекта: $PROJECT_ROOT"
echo "---------------------------------------------------------"

# 1. Очистка старой сборки
rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"
if [ -d "$LIB_PATH" ]; then
    cd "$LIB_PATH" && make clean >/dev/null 2>&1 && cd "$PROJECT_ROOT"
fi

# 2. Пути инклудов (добавляем путь к заголовкам модулей)
INCLUDES_IEC="-I$LIB_PATH/src/iec61850/inc \
              -I$LIB_PATH/src/mms/inc \
              -I$LIB_PATH/src/common/inc \
              -I$LIB_PATH/src/logging \
              -I$LIB_PATH/hal/inc \
              -I$LIB_PATH/hal/api \
              -I$PROJECT_ROOT/src \
              -I$PROJECT_ROOT/src/models/include\
              -I$PROJECT_ROOT/src/models/$mod"   # <-- добавлено

# 3. Сборка libiec61850
echo "--- Сборка библиотеки libiec61850 (Native) ---"
cd "$LIB_PATH" && make CC="$CC" &>/dev/null && cd "$PROJECT_ROOT"

# 4. Сборка модулей портов (все .c файлы)
echo "--- Сборка модулей портов (Native) ---"
# Список файлов модулей (предполагается, что они лежат в $PROJECT_ROOT/src/)
MODULES="common.c status.c mac.c capabilities.c speed.c autoneg.c flow_control.c mtu.c"
for mod in $MODULES; do
    $CC -c "$PROJECT_ROOT/src/$mod" -o "$BUILD_DIR/${mod%.c}.o" $INCLUDES_IEC -std=c99
done

# Собираем архив
$AR rcs "$LIB_DIR/libmyports.a" $BUILD_DIR/*.o
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