//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include <iostream>
#include "./include/JoinCommand.h"
#define MAX_GAME_NAME 50

JoinCommand::JoinCommand(vector<NetworkGame *> *gamesList) {
    this->gamesList = gamesList;
}

void JoinCommand::execute(vector<string> args, ClientsInformation *cio) {
// writes the lst of games
    string s;

    for(int i =0; i< gamesList->size() ; i++ ){
        s.append(gamesList->at(i)->getName());
        s.append(" \n");
    }
    int w = write(cio->getsocket(), &s, s.length());
    if (w == -1) {
        std::cout << "Error writing to client" << std::endl;
        return;
    }
//    char msg[] = "END_LIST";
//    w = write(cio->getsocket(), msg, strlen(msg));
//    if (w == -1) {
//        std::cout << "Error writing to client" << std::endl;
//        return;
//    }

    //read game selection
    char gameName[MAX_GAME_NAME] = "\0";

    int n = read(cio->getsocket(), gameName, MAX_GAME_NAME);
    if (n == -1) {
        std::cout << "Error writing to client" << std::endl;
        return;
    }

    //adds the second socket to the network game
    int game;
    for(int i =0; i< gamesList->size() ; i++ ){
        string s = gamesList->at(i)->getName();
        string name(gameName);
        if (!s.compare(name)){
            gamesList->at(i)->addSecoundPlayer(cio->getsocket());
            game = i;
            break;
        }
    }

    cio->setsocket2(gamesList->at(game)->getSocket1());

    int blckSock = gamesList->at(game)->getSocket1();
    int witSock = gamesList->at(game)->getSocket2();

    char msg1[] = "Remote player has joined the game! we are ready to roll :) \nYou are the black (X) player, you play first! \n";
    w = write(blckSock, msg1, strlen(msg1));
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
