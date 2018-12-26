
#ifndef PROJECT1_MY_COMMANDEXPRESSION_H
#define PROJECT1_MY_COMMANDEXPRESSION_H

#include "Expression.h"
#include "Command.h"
#include "SymbolTableManager.h"


/*
 * this class represent CommandExpression,its heiress from Expression.
 */
class CommandExpression: public Expression {
    Command*  command;
    vector<string> &data;
    int &index;
   // virtual ~CommandExpression(){
   //     delete command;
   // }

public:
    CommandExpression(Command* command,vector<string>& data, int &index);
    virtual double calculate();

    virtual ~CommandExpression(){
        delete command;
    }

};


#endif //PROJECT1_MY_COMMANDEXPRESSION_H
