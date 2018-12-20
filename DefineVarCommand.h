//
// Created by yuval on 18/12/18.
//

#ifndef PROJECT1_MY_DEFINEVARCOMMAND_H
#define PROJECT1_MY_DEFINEVARCOMMAND_H

#include <map>
#include <vector>
#include "Command.h"
#include "SymbolTableManager.h"

using namespace std;

class DefineVarCommand : public Command{
    map<string, double> symbolTable;
    SymbolTableManager* stm;
public:
    DefineVarCommand(SymbolTableManager* stm);
    virtual int doCommand(vector<string> data, int index);

};


#endif //PROJECT1_MY_DEFINEVARCOMMAND_H
