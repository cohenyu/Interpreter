//
// Created by yuval on 19/12/18.
//

#include <unistd.h>
#include "SocketCommunication.h"

#define MESSAGE_SEPERATOR '\n'

SocketCommunication::SocketCommunication() {
}

string SocketCommunication::readLineFromSocket(int socket) {
    char c = '\0';
    int n;
    string data;

    if (socket < 0){
        // TODO ERROR
    }

    n = read(socket, &c, 1);
    while (c != MESSAGE_SEPERATOR) {
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        data += c;
        n = read(socket, &c, 1);
    }

    return data;
}

void SocketCommunication::writeToSocket(int socket, string data) {
    int n = write(socket, data.c_str(), data.length());

    if (socket < 0){
        // TODO ERROR
    }

    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}
