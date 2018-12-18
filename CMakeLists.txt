cmake_minimum_required(VERSION 3.12)
project(project1_MY)

set(CMAKE_CXX_STANDARD 14)

add_executable(project1_MY main.cpp Expression.h Number.cpp Number.h BinaryExpression.cpp BinaryExpression.h Div.cpp Div.h Plus.cpp Plus.h Mul.cpp Mul.h Minus.cpp Minus.h Expression.cpp UnaryExpression.cpp UnaryExpression.h ShuntingYard.cpp ShuntingYard.h Parser.cpp Parser.h Lexer.cpp Lexer.h Neg.cpp Neg.h Condition.h ComparisonCondition.cpp ComparisonCondition.h Equal.cpp Equal.h NotEqual.cpp NotEqual.h Less.cpp Less.h Greater.cpp Greater.h GreaterEqual.cpp GreaterEqual.h LessEqual.cpp LessEqual.h Command.h DefineVarCommand.cpp DefineVarCommand.h)