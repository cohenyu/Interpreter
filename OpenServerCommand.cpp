//
// Created by yuval on 19/12/18.
//

#include <unistd.h>
#include "OpenServerCommand.h"
#include "ShuntingYard.h"
#include "DataReaderServer.h"
// in this case read from the socket at a given rate
OpenServerCommand::OpenServerCommand(SymbolTableManager* stm) {
    this->stm= stm;
}


int OpenServerCommand::doCommand(vector<string> data, int index) {
    ShuntingYard shuntingYard(stm);
    Expression *exp;
    int rate, port;

    exp = shuntingYard.fromInfixToExp(data[index + 1]);
    port = static_cast<int>(exp->calculate());
    delete exp;

    exp = shuntingYard.fromInfixToExp(data[index + 2]);
    rate = static_cast<int>(exp->calculate());
    delete exp;

    DataReaderServer(port,rate).acceptConnectionsAndReadData(stm);
    return 3;
}