//
// Created by yuval on 17/12/18.
//

#include "LessEqual.h"

LessEqual::LessEqual(Expression *left, Expression *right): ComparisonCondition(left, right) {

}

bool LessEqual::evaluate() {
    return this->left->calculate() <= this->right->calculate();
}
