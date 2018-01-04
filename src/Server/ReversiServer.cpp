//
// Created by sagi shaashua on 07/12/2017.
//

#include "./include/ReversiServer.h"
#include "include/CommandsManager.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <sstream>

#define MAX_CONNECTED_CLIENTS 10
#define MAX_COMMAND_LEN 20

static void *acceptClients(void *);
static void *handleClient(void *);

ReversiServer::ReversiServer(int port) : port(port), serverSocket(0) {
    this->move = new char[10];
    this->move[0] = 'O';
    this->move[1] = 'K';
    this->move[2] = '.';
    this->noMovesCounter = 0;
    this->clients = new int[MAX_CONNECTED_CLIENTS];
    this->firstMove = true;

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

    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }


    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    pthread_create(&serverThreadId, NULL, &acceptClients, (void *) serverSocket);
}
static void *acceptClients(void *socket) {
    long serverSocket = (long) socket;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;

    while (true) {
        std::cout << "Waiting for client connections..." << std::endl;

        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        if (clientSocket == -1)
            throw "Error on accept";
        std::cout << "Client connected" << std::endl;

        pthread_t threadId;
        pthread_create(&threadId, NULL, &handleClient, (void *) clientSocket);
    }
}

static void *handleClient(void *socket) {
    long clientSocket = (long) socket;
    char commandStr[MAX_COMMAND_LEN];
    // Read the command from the socket
    int n = read(clientSocket, commandStr, MAX_COMMAND_LEN);
    if (n == -1) {
        cout << "Error reading command" << endl;
        return NULL;
    }
    cout << "Received command: " << commandStr << endl;
    // Split the command string to the command name and the arguments
    string str(commandStr);
    istringstream iss(str);
    string command;
    iss >> command;
    vector<string> args;
    while (iss) {
        string arg;
        iss >> arg;
        args.push_back(arg);
    }
    CommandsManager::getInstance()->executeCommand(command, args, clientSocket);
    return NULL;
}
//        int players = 0;
//    //first player connection
//    int clientSocket1 = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
//    if (clientSocket1 == -1)
//        throw "Error on accept";
//    else{
//        players = 1;
//
//        std::cout << "Player number 1 connected."<< std::endl;
//
//        int n = write(clientSocket1,&players, sizeof(players));
//        if (n==-1) {
//            std::cout << "Error writing to socket" << std::endl;
//        }
//        char who1[] = "You are the Black player (X), you play first! \n Waiting for other player to join...";
//        n = write(clientSocket1,who1, sizeof(who1)/ sizeof(char));
//        if (n==-1){
//            std::cout << "Error writing to socket" << std::endl;
//        }
//    }
//
//
//    //Second player connection
//    int clientSocket2 = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
//    if (clientSocket2 == -1)
//        throw "Error on accept";
//    else {
//        players = 2;
//
//        std::cout << "Player number 2 connected."<< std::endl;
//
//        int n = write(clientSocket2,&players, sizeof(players));
//        if (n==-1) {
//            std::cout << "Error writing to socket" << std::endl;
//        }
//
//        char who2[] = "You are the White player (O), you play second! \n waiting for black player move...";
//        n = write(clientSocket2, who2, sizeof(who2)/ sizeof(char));
//        if (n == -1) {
//            std::cout << "Error writing to socket" << std::endl;
//        }
//    }
//
//    this->clients[0] = clientSocket1;
//    this->clients[1] = clientSocket2;
//    int cNum = 1;
//
//    if(firstMove){
//        int n = read(clients[0], this->move, sizeof(this->move)/ sizeof(char));
//        if (n == -1) {
//            std::cout << "Error reading move" << std::endl;
//            return;
//        }
//        if (n == 0) {
//            std::cout << "Client disconnected" << std::endl;
//            return;
//        }
//    }
//    while (noMovesCounter!=3) {
//            hendleClient(clients[cNum]);
//            cNum = (cNum+1)%2;
//
//    }
//    }
/**
 * this method hendles the client conection - sends information and resieves information.
 * @param clientSocket what socket to use.
 */
//void ReversiServer::hendleClient(int clientSocket) {
//    int n = write(clientSocket, this->move, sizeof(this->move) / sizeof(char));
//    if (n == -1) {
//        std::cout << "Error writing to socket" << std::endl;
//        return;
//    }
//
//    n = read(clientSocket, this->move, sizeof(this->move)/ sizeof(char));
//    if (n == -1) {
//        std::cout << "Error reading move" << std::endl;
//        return;
//    }
//    if (n == 0) {
//        std::cout << "Client disconnected" << std::endl;
//        return;
//    }
//    std::cout<<"Move recieved"<<std::endl;
//    if(!strcmp(this->move,"nmv")) {
//        noMovesCounter++;
//        if (noMovesCounter == 2) {
//            char end[] = "end";
//            int n = write(clients[0], end, sizeof(end)/sizeof(char));
//            if (n == -1) {
//                std::cout << "Error writing end to fist socket" << std::endl;
//                return;
//            }
//            close(clients[0]);
//            n = write(clients[1], end, sizeof(end)/sizeof(char));
//            if (n == -1) {
//                std::cout << "Error writing end to second socket" << std::endl;
//                return;
//            }
//            close(clients[1]);
//            noMovesCounter++;
//        }
//    } else {
//        noMovesCounter = 0;
//    }
//
//}


/**
 * closes the socket.
 */
    void ReversiServer::stop() {
    pthread_cancel(serverThreadId);
        close(serverSocket);
    cout << "Server stopped" << endl;
    }