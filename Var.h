//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_VAR_H
#define YUVALANDMIRIEL_VAR_H

#include "Expression.h"

class Var: public Expression {
    string name;
public:
    Var(string name);
    virtual double calculate();

};

#endif //YUVALANDMIRIEL_VAR_H
