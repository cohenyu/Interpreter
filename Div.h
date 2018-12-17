//
// Created by yuval on 13/12/18.
//

#ifndef PROJECT1_MY_DIV_H
#define PROJECT1_MY_DIV_H

#include "BinaryExpression.h"
class Div :public BinaryExpression{
public:
    Div(Expression* left, Expression* right);
    virtual double calculate();
};


#endif //PROJECT1_MY_DIV_H
