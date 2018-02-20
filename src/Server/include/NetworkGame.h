//
// Created by sagi shaashua on 06/01/2018.
//

#ifndef SERVER_NETWORKGAME_H
#define SERVER_NETWORKGAME_H

#include <pthread.h>
#include <string>
#include "ClientsInformation.h"

using namespace std;

/**
 * this calss strores the information of a single game.
 */
class NetworkGame {
public:
    ~NetworkGame();

   // NetworkGame(string n , ClientsInformation clio);
    NetworkGame(int socket);

    NetworkGame(const NetworkGame& other);

    pthread_t getGameThread();

    int getSocket1();

    int getSocket2();

    string getName();

    void addSecoundPlayer(int s);

    void setThread(pthread_t *gt);

    void setName(const string &name);

    pthread_t gameThread;

private:
    int socket1, socket2;
    string name;

};


#endif //SERVER_NETWORKGAME_H
