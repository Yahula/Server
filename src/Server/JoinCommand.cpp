//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include <iostream>
#include "./include/JoinCommand.h"

JoinCommand::JoinCommand(vector<NetworkGame *> *gamesList) {
    this->gamesList = gamesList;
}

void JoinCommand::execute(vector<string> args, ClientsInformation *cio) {
    pthread_join(*cio->getthread(),NULL);
    int game;
    for(int i =0; i< gamesList->size() ; i++ ){
        string s = gamesList->at(i)->getName();
        string name(args[0]);
        if (!s.compare(name)){
            gamesList->at(i)->addSecoundPlayer(cio->getsocket());
            game = i;
            break;
        }
    }
    int blckSock = gamesList->at(game)->getSocket1();
    int witSock = gamesList->at(game)->getSocket2();

    char msg1[] = "Remote player has joined the game! we are ready to roll :) \nYou are the black (X) player, you play first! \n";
    int w = write(blckSock, msg1, strlen(msg1));
    if (w == -1) {
        std::cout << "Error writing to client" << std::endl;
        return;
    }

    char msg2[] = "You have joined the game! we are ready to roll :) \nYou are the white (O) player, you play second! \nWaiting for black player to play...";
    w = write(witSock, msg2, strlen(msg2));
    if (w == -1) {
        std::cout << "Error writing to client" << std::endl;
        return;
    }

}

void JoinCommand::join() {

}