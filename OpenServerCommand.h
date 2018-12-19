//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_OPENSERVERCOMMAND_H
#define YUVALANDMIRIEL_OPENSERVERCOMMAND_H

#include "Command.h"

class OpenServerCommand : public Command{

public:
    //TODO
    OpenServerCommand();
    virtual  int doCommand(vector<string> data,int index);
};


#endif //YUVALANDMIRIEL_OPENSERVERCOMMAND_H
