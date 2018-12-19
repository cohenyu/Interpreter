//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_DATAREADERSERVER_H
#define YUVALANDMIRIEL_DATAREADERSERVER_H


#include "TCPServer.h"

class DataReaderServer {
    TCPServer server;
    int rate;
public:
    DataReaderServer(int port, int rate);
    void acceptConnectionsAndReadData();
};


#endif //YUVALANDMIRIEL_DATAREADERSERVER_H
