//
// Created by yuval on 17/12/18.
//

#ifndef PROJECT1_MY_GREATER_H
#define PROJECT1_MY_GREATER_H

#include "ComparisonCondition.h"
#include "Expression.h"

class Greater: public ComparisonCondition {
public:
    Greater(Expression* left, Expression* right);
    virtual bool evaluate();
};


#endif //PROJECT1_MY_GREATER_H
