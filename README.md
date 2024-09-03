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


Лексический анализатор (Lexer)

Отбрасывание комментарием и пробельных символов
Отделение токенов друг от друга

           ________      Токен     _____________
Source     |       |-------------->| Syntax     |
Code   --> | Lexer |               | Analizator |---> К семантическому анализатору
           |_______|<--------------|___________ |
                   |   getNextToken |    
                   |                |
                   |     ___________|
                   |----| Табдица   |
                        |  Символов |  
                        |___________|   


Токен типы:
                             
1 Keywords:                 [int, return, if, while, for, void, char]  зарезервированные слова языка
2 Identifiers:              [main, varName, myFunction ]  задаются программистом 
3 Literals:    
  [
   Integer literals:        [10, 0, -5, 0xFF]
   Floating-point literals: [3.14, -0.001, 2.0e10]
   Character literals:      ['a', '\n']
   String literals:         ["Hello, World!", "C programming"]
  ]
4 Operators:
  [
   Arithmetic operators:    [+ -  *  /  %] 
   Assignment operators:    [=, +=, -=, *=, /=, %=]
   Logical operators:       [&& (логическое И), || (логическое ИЛИ), ! (логическое НЕ)]
   Comparison operators:    [==, !=, <, >, <=, >=.]
   Bitwise operators:       [&, |, ^, ~, <<, >>.]
   Unary operators:         [++ (инкремент), -- (декремент), & (адрес), * (разыменование указателя).]
  ]
5 Separators:
  [
   Comma:           [,] — разделяет элементы списка (например, параметры функции).
   Semicolon:       [;] — завершает выражение или оператор.
   Curly braces:    [{}], которые используются для определения блоков кода.
   Parentheses:     [()] — используются для группировки выражений и вызова функций.
   Square brackets: [[]] — используются для определения массивов и доступа к элементам массива.
  ]
6 Comments:
  [
   Single-line comments: [//]   начинаются с // и продолжаются до конца строки.
   Multi-line comments:  [/**/] заключаются между /* и */.
  ]
7 Preprocessor directives: 
  [
   [#include]         — включение заголовочных файлов.
   [#define]          — определение макросов.
   [#ifdef], [#endif] — условная компиляция.
  ]


  Оставим для простоты только типы токенов:


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
