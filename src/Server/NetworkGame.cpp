//
// Created by sagi shaashua on 06/01/2018.
//

#include "include/NetworkGame.h"

/**
 * constructor
 * @param n the name of the game
 * @param threadId the thread the game is in.
 * @param socket the first players socket.
 */
NetworkGame::NetworkGame(string n , pthread_t* threadId , int socket) {
    name = n;
    gameThread = threadId;
    socket1 = socket;

}

NetworkGame::~NetworkGame() {
}

pthread_t *NetworkGame::getGameThread(){
    return gameThread;
}

int NetworkGame::getSocket1(){
    return socket1;
}

int NetworkGame::getSocket2(){
    return socket2;
}

void NetworkGame::addSecoundPlayer(int s){
    socket2 = s;
}

string NetworkGame::getName(){
    return name;
}
