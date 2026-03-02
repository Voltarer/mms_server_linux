#!/bin/bash
GEN_JAR="lib/libiec61850/tools/model_generator/genmodel.jar"
ICD_FILE="src/model.icd"

PROJECT_ROOT="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"

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