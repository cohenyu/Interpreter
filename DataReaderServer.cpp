//
// Created by yuval on 19/12/18.
//

#include <thread>
#include <unistd.h>
#include <iostream>
#include <sstream>
#include "DataReaderServer.h"
#define COMMA ','

#define NEW_LINE '\n'

using namespace std;

void handleClient(int socket, int rate,SymbolTableManager *stm){
    int microSecToSleep = (1000/rate) * 1000;
    SocketCommunication socketCommunication;

    while (true) {
        string data = socketCommunication.readFromSocket(socket,NEW_LINE);
        stm->setValuesFromFlightGear(split(data, COMMA));

        cout << data << endl;
        usleep(microSecToSleep);
    }
}

void startServer(TCPServer server,int rate,SymbolTableManager *stm) {
    server.startListenToConnect();

    while (true) {
        thread t(handleClient, server.acceptConnectionFromClient(),rate, stm);
        t.detach();
    }
}

DataReaderServer::DataReaderServer(int port, int rate) : server(port){
    this->rate = rate;
}

void DataReaderServer::acceptConnectionsAndReadData(SymbolTableManager *stm) {
    stm->setServer(&server);
    thread t(startServer,server,rate,stm);

    t.detach();
}


vector<string> split(const string &str, char delimiter) {
    vector<string> tokens;
    string token;
    istringstream tokenStream(str);
    while (getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}
