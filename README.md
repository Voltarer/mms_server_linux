# MMS Server & Realtek SDK Integration

Минимальный проект MMS-сервера (IEC 61850) с интеграцией аппаратных
портов коммутатора Realtek.

------------------------------------------------------------------------

## Структура проекта

``` text
/workspace
  ├── toolchain/          # MIPS toolchain
  └── mms_server_linux/   # Проект
      ├── lib/
      │   ├── realtek/    # .a библиотеки
      ├── setup.sh
      ├── build.sh
      └── ...
```

------------------------------------------------------------------------

## Быстрый старт

### 1. Cборка проекта

``` bash
chmod +x setup.sh
./setup.sh
```

### 2. Подготовка кросс-компиляции

-   Поместите компилятор в `../toolchain/`
-   Переместите папку SDK в `lib/`, должно получиться `lib/sdk`

### 3. Сборка под MIPS

``` bash
chmod +x build.sh
./build.sh
```

Готовый бинарный файл:

    build/mms_server_mips
