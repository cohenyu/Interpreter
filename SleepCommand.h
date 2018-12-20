//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_SLEEPCOMMAND_H
#define YUVALANDMIRIEL_SLEEPCOMMAND_H

#include "Command.h"
#include "SymbolTableManager.h"

class SleepCommand: public Command {
    SymbolTableManager* stm;
public:
    SleepCommand(SymbolTableManager* stm); //TODO
    virtual int doCommand(vector<string> data,int index);

};


#endif //YUVALANDMIRIEL_SLEEPCOMMAND_H
