//
// Created by yuval on 19/12/18.
//

#include <unistd.h>
#include "OpenServerCommand.h"
#include "ShuntingYard.h"
#include "DataReaderServer.h"

// constructor
OpenServerCommand::OpenServerCommand(SymbolTableManager* stm) {
    this->stm= stm;
}

/**
 * The function opens a thread that opens a server on the given port and
 * reads lines according to the desired rate.
 * @param data the main vector
 * @param index the index if the command on the vector
 * @return how mach moves to step after this command.
 */
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