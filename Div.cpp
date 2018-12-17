//
// Created by yuval on 13/12/18.
//

#include "Div.h"

Div::Div(Expression *left, Expression *right): BinaryExpression(left, right) {

}
double Div::calculate() {
    return this->getLeftExpression()->calculate() / this->getRightExpression()->calculate();
}