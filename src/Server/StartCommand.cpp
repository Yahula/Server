//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include <iostream>
#include "include/StartCommand.h"


StartCommand::StartCommand(vector<NetworkGame> *gamesList){
    this->gamesList = gamesList;
}

void StartCommand::execute(vector <string> args, NetworkGame *cio) {
    NetworkGame netgame(cio->getSocket1());
    netgame.setName(args[0]);
    gamesList->push_back(netgame);
    char msg[] = "Waiting for remote player to join...";
    int w = write(cio->getSocket1(), msg, strlen(msg));
    if (w == -1) {
        std::cout << "Error writing to client" << std::endl;
        return;
    }

    //rights to the player that he will be first.
//    char temp = '0';
//    char* num = &temp;
//    int t = write(cio->getSocket1(), num, strlen(num));
//    if (t == -1) {
//        std::cout << "Error writing to client" << std::endl;
//        return;
//    }
}

void StartCommand::start() {}

