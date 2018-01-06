//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include <iostream>
#include "include/ListGamesCommand.h"

void ListGamesCommand::execute(vector<string> args, pthread_t threadId, int socket) {


    gamesMap[args[0]] = &threadId;
    char msg[] = "Wait for remote player to connect...";
    int w = write(socket, msg, strlen(msg));
    if (w == -1) {
        std::cout << "Error writing to client" << std::endl;
        return;
    }

}

void ListGamesCommand::ListGames() {

}