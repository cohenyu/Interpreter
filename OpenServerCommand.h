//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_OPENSERVERCOMMAND_H
#define YUVALANDMIRIEL_OPENSERVERCOMMAND_H

#include "Command.h"
#include "SymbolTableManager.h"
/*
 * this class represent a OpenServerCommand
 * means its responsible to the connection with the server.
 */
class OpenServerCommand : public Command{
    SymbolTableManager* stm;
public:
    OpenServerCommand(SymbolTableManager* stm);
    virtual  int doCommand(vector<string> data,int index);
//    ~OpenServerCommand(){
//        delete stm;
//    }
};


#endif //YUVALANDMIRIEL_OPENSERVERCOMMAND_H
