

#ifndef YUVALANDMIRIEL_CONNECTCOMMAND_H
#define YUVALANDMIRIEL_CONNECTCOMMAND_H

#include "Command.h"
#include "SymbolTableManager.h"

/*
 * this class represent a ConnectCommand .
 * the connect have ip and port
 * its responsible to connectection
 */
class ConnectCommand : public Command{
    SymbolTableManager* stm;
public:
    ConnectCommand(SymbolTableManager* stm);
    virtual  int doCommand(vector<string> data,int index);
};


#endif //YUVALANDMIRIEL_CONNECTCOMMAND_H
