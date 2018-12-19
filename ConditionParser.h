//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_CONDITIONPARSER_H
#define YUVALANDMIRIEL_CONDITIONPARSER_H

#include "Command.h"
#include "list"
using namespace std;

class ConditionParser : public Command{
    //TODO
protected:
    list<Command*> commands;

public:
    virtual int doCommand(vector<string> data, int index) = 0;
};


#endif //YUVALANDMIRIEL_CONDITIONPARSER_H
