//
// Created by yuval on 17/12/18.
//

#ifndef PROJECT1_MY_GREATEREQUAL_H
#define PROJECT1_MY_GREATEREQUAL_H

#include "ComparisonCondition.h"
#include "Expression.h"

class GreaterEqual : public ComparisonCondition{
public:
    GreaterEqual(Expression* left, Expression* right);
    virtual bool evaluate();
};


#endif //PROJECT1_MY_GREATEREQUAL_H
