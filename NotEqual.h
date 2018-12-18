//
// Created by yuval on 17/12/18.
//

#ifndef PROJECT1_MY_NOTEQUAL_H
#define PROJECT1_MY_NOTEQUAL_H

#include "ComparisonCondition.h"
#include "Expression.h"

class NotEqual: ComparisonCondition {
public:
    NotEqual(Expression* left, Expression* right);
    virtual bool evaluate();
};


#endif //PROJECT1_MY_NOTEQUAL_H
