

#ifndef PROJECT1_MY_MINUS_H
#define PROJECT1_MY_MINUS_H

#include "BinaryExpression.h"
/*
 * this class represent the Minus operation,its heiress from BinaryExpression
 */
class Minus :public BinaryExpression{
public:
    Minus(Expression* left, Expression* right);
    virtual double calculate();
};


#endif //PROJECT1_MY_MINUS_H
