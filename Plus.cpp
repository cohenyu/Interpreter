
#include "Plus.h"

Plus::Plus(Expression *left, Expression *right) :BinaryExpression(left, right){

}

double Plus::calculate() {
    return this->getLeftExpression()->calculate() + this->getRightExpression()->calculate();
}