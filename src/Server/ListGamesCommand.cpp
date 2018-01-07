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

    for(int i =0; i< gamesList->size() ; i++ ){
        string s = gamesList->at(i)->getName();
        int w = write(socket, &s, s.size());
        if (w == -1) {
            std::cout << "Error writing to client" << std::endl;
            return;
        }
    }
    cout<< gamesList->at(0)->getName() <<endl;
    char msg[] = "END_LIST";
    int w = write(socket, msg, strlen(msg));
    if (w == -1) {
        std::cout << "Error writing to client" << std::endl;
        return;
    }


}



