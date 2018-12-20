#include "ConnectCommand.h"
#include "Expression.h"
#include "ShuntingYard.h"
#include "TCPClient.h"


ConnectCommand::ConnectCommand(SymbolTableManager* stm) {
    this->stm = stm;
}


int ConnectCommand::doCommand(vector<string> data, int index) {
    ShuntingYard shuntingYard(stm);
    Expression *exp;
    int port;
    string ipAddress;

    ipAddress = data[index + 1];
    
    exp = shuntingYard.fromInfixToExp(data[index + 2]);
    port = static_cast<int>(exp->calculate());
    // TODO destructors
    delete exp;

    TCPClient client(ipAddress,port);
    client.connectToServer();
    // TODO add client to symbol table
    return 3;

}
