//
// Created by sagi shaashua on 06/01/2018.
//

#ifndef SERVER_NETWORKGAME_H
#define SERVER_NETWORKGAME_H

#include <pthread.h>
#include <string>
using namespace std;

class NetworkGame {
public:
    ~NetworkGame();
    NetworkGame(string n , pthread_t* threadId , int socket);

    pthread_t *getGameThread();

    int getSocket1();

    int getSocket2();

    string getName();

    void addSecoundPlayer(int s);

private:
    pthread_t *gameThread;
    int socket1, socket2;
    string name;

};


#endif //SERVER_NETWORKGAME_H