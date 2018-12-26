cmake_minimum_required(VERSION 3.13)
project(YuvalandMiriel)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

find_package(Threads)

add_executable(YuvalandMiriel
        BinaryExpression.cpp
        BinaryExpression.h
        Command.h
        CommandExpression.cpp
        CommandExpression.h
        TCPServer.cpp
        TCPServer.h
        DefineVarCommand.cpp
        DefineVarCommand.h
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
        Number.cpp
        Number.h
        Parser.cpp
        Parser.h
        Plus.cpp
        Plus.h
        ShuntingYard.cpp
        ShuntingYard.h
        OpenServerCommand.cpp OpenServerCommand.h ConnectCommand.cpp ConnectCommand.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h DataReaderServer.cpp DataReaderServer.h TCPClient.cpp TCPClient.h SymbolTableManager.cpp SymbolTableManager.h AssignmentCommand.cpp AssignmentCommand.h ConditionParser.cpp ConditionParser.h IfCommand.cpp IfCommand.h WhileCommand.cpp WhileCommand.h SocketCommunication.cpp SocketCommunication.h EnterC.cpp EnterC.h ExitCommand.cpp ExitCommand.h)


target_link_libraries(YuvalandMiriel ${CMAKE_THREAD_LIBS_INIT})
