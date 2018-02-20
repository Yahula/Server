//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include "include/CloseCommand.h"

void CloseCommand::execute(vector<string> args, NetworkGame *gameInfo) {

    for (std::vector<NetworkGame>::iterator it = gamesList->begin(); it != gamesList->end(); ++it) {
        if (it->getName() == gameInfo->getName()) {
            close(it->getSocket1());
            close(it->getSocket2());
            gamesList->erase(it);
            pthread_exit(pthread_self());
        }
    }
}

CloseCommand::CloseCommand(vector<NetworkGame> *gamesL) {
    gamesList = gamesL;
}