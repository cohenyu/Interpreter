
#ifndef PROJECT1_MY_DATAREADERSERVER_H
#define PROJECT1_MY_DATAREADERSERVER_H

#include "SocketCommunication.h"
/*
 * this class represent a TCPServer.
 * it have port ,socket of the server
 * and SocketCommunication in order to be able to connect
 */
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
//    ~TCPServer(){
//    }
};

#endif //PROJECT1_MY_DATAREADERSERVER_Ha
