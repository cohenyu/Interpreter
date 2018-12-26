
#ifndef PROJECT1_MY_DEFINEVARCOMMAND_H
#define PROJECT1_MY_DEFINEVARCOMMAND_H

#include <map>
#include <vector>
#include "Command.h"
#include "SymbolTableManager.h"

using namespace std;
/*
 * this class represent DefineVarCommand
 * its charge to define a new var in the program
 */
class DefineVarCommand : public Command{
    SymbolTableManager* stm;
public:
    DefineVarCommand(SymbolTableManager* stm);
    virtual int doCommand(vector<string> data, int index);
   // ~DefineVarCommand(){
   //     delete stm;
   // }

};


#endif //PROJECT1_MY_DEFINEVARCOMMAND_H
