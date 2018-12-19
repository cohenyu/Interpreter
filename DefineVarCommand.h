//
// Created by yuval on 18/12/18.
//

#ifndef PROJECT1_MY_DEFINEVARCOMMAND_H
#define PROJECT1_MY_DEFINEVARCOMMAND_H

#include <map>
#include <vector>
#include "Command.h"
using namespace std;

class DefineVarCommand : public Command{
    map<string, double> symbolTable;
public:
    virtual int doCommand(vector<string> data);

};


#endif //PROJECT1_MY_DEFINEVARCOMMAND_H
