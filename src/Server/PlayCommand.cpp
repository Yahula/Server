//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include "include/PlayCommand.h"
#include "include/NetworkGame.h"

PlayCommand::PlayCommand(vector<NetworkGame *> *gamesList) {
    this->gamesList = gamesList;
}

void PlayCommand::execute(vector<string> args, pthread_t threadId, int socket) {
    int game;
    for(int i =0; i< gamesList->size() ; i++ ){
        if (gamesList->at(i)->getGameThread()==&threadId) {
            game = i;
            break;
        }
    }
}

void PlayCommand::play() {

}