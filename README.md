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

Основные части интерпретатора:

1. Лексический анализатор (Lexer) -> возврыщает набор токенов
2. Синтаксический анализатор (Parser)
3. Интерпретатор (Interpreter)


## Структура проекта

 ```bash
Micro-C/
│
├── include/
|   ├── token.h
│   ├── lexer.h
│   ├── parser.h
│   ├── interpreter.h
│   ├── abstract_syntax_tree.h
│   ├── input_processor.h
│
├── src/
|   ├── token.cpp
│   ├── lexer.cpp
│   ├── parser.cpp
│   ├── interpreter.cpp
│   ├── abstract_syntax_tree.cpp
│   ├── input_processor.cpp
│   └── main.cpp
│
└── CMakeLists.txt

'''
