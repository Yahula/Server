//
// Created by Yahel Ben ishay on 1/3/18.
//

#ifndef SERVER_PLAYCOMMAND_H
#define SERVER_PLAYCOMMAND_H


#include "Command.h"
#include "NetworkGame.h"

class PlayCommand: public Command {
public:
    PlayCommand(vector<NetworkGame *> *gamesList);
    void execute(vector<string> args, ClientsInformation *cio);
private:
    void play();
    vector<NetworkGame *> *gamesList;
};

#endif //SERVER_PLAYCOMMAND_H
