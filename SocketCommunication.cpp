//
// Created by yuval on 19/12/18.
//

#include <unistd.h>
#include "SocketCommunication.h"

#define MESSAGE_SEPERATOR '\n'

//constructor
SocketCommunication::SocketCommunication() {
}

/**
 * The function read from the given socket until the given separator and returns what it reads.
 * @param socket the socket to read from
 * @param seperator read until the separator
 * @return what the function reaf from the socket
 */
string SocketCommunication::readFromSocket(int socket, char separator) {
    char c = '\0';
    int n;
    string data;

    if (socket < 0){
        perror("ERROR socket not found");
    }

    n = read(socket, &c, 1);
    while (c != separator) {
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }

        data += c;
        n = read(socket, &c, 1);
    }

    return data;
}

/**
 * The function write the string data to the the given socket.
 * @param socket the socket to write to
 * @param data the string to write
 */
void SocketCommunication::writeToSocket(int socket, string data) {
    int n;

    if (socket < 0){
        perror("ERROR socket not found");
    }

    n = write(socket, data.c_str(), data.length());
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}
