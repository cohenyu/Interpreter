//
// Created by yuval on 17/12/18.
//

#include "Less.h"

Less::Less(Expression *left, Expression *right):ComparisonCondition(left, right) {

}

bool Less::evaluate() {
    return this->left < this->right;
}