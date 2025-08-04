cmake_minimum_required(VERSION 3.28)
project(programming_language)

set(CMAKE_CXX_STANDARD 20)

add_executable(programming_language main.cpp
        Source/Lexer.cpp
        Header/Lexer.h
        Header/Token.h)
