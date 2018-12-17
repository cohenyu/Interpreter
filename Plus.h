
#ifndef PROJECT1_MY_PLUS_H
#define PROJECT1_MY_PLUS_H

#include "BinaryExpression.h"
class Plus: public BinaryExpression {
public:
    Plus(Expression* left, Expression* right);
    virtual double calculate();
};


#endif
