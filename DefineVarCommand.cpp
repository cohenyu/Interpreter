//
// Created by yuval on 18/12/18.
//

#include "DefineVarCommand.h"

DefineVarCommand::DefineVarCommand(SymbolTableManager *stm) {
    this->stm = stm;
}

int DefineVarCommand::doCommand(vector<string> data, int index) {
    string varName = data[index +1];
    this->stm->addVarToSymbolTable(varName, 0);

    return 2;
}