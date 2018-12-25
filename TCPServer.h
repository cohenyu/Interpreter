//
// Created by yuval on 18/12/18.
//
//
#ifndef PROJECT1_MY_DATAREADERSERVER_H
#define PROJECT1_MY_DATAREADERSERVER_H

#include "SocketCommunication.h"

class TCPServer{
    int port;
    int serverSocket;
    SocketCommunication socketCommunication;
public:
    TCPServer(){}
    TCPServer(int port);
    void startListenToConnect();
    int acceptConnectionFromClient();
    string readFromServer(char separator);
    void writeToServer(string data);
    int getSocket();
    ~TCPServer(){
    }
};

#endif //PROJECT1_MY_DATAREADERSERVER_Ha
