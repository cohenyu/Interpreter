//
// Created by yuval on 16/12/18.
//

#ifndef PROJECT1_MY_SHUNTINGYARD_H
#define PROJECT1_MY_SHUNTINGYARD_H

#include <string>
#include "Expression.h"
#include <bits/stdc++.h>
#include "SymbolTableManager.h"

using namespace std;
class ShuntingYard {
    SymbolTableManager* symbolTableManager;

public:
    ShuntingYard(SymbolTableManager* symbolTableManager);
    Expression* fromInfixToExp(string infixExpression);

private:

    int precedence(char op);
    Expression* createExp(Expression *left, Expression *right, char operation);
    bool isOperator(char c);

};


#endif //PROJECT1_MY_SHUNTINGYARD_H