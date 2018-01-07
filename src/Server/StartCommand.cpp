//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include <iostream>
#include "include/StartCommand.h"


StartCommand::StartCommand(vector<NetworkGame *> *gamesList){
    this->gamesList = gamesList;
}

void StartCommand::execute(vector <string> args, pthread_t threadId, int socket) {
    gamesList->push_back(new NetworkGame(args[0], &threadId, socket));
    gamesList->push_back(new NetworkGame("check", &threadId, socket));
    char msg[] = "Waiting for remote player to join...";
    int w = write(socket, msg, strlen(msg));
    if (w == -1) {
        std::cout << "Error writing to client" << std::endl;
        return;
    }
}

void StartCommand::start() {

}

