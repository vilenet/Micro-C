cmake_minimum_required(VERSION 3.10)

project(MicroC)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(MicroC
    src/main.cpp
    #src/lexer.cpp
    #src/parser.cpp
    #src/interpreter.cpp
    #src/ast.cpp
)
