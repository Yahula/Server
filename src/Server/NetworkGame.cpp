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
//NetworkGame::NetworkGame(string n , ClientsInformation clio) {
//    name = n;
//    gameThread = NULL;
//    socket1 = clio.getsocket();
//
//}

NetworkGame::NetworkGame(int socket) {
    socket2 = -1;
    socket1= socket;
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

void NetworkGame::setThread(pthread_t *gt) {
    gameThread = gt;

}


void NetworkGame::setName(const string &name) {
    NetworkGame::name = name;
}

NetworkGame::NetworkGame(const NetworkGame &other) {
    socket1 = other.socket1;
    socket2 = other.socket2;
    name = other.name;
   // *gameThread = *other.gameThread;
}


