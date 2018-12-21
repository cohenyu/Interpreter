//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_CONDITIONPARSER_H
#define YUVALANDMIRIEL_CONDITIONPARSER_H

#include "Command.h"
#include "Expression.h"
#include "list"
#include "SymbolTableManager.h"

using namespace std;

class ConditionParser : public Command{
    //TODO
protected:
    Expression* right;
    Expression* left;

    virtual bool checkCondition(string leftStr, string op, string rightStr, SymbolTableManager* stm);
    virtual vector<string> createConditionData (vector<string> data, int index);

public:
    virtual int doCommand(vector<string> data, int index) = 0;
};


#endif //YUVALANDMIRIEL_CONDITIONPARSER_H
