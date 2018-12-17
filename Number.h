
#ifndef PROJECT1_MY_NUMBER_H
#define PROJECT1_MY_NUMBER_H

#include "Expression.h"

class Number : public Expression{
    double num;
public:
    Number(double num);
    virtual double calculate();
};


#endif //PROJECT1_MY_NUMBER_H
