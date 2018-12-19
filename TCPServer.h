//
// Created by yuval on 18/12/18.
//
//
#ifndef PROJECT1_MY_DATAREADERSERVER_H
#define PROJECT1_MY_DATAREADERSERVER_H

class TCPServer{
    int port;
    int serverSocket;
public:
    TCPServer(int port);
    void startListenToConnect();
    int acceptConnectionFromClient();
};

#endif //PROJECT1_MY_DATAREADERSERVER_Ha
