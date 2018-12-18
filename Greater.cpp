//
// Created by yuval on 17/12/18.
//

#include "Greater.h"

Greater::Greater(Expression *left, Expression *right) : ComparisonCondition(left, right){

}

bool Greater::evaluate() {
    return this->left->calculate() > this->right->calculate();
}