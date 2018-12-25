//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_DATAREADERSERVER_H
#define YUVALANDMIRIEL_DATAREADERSERVER_H


#include "TCPServer.h"
#include "SymbolTableManager.h"
#include <vector>

class DataReaderServer {
    //TODO
    TCPServer server;
    int rate;
public:
    DataReaderServer(int port, int rate);
    void acceptConnectionsAndReadData(SymbolTableManager *stm);

};

vector<string> split(const string& str, char delimiter);

#endif //YUVALANDMIRIEL_DATAREADERSERVER_H
