cmake_minimum_required(VERSION 3.10)

project(MicroC)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(MicroC
    src/main.cpp
    src/input_processor.cpp
    src/abstract_syntax_tree.cpp
    src/token.cpp
    src/lexer.cpp
    src/parser.cpp
    src/interpreter.cpp
)
