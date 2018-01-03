//
// Created by sagi shaashua on 07/12/2017.
//

#ifndef SERVER_REVERSISERVER_H
#define SERVER_REVERSISERVER_H

#include <pthread.h>

class ReversiServer {
public:
    ReversiServer(int port);
    void start();
    void stop();
private:
    int port;
    int serverSocket;
    char* move;
    void hendleClient(int clientServer);
    int noMovesCounter;
    int* clients;
    bool firstMove;
    pthread_t serverThreadId;
};


#endif //SERVER_REVERSISERVER_H
