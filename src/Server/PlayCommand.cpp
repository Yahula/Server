//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include <iostream>
#include "include/PlayCommand.h"
#include "include/NetworkGame.h"

PlayCommand::PlayCommand(vector<NetworkGame *> *gamesList) {
    this->gamesList = gamesList;
}

void PlayCommand::execute(vector<string> args, pthread_t threadId, int socket) {
    int game;
    for (int i = 0; i < gamesList->size(); i++) {
        int e = pthread_equal(*gamesList->at(i)->getGameThread(), threadId);
        if (e){
            game = i;
            break;
        }
    }
    int blckSock = gamesList->at(game)->getSocket1();
    int witSock = gamesList->at(game)->getSocket2();
    char msg1[10];
    const char *move = args[0].c_str();
    strcpy(msg1, move);//the played move
    char msg2[] = "Waiting for second player to play...";

    if (blckSock == socket) {//black player made the move, we send the move to white
        int w = write(witSock, msg1, strlen(msg1));
        if (w == -1) {
            std::cout << "Error writing to client" << std::endl;
            return;
        }
        w = write(blckSock, msg2, strlen(msg2));//black needs to wait
        if (w == -1) {
            std::cout << "Error writing to client" << std::endl;
            return;
        }
    } else { //white player made the move
        int w = write(witSock, msg2, strlen(msg2));
        if (w == -1) {
            std::cout << "Error writing to client" << std::endl;
            return;
        }
        w = write(blckSock, msg1, strlen(msg1));//black needs to wait
        if (w == -1) {
            std::cout << "Error writing to client" << std::endl;
            return;
        }
    }
}