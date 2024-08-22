## Сборка
### (Win11, MinGW, CMake)

**В Терминале**

1. Выполните команду для создания отдельной директории для сборки:

'mkdir build'
'cd build'

2. Выполните CMake для генерации файлов сборки:

'cmake .. -G "MinGW Makefiles"'


3. Скомпилируйте проект:

'cmake --build .'


4. Запуск программы:

'MicroC.exe'


**В Visual Studio Code**
1. Run CMake
- нажмите F1, введите "CMake: Configure" и выберите опцию для запуска CMake.

2. Build
- собрать проект, нажав F7 или выбрав команду CMake: Build через F1.

3. Execute
- Запустить Терминал - нажмите Ctrl + '
- Перейдите в папку build: 'cd build'

- Запустите .exe файл: './MicroC.exe'

**В Visual Studio Code - способ 2: Настройка задачи в (tasks.json)**

1. Создайте файл tasks.json:
   -В меню выберите Terminal -> Configure Tasks -> Create tasks.json file from template -> Others.

2. Добавьте задачу для запуска .exe файла:

```json
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
```

3. Запустите задачу:
   -Нажмите F1, введите Tasks: Run Task, выберите Run MicroC.
   -Или просто нажмите Ctrl + Shift + B, если эта задача назначена как isDefault.


**В Visual Studio Code - способ 3: Использование конфигурации запуска (launch.json)**
TODO
