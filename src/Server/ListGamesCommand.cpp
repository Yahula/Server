//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include <iostream>
#include "include/ListGamesCommand.h"


ListGamesCommand::ListGamesCommand(vector<NetworkGame *> *gamesList) {
    this->gamesList = gamesList;
}

void ListGamesCommand::execute(vector<string> args, pthread_t threadId, int socket) {
    string s;

    for(int i =0; i< gamesList->size() ; i++ ){
        s.append(gamesList->at(i)->getName());
        s.append(" \n");
    }
    int w = write(socket, &s, s.length());
    if (w == -1) {
        std::cout << "Error writing to client" << std::endl;
        return;
    }
    char msg[] = "END_LIST";
    w = write(socket, msg, strlen(msg));
    if (w == -1) {
        std::cout << "Error writing to client" << std::endl;
        return;
    }
}



