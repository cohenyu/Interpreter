//
// Created by yuval on 19/12/18.
//

#ifndef YUVALANDMIRIEL_TCPCLIENT_H
#define YUVALANDMIRIEL_TCPCLIENT_H

#include "SocketCommunication.h"

using namespace std;

class TCPClient {
    int clientSocket;
    int port;
    string ipAddress;
    SocketCommunication socketCommunication;
public:
    int getSocket();
    TCPClient(string ipAddress, int port);
    void connectToServer();
    string readFromServer(char separator);
    void writeToServer(string data);
    ~TCPClient(){
       // close(clientSocket);
    }
};


#endif //YUVALANDMIRIEL_TCPCLIENT_H
