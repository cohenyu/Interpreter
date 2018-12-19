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
        TCPServer.cpp
        TCPServer.h
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
        UnaryExpression.h Var.cpp Var.h OpenServerCommand.cpp OpenServerCommand.h ConnectCommand.cpp ConnectCommand.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h DataReaderServer.cpp DataReaderServer.h TCPClient.cpp TCPClient.h SymbolTableManager.cpp SymbolTableManager.h AssignmentCommand.cpp AssignmentCommand.h ConditionParser.cpp ConditionParser.h IfCommand.cpp IfCommand.h WhileCommand.cpp WhileCommand.h)
