# Micro-C Interpreter

## Реализовать минимальный функционал:

1. **Основные типы данных:**
   - Только `int`

2. **Операторы:**
   - Арифметические: `+`, `-`
   - Сравнение: `<=` (необходим для выполнения условий цикла)
   - Присваивание: `=`

3. **Управляющие конструкции:**
   - Только цикл `for`

4. **Функции:**
   - `main`

5. **Ввод/вывод:**
   - `printf`
     - Базовый синтаксис должен поддерживать такие варианты:
       ```c
       printf("Hello, World!\n");
       printf("Value of i: %d\n", i);
       ```

6. **Препроцессор:**
   - `#include`

7. **Ошибки и исключения:**
   - Простейшие ошибки компиляции, такие как синтаксические ошибки.

8. **Пример программы:**
   ```c
   #include <stdio.h>
   void main()
   {
       int i;
       for (i = 0; i < 10; i = i + 1)
       {
           printf("Value of i: %d\n", i);
       }
   
       return 0;
   }


## Реализация

Base steps:
1. Лексический анализатор (Lexer)
2. Синтаксический анализатор (Parser)
3. Интерпретатор (Interpreter)


## Структура проекта

 ```bash
Micro-C/
│
├── include/
│   ├── lexer.h
│   ├── parser.h
│   ├── interpreter.h
│   ├── ast.h
│
├── src/
│   ├── lexer.cpp
│   ├── parser.cpp
│   ├── interpreter.cpp
│   ├── ast.cpp
│   └── main.cpp
│
└── CMakeLists.txt (или Makefile)
<<<<<<< HEAD
'''
=======
'''

## Сборка

### (Win11, MinGW, CMake)

**В Терминале**

1. Выполните команду для создания отдельной директории для сборки:
   ```bash
   mkdir build
   cd build
'''

2. Выполните CMake для генерации файлов сборки:
'''bash
cmake .. -G "MinGW Makefiles"
'''

3. Скомпилируйте проект:
'''bash
cmake --build .
'''

4. Запуск программы:
'''c
MicroC.exe
'''

**В Visual Studio Code**
1. Run CMake
- нажмите F1, введите "CMake: Configure" и выберите опцию для запуска CMake.

2. Build
- собрать проект, нажав F7 или выбрав команду CMake: Build через F1.

3. Execute
- Запустить Терминал - нажмите Ctrl + '
- Перейдите в папку build:
'''bash
cd build

- Запустите .exe файл:
'''bash
./MicroC.exe
'''

**В Visual Studio Code - способ 2: Настройка задачи в (tasks.json)**

1. Создайте файл tasks.json:
   -В меню выберите Terminal -> Configure Tasks -> Create tasks.json file from template -> Others.

2. Добавьте задачу для запуска .exe файла:
'''bash
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Run MicroC",
            "type": "shell",
            "command": "./build/MicroC.exe",
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "presentation": {
                "echo": true,
                "reveal": "always",
                "focus": false,
                "panel": "shared"
            },
            "problemMatcher": []
        }
    ]
}
'''

3. Запустите задачу:
   -Нажмите F1, введите Tasks: Run Task, выберите Run MicroC.
   -Или просто нажмите Ctrl + Shift + B, если эта задача назначена как isDefault.


**В Visual Studio Code - способ 3: Использование конфигурации запуска (launch.json)**
TODO
>>>>>>> 332c7ca6b025f001749ad087f345d62f4a9e77b9
