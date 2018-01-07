//
// Created by Yahel Ben ishay on 1/3/18.
//

#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H


#include <map>
#include "Command.h"
#include "NetworkGame.h"
#include <iostream>


class StartCommand: public Command {
public:
    StartCommand(vector<NetworkGame *> *gamesList);
    void execute(vector<string> args, pthread_t threadId, int socket = 0);
private:
    void start();
    vector<NetworkGame *> *gamesList;
};



#endif //SERVER_STARTCOMMAND_H
