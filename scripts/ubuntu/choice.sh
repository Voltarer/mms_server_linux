#!/bin/bash
echo "Выберите ОС, которую хотите собрать:"
echo "1) Ubuntu"
echo "2) Windows"
echo "3) MIPS"
read -p "Ваш выбор: " CHOISE

if [ "$CHOISE" == "1" ]; then
    echo "Компиляция под Ubuntu..."
    ./scripts/ubuntu/build_UBUNTU.sh
elif [ "$CHOISE" == "2" ]; then 
    echo "Компиляция под Windows"
    ./scripts/ubuntu/build_WIN.sh
elif [ "$CHOISE" == "3" ]; then   
    echo "Компиляция под MIPS"
    ./scripts/ubuntu/build_MIPS.sh
else
    echo "error"
fi