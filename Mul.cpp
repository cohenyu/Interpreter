
#include "Mul.h"
Mul::Mul(Expression *left, Expression *right) : BinaryExpression(left, right){

}

double Mul::calculate() {
    return this->getLeftExpression()->calculate() * this->getRightExpression()->calculate();
}