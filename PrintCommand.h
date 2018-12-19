//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_PRINTCOMMAND_H
#define YUVALANDMIRIEL_PRINTCOMMAND_H

#include "Command.h"

class PrintCommand: public Command {
public:
    PrintCommand(); //TODO
    virtual int doCommand(vector<string> data,int index);
};


#endif //YUVALANDMIRIEL_PRINTCOMMAND_H
