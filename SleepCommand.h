//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_SLEEPCOMMAND_H
#define YUVALANDMIRIEL_SLEEPCOMMAND_H

#include "Command.h"
#include "SymbolTableManager.h"
/*
 * this class represent a sleep command that heiress from command
 * the class execute sleep for milliseconds.
 */
class SleepCommand: public Command {
    SymbolTableManager* stm;
public:
    SleepCommand(SymbolTableManager* stm);
    virtual unsigned int doCommand(vector<string> data,unsigned int index);

};


#endif //YUVALANDMIRIEL_SLEEPCOMMAND_H
