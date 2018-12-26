
#ifndef PROJECT1_MY_MUL_H
#define PROJECT1_MY_MUL_H

#include "BinaryExpression.h"
/*
 * this class represent the Multiplication operation,
 * its heiress from BinaryExpression
 */
class Mul :public BinaryExpression{

public:
    Mul(Expression* left, Expression* right);
    virtual double calculate();
};


#endif //PROJECT1_MY_MUL_H
