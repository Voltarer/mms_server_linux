#!/bin/bash
PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )/.." && pwd )"
cd "$PROJECT_ROOT" || exit

LIB_DIR="lib"
GEN_JAR="$LIB_DIR/libiec61850/tools/model_generator/genmodel.jar"
ICD_FILE="src/model.icd"

if [ -f "$GEN_JAR" ]; then
    echo "Генерация статической модели из $ICD_FILE..."
    # Запускаем из корня, чтобы пути src/model.icd были верны
    java -jar "$GEN_JAR" "$ICD_FILE"
    
    # Перемещаем результат в папку с исходниками
    mv static_model.c src/
    mv static_model.h src/
    echo "✅ Готово! Файлы в src/"
else
    echo "❌ ОШИБКА: jar не найден по пути: $GEN_JAR"
    echo "Текущая директория: $(pwd)"
fi