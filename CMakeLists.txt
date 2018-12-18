cmake_minimum_required(VERSION 3.13)
project(YuvalandMiriel)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(YuvalandMiriel
        BinaryExpression.cpp
        BinaryExpression.h
        Div.cpp
        Div.h
        Expression.cpp
        Expression.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Minus.cpp
        Minus.h
        Mul.cpp
        Mul.h
        Neg.cpp
        Neg.h
        Number.cpp
        Number.h
        Parser.cpp
        Parser.h
        Plus.cpp
        Plus.h
        ShuntingYard.cpp
        ShuntingYard.h
        UnaryExpression.cpp
        UnaryExpression.h)
