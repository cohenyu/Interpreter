//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_WHILECOMMAND_H
#define YUVALANDMIRIEL_WHILECOMMAND_H

#include "ConditionParser.h"
#include "SymbolTableManager.h"
class WhileCommand : public ConditionParser{
    SymbolTableManager* stm;
public:
    WhileCommand(SymbolTableManager* stm);
    virtual int doCommand(vector<string> data, int index);
};


#endif //YUVALANDMIRIEL_WHILECOMMAND_H
