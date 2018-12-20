//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_ASSIGNMENTCOMMAND_H
#define YUVALANDMIRIEL_ASSIGNMENTCOMMAND_H

#include "Command.h"
#include "SymbolTableManager.h"

class AssignmentCommand: public Command{
    SymbolTableManager* stm;
public:
    AssignmentCommand(SymbolTableManager* stm);
    virtual int doCommand(vector<string> data, int index);
};


#endif //YUVALANDMIRIEL_ASSIGNMENTCOMMAND_H
