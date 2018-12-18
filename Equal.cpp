//
// Created by yuval on 17/12/18.
//

#include "Equal.h"

Equal::Equal(Expression *left, Expression *right): ComparisonCondition(left, right) {

}

bool Equal::evaluate() {
    return this->left->calculate() == this->right->calculate();
}