//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include <iostream>
#include "./include/JoinCommand.h"
#include <mutex>


#define MAX_GAME_NAME 50

std::mutex mtx;

JoinCommand::JoinCommand(vector<NetworkGame> *gamesList) {
    this->gamesList = gamesList;
}

void JoinCommand::execute(vector<string> args, NetworkGame *cio) {
// writes the list of games
    string s;
    mtx.lock();

    for (int i = 0; i < gamesList->size(); i++) {
        if(gamesList->at(i).getSocket2()==-1) {
            s = s + gamesList->at(i).getName() + " ";
        }
    }
    int w = write(cio->getSocket1(), &s, s.length());
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
    int temp = 0;
        int n = read(cio->getSocket1(), gameName, MAX_GAME_NAME);
        if (n == -1) {
            std::cout << "Error writing to client" << std::endl;
            return;
        }

    int game;

    //adds the second socket to the network game
    for (int i = 0; i < gamesList->size(); i++) {
        string s = gamesList->at(i).getName();
        string name(gameName);
        if (!s.compare(name)) {
            gamesList->at(i).addSecoundPlayer(cio->getSocket1());
            mtx.unlock();
            game = i;
            break;
        }
    }

    *cio = *&gamesList->at(game);

    int blckSock = gamesList->at(game).getSocket1();
    int witSock = gamesList->at(game).getSocket2();

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
