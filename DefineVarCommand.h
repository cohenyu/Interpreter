//
// Created by yuval on 18/12/18.
//

#ifndef PROJECT1_MY_DEFINEVARCOMMAND_H
#define PROJECT1_MY_DEFINEVARCOMMAND_H

#include <map>
#include <vector>
using namespace std;

class DefineVarCommand {
    map<string, double> symbolTable;
    virtual int doCommand(vector<string> data);

};


#endif //PROJECT1_MY_DEFINEVARCOMMAND_H
