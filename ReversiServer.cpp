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
    this->move = new char[3];
    this->move[0] = '0';
    this->move[1] = ',';
    this->move[2] = '0';
    this->noMovesCounter = 0;
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
    bool firstMove = true;
    int players = 0;

    std::cout << "Waiting for players connection..." << std::endl;

    //first player connection
    int clientSocket1 = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
    if (clientSocket1 == -1)
        throw "Error on accept";
    else{
        players = 1;

        std::cout << "Player number 1 connected."<< std::endl;

        int n = write(clientSocket1,&players, sizeof(players));
        if (n==-1) {
            std::cout << "Error writing to socket" << std::endl;
        }
        char who1[] = "You are the Black player (X), you play first! Waiting for other player to join...";
        n = write(clientSocket1,&who1, sizeof(who1));
        if (n==-1){
            std::cout << "Error writing to socket" << std::endl;
        }
    }


    //Second player connection
    int clientSocket2 = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
    if (clientSocket2 == -1)
        throw "Error on accept";
    else {
        players = 2;

        std::cout << "Player number 2 connected."<< std::endl;

        int n = write(clientSocket2,&players, sizeof(players));
        if (n==-1) {
            std::cout << "Error writing to socket" << std::endl;
        }

        char who2[] = "You are the White player (O), you play second!, waiting for black player move...";
        n = write(clientSocket2, &who2, sizeof(who2));
        if (n == -1) {
            std::cout << "Error writing to socket" << std::endl;
        }
    }
    while (true) {
        if(firstMove){
            int n = read(clientSocket1, &this->move, sizeof(this->move));
            if (n == -1) {
                std::cout << "Error reading arg1" << std::endl;
                return;
            }
            else{
                std::cout<<"move recieved by server"<<std::endl;
            }
            if (n == 0) {
                std::cout << "Client disconnected" << std::endl;
                return;
            }
            firstMove = false;
        }
        else {
            hendleClient(clientSocket2);
            hendleClient(clientSocket1);
        }
    }
}
/**
 * this method hendles the client conection - sends information and resieves information.
 * @param clientSocket what socket to use.
 */
void ReversiServer::hendleClient(int clientSocket) {
//    if (noMovesCounter==2){
//        std::cout<<"Game Over!"<<std::endl;
//        close(clientSocket);
//        return;
//    }
    int n = write(clientSocket, &this->move, 3);
    if (n == -1) {
        std::cout << "Error writing to socket" << std::endl;
        return;
    }

    n = read(clientSocket, &this->move, sizeof(this->move));
    if (n == -1) {
        std::cout << "Error reading arg1" << std::endl;
        return;
    }
    if (n == 0) {
        std::cout << "Client disconnected" << std::endl;
        return;
    }
//    if (!strcmp(this->move, "END")) {
//        this->noMovesCounter++;
//    }
//    else{
//        this->noMovesCounter=0;
//    }
}


/**
 * closes the socket.
 */
void ReversiServer::stop() {
    close(serverSocket);
}
