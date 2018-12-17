//
// Created by yuval on 17/12/18.
//

#include "Neg.h"

Neg::Neg(Expression *exp) :UnaryExpression(exp){

}

double Neg::calculate() {
    return -1 * this->getExpression()->calculate();
}