//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include <iostream>
#include <sys/stat.h>
#include "include/PlayCommand.h"
#include "include/NetworkGame.h"

PlayCommand::PlayCommand(vector<NetworkGame> *gamesList) {
    this->gamesList = gamesList;
}

void PlayCommand::execute(vector<string> args, NetworkGame *gameInfo) {
    int game;

    cout<<"args0:"<<args[0]<<" args1:"<<args[1]<<" args2:"<<args[2]<<endl;

    for (int i = 0; i < gamesList->size(); i++) {
        if (gamesList->at(i).getName() == gameInfo->getName()){
            game = i;
            break;
        }
    }
    int blckSock = gamesList->at(game).getSocket1();
    int witSock = gamesList->at(game).getSocket2();

    char msg1[10];
    const char *move = args[0].c_str();
    strcpy(msg1, move);//the played move
    char msg2[] = "Waiting for second player to play...";

    string player = args[1];

    cout<<"player: "<<player<<endl;

    if (!player.compare("-1")) { //black player made the move
        int w = write(witSock, msg1, strlen(msg1));
        if (w == -1) {
            std::cout << "Error writing to client" << std::endl;
            return;
        }
        cout << "Wrote to white: " << msg1;

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
        w = write(blckSock, msg1, strlen(msg1));//white needs to wait
        if (w == -1) {
            std::cout << "Error writing to client" << std::endl;
            return;
        }
    }
}