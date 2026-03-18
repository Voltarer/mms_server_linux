echo "MMS_SERVER"
echo "Выберите ОС,в которой вы сейчас работаете:"
echo "1) Ubuntu"
echo "2) Windows"
read -p "Ваш выбор: " CHOISE

echo "Подготовим нужные файлы..."
./scripts/setup.sh

if [ "$CHOISE" == "1" ]; then
    echo "Компиляция с Ubuntu..."
    ./scripts/ubuntu/choice.sh
elif ["$CHOISE" == "2" ]; then
    echo "Компиляция с Windows"
    # ./scripts/win/build_win.bat
else
    echo "error"
fi
