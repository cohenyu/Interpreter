////
//// Created by yuval on 18/12/18.
////
//
#include <netinet/in.h>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <unistd.h>
#include <thread>
#include "TCPServer.h"

#define BUFFER_SIZE 1024

TCPServer::TCPServer(int port) {// : socketCommunication(-1)
    this->port = port;
    this->serverSocket = -1;
}

void TCPServer::startListenToConnect() {
    // initalize the sockets variables
    struct sockaddr_in serv_addr;

    /* First call to socket() function */
    this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    socketCommunication = SocketCommunication();/*this->serverSocket*/

    if (this->serverSocket < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(this->port);

    /* Now bind the host address using bind() call.*/
    if (bind(this->serverSocket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(this->serverSocket, 5);
}

int TCPServer::acceptConnectionFromClient() {
    int sockfd, newsockfd, clilen;
    char buffer[BUFFER_SIZE + 1];
    struct sockaddr_in cli_addr;
    int n;

    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(this->serverSocket, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);

    if (newsockfd < 0) {
        perror("ERROR on accept");
        exit(1);
    }

    return newsockfd;
}



string TCPServer::readFromServer(char seperator) {
    return socketCommunication.readFromSocket(this->serverSocket, seperator);
}

void TCPServer::writeToServer(string data) {
    socketCommunication.writeToSocket(this->serverSocket, data);
}