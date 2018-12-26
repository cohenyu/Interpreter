//
// Created by yuval on 19/12/18.
//

#include <thread>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <sstream>
#include "DataReaderServer.h"
#include <EnterC.h>
#define COMMA ','

#define NEW_LINE '\n'

using namespace std;

void handleClient(int socket, int rate,SymbolTableManager *stm){
    int microSecToSleep = (1000/rate) * 1000;
    SocketCommunication socketCommunication;
    while (true) {
        string data = socketCommunication.readFromSocket(socket,NEW_LINE);
        vector<string> splited = split(data, COMMA);
        stm->setValuesFromFlightGear(splited);

        //cout << data << endl;
        //todo
        usleep(microSecToSleep);
    }
}


/// todo
// //stm->setServer(&server);

// constructor
// TODO
/*
 * this is the constructor of DataReaderServer.
 */
DataReaderServer::DataReaderServer(int port, int rate) {//: server(port){
    this->server = TCPServer(port);
    this->rate = rate;
}

/**
 * this function accepts connection and read data
 * @param stm the symbol table manager
 */
void DataReaderServer::acceptConnectionsAndReadData(SymbolTableManager *stm) {

    stm->setServer(this->server);
    this->server.startListenToConnect();

    thread t(handleClient, server.acceptConnectionFromClient(),rate, stm);
    t.detach();
}

/**
 * The function accepts a string and splits it according to the given delimiter.
 * @param str the string
 * @param delimiter the separator
 * @return the splited string in vector
 */
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
