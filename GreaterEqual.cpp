//
// Created by yuval on 17/12/18.
//

#include "GreaterEqual.h"

GreaterEqual::GreaterEqual(Expression *left, Expression *right):ComparisonCondition(left, right) {

}

bool GreaterEqual::evaluate() {
    return this->left->calculate() >= this->right->calculate();
}