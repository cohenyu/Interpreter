//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_CONNECTCOMMAND_H
#define YUVALANDMIRIEL_CONNECTCOMMAND_H

#include "Command.h"
#include "SymbolTableManager.h"


class ConnectCommand : public Command{
    SymbolTableManager* stm;
public:
    ConnectCommand(SymbolTableManager* stm);

    // TODO
    virtual  int doCommand(vector<string> data,int index);

};


#endif //YUVALANDMIRIEL_CONNECTCOMMAND_H
