

#include "BinaryExpression.h"
BinaryExpression::BinaryExpression(Expression *left, Expression *right) {
    this->left = left;
    this->right = right;
}
Expression* BinaryExpression::getLeftExpression() {
    return this->left;
}

Expression* BinaryExpression::getRightExpression() {
    return this->right;
}

BinaryExpression::~BinaryExpression() {
    delete this->left;
    delete this->right;
}