//
// Created by sagi shaashua on 07/12/2017.
//

#include "ReversiServer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>

#define MAX_CONNECTED_CLIENTS 2

ReversiServer::ReversiServer(int port) : port(port), serverSocket(0) {
    this->move = new char[2];
    std::cout << "Server" << std::endl;
}

void ReversiServer::start() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }

    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if(bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress))==-1){
        throw "Error on binding";
    }


    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;

    int players = 0;

    while (players < 2) {
        std::cout << "Waiting for players connection..." << std::endl;

        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        if (clientSocket == -1)
            throw "Error on accept";

        players++;

        std::cout << "Player number " << players<<" connected."<< std::endl;
        int n = write(clientSocket,&players, sizeof(players));
        if (n==-1) {
            std::cout << "Error writing to socket" << std::endl;
            continue;
        }
        if(players == 1){
            char who[] = "You are the Black player (X), you play first! Waiting for other player to join...";
            int n = write(clientSocket,&who, sizeof(who));
            if (n==-1){
                std::cout << "Error writing to socket" << std::endl;
                continue;
            }
        }

        if(players == 2) {
            char who[] = "You are the White player (O), you play second!, waiting for black player move...";
            int n = write(clientSocket, &who, sizeof(who));
            if (n == -1) {
                std::cout << "Error writing to socket" << std::endl;
                continue;
            }
        }
        close(clientSocket);
    }

    while (true) {
        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        if (clientSocket == -1)
            throw "Error on accept";
        hendleClient(clientSocket);
        close(clientSocket);
    }
}

void ReversiServer::hendleClient(int clientSocket) {

        while (true) {

//            n = write(clientSocket, &, sizeof(result));
//            if (n == -1) {
//                std::cout << "Error writing to socket" << endl;
//                return;
//            }

            int n = read(clientSocket, &this->move, sizeof(this->move));
            if (n == -1) {
                std::cout << "Error reading arg1" << std::endl;
                return;
            }
            if (n == 0) {
                std::cout << "Client disconnected" << std::endl;
                return;
            }


        }
}



void ReversiServer::stop() {
    close(serverSocket);
}
