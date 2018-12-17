#ifndef PROJECT1_MY_EXPRESSION_H
#define PROJECT1_MY_EXPRESSION_H

#include <string>

using namespace std;

class Expression {

public:
    virtual double calculate() = 0;
    virtual Expression* shuntingYard(string infixExpression);
};

#endif
