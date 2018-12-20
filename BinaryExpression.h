

#ifndef PROJECT1_MY_BINARYEXPRESSION_H
#define PROJECT1_MY_BINARYEXPRESSION_H

#include "Expression.h"
class BinaryExpression :public Expression{
    Expression* right;
    Expression* left;
public:
    BinaryExpression(Expression* left, Expression* right);
    virtual double calculate() = 0;
    Expression* getRightExpression();
    Expression* getLeftExpression();
    ~BinaryExpression();
};

#endif
