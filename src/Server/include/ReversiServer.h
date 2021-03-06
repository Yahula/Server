//
// Created by sagi shaashua on 07/12/2017.
//

#ifndef SERVER_REVERSISERVER_H
#define SERVER_REVERSISERVER_H

#include <pthread.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>
#include <sstream>
#include "CommandsManager.h"
#include <unistd.h>
#include "NetworkGame.h"


/**
 * this class is our server. it conecctes players to play a game.
 */
class ReversiServer {

public:
    /**
     * the constructor.
     * @param port the number of the port.
     */
    ReversiServer(int port);

    /**
     * starts the connection.
     */
    void start();

    /**
     * ends the connection.
     */
    void stop();


    struct commandInfo {
        string command;
        vector<string> args;
    };

    static commandInfo recieveCommand(int socket);


private:

    /**
     * the number of the port.
     */
    int port;

    /**
     *
     */
    int serverSocket;

    /**
     * the command to pass between the players. what move did the other player make.
     */
    char *move;

    /**
     * counts how many times in a raw the players couldn't move.
     */
    int noMovesCounter;

    /**
     * an array of players(clients).
     */
    int *clients;

    bool firstMove;

    pthread_t serverThreadId;


};


#endif //SERVER_REVERSISERVER_H
