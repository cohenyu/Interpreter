//
// Created by yuval on 18/12/18.
//

#ifndef PROJECT1_MY_COMMANDEXPRESSION_H
#define PROJECT1_MY_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"

class CommandExpression: public Expression {
    Command* command;
public:
    CommandExpression(Command* command);
    virtual double calculate();

};


#endif //PROJECT1_MY_COMMANDEXPRESSION_H
