//
// Created by yuval on 17/12/18.
//

#ifndef PROJECT1_MY_EQUAL_H
#define PROJECT1_MY_EQUAL_H

#include "Expression.h"
#include "ComparisonCondition.h"

class Equal: public ComparisonCondition {

public:
    Equal(Expression* left, Expression* right);
    virtual bool evaluate();
};


#endif //PROJECT1_MY_EQUAL_H
