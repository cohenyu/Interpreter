////
//// Created by yuval on 18/12/18.
////
//
//#include <netinet/in.h>
//#include <cstdio>
//#include <cstdlib>
//#include <memory.h>
//#include <unistd.h>
//#include <thread>
//#include "DataReaderServer.h"
//
//#define BUFFER_SIZE 1024
//
//static void handleClient(int socket){
//    write(socket,"shalom",7);
//}
//
//static void startServer(int port,int rate) {
//    DataReaderServer server = DataReaderServer(port,rate);
//    server.startListenToConnect();
//    while (true){
//        std::thread(handleClient, server.accpetConnectionFromClient());
//    }
//}
//
//DataReaderServer::DataReaderServer(int port, int rate) {
//    this->port = port;
//    this->rate = rate;
//    this->serverSocket = -1;
//}
//
//void DataReaderServer::startListenToConnect() {
//    // initalize the sockets variables
//    struct sockaddr_in serv_addr;
//
//    /* First call to socket() function */
//    this->serverSocket = socket(AF_INET, SOCK_STREAM, 0);
//
//    if (this->serverSocket < 0) {
//        perror("ERROR opening socket");
//        exit(1);
//    }
//
//    /* Initialize socket structure */
//    bzero((char *) &serv_addr, sizeof(serv_addr));
//
//    serv_addr.sin_family = AF_INET;
//    serv_addr.sin_addr.s_addr = INADDR_ANY;
//    serv_addr.sin_port = htons(this->port);
//
//    /* Now bind the host address using bind() call.*/
//    if (bind(this->serverSocket, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
//        perror("ERROR on binding");
//        exit(1);
//    }
//
//    /* Now start listening for the clients, here process will
//       * go in sleep mode and will wait for the incoming connection
//    */
//
//    listen(this->serverSocket, 5);
//}
//
//int DataReaderServer::accpetConnectionFromClient() {
//    int sockfd, newsockfd, clilen;
//    char buffer[BUFFER_SIZE + 1];
//    struct sockaddr_in cli_addr;
//    int n;
//
//    clilen = sizeof(cli_addr);
//
//    /* Accept actual connection from the client */
//    newsockfd = accept(this->serverSocket, (struct sockaddr *)&cli_addr, (socklen_t*)&clilen);
//
//    if (newsockfd < 0) {
//        perror("ERROR on accept");
//        exit(1);
//    }
//
//    std::thread aba = std::thread(startServer,5400,10);
//
//    return newsockfd;
//}



