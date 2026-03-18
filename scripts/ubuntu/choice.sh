#!/bin/bash
echo "MMS_SERVER"
echo "Выберите ОС, которую хотите собрать:"
echo "1) Ubuntu"
echo "2) Windows"
echo "3) MIPS"
read -p "Ваш выбор: " CHOISE

if [ "$CHOISE" == "1" ]; then
    echo "Компиляция под Ubuntu..."
    ./scripts/ubuntu/build_UBUNTU.sh
elif [ "$CHOISE" == "2" ]; then    # Добавлен пробел после [
    echo "Компиляция под Windows"
    ./scripts/ubuntu/build_WIN.sh
elif [ "$CHOISE" == "3" ]; then    # Добавлен пробел после [
    echo "Компиляция под MIPS"
    ./scripts/ubuntu/build_MIPS.sh
else
    echo "error"
fi