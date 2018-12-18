//
// Created by yuval on 17/12/18.
//

#include "ComparisonCondition.h"

ComparisonCondition::ComparisonCondition(Expression *left, Expression *right) {
    this->right = right;
    this->left = left;
}