//
// Created by yuval on 13/12/18.
//

#include "Minus.h"
Minus::Minus(Expression *left, Expression *right) : BinaryExpression(left, right){

}

double Minus::calculate() {
    return this->getLeftExpression()->calculate() - this->getRightExpression()->calculate();
}