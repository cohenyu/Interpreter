//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_IFCOMMAND_H
#define YUVALANDMIRIEL_IFCOMMAND_H

#include "ConditionParser.h"

class IfCommand : public ConditionParser{
public:
    virtual int doCommand(vector<string> data, int index);
};


#endif //YUVALANDMIRIEL_IFCOMMAND_H
