//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_WHILECOMMAND_H
#define YUVALANDMIRIEL_WHILECOMMAND_H

#include "ConditionParser.h"
class WhileCommand : public ConditionParser{

public:
    virtual int doCommand(vector<string> data, int index);
};


#endif //YUVALANDMIRIEL_WHILECOMMAND_H
