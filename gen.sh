#!/bin/bash
GEN_JAR="lib/libiec61850/tools/model_generator/genmodel.jar"
ICD_FILE="src/model.icd"

if [ -f "$GEN_JAR" ]; then
    echo "Генерация статической модели из $ICD_FILE..."
    java -jar "$GEN_JAR" "$ICD_FILE"
    echo "Готово!"
else
    echo "ОШИБКА: genmodel.jar не найден по пути $GEN_JAR"
fi