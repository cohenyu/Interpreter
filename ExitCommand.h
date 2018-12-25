//
// Created by yuval on 24/12/18.
//

#ifndef YUVALANDMIRIEL_EXITCOMMAND_H
#define YUVALANDMIRIEL_EXITCOMMAND_H

#include "Command.h"
#include "SymbolTableManager.h"

class ExitCommand: public Command {
    SymbolTableManager* stm;
public:
    ExitCommand(SymbolTableManager* stm);
    int doCommand(vector<string> data, int index);


};


#endif //YUVALANDMIRIEL_EXITCOMMAND_H
