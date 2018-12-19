//
// Created by yuval on 19/12/18.
//

#include <thread>
#include <unistd.h>
#include "DataReaderServer.h"

using namespace std;

void handleClient(int socket, int rate){
    // TODO read at the wanted rate
    //write(socket,"shalom",7);
}

void startServer(TCPServer server,int rate) {
    server.startListenToConnect();

    while (true) {
        thread(handleClient, server.acceptConnectionFromClient());
    }
}

DataReaderServer::DataReaderServer(int port, int rate) : server(port){
    this->rate = rate;
}

void DataReaderServer::acceptConnectionsAndReadData() {
    thread(startServer,server,rate);
}
