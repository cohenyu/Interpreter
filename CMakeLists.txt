cmake_minimum_required(VERSION 3.13)
project(YuvalandMiriel)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(YuvalandMiriel
        BinaryExpression.cpp
        BinaryExpression.h
        Command.h
        CommandExpression.cpp
        CommandExpression.h
        ComparisonCondition.cpp
        ComparisonCondition.h
        Condition.h
        DataReaderServer.cpp
        DataReaderServer.h
        DefineVarCommand.cpp
        DefineVarCommand.h
        Div.cpp
        Div.h
        Equal.cpp
        Equal.h
        Expression.cpp
        Expression.h
        Greater.cpp
        Greater.h
        GreaterEqual.cpp
        GreaterEqual.h
        Less.cpp
        Less.h
        LessEqual.cpp
        LessEqual.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Minus.cpp
        Minus.h
        Mul.cpp
        Mul.h
        Neg.cpp
        Neg.h
        NotEqual.cpp
        NotEqual.h
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
