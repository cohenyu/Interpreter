//
// Created by yuval on 18/12/18.
//

#ifndef PROJECT1_MY_COMMANDEXPRESSION_H
#define PROJECT1_MY_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
#include "SymbolTableManager.h"

class CommandExpression: public Expression {
    Command*  command;
    vector<string> &data;
    int &index;
    ~CommandExpression(){
        //delete command;
    }

public:
    CommandExpression(Command* command,vector<string>& data, int &index);
    virtual double calculate();

};


#endif //PROJECT1_MY_COMMANDEXPRESSION_H
