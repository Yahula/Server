//
// Created by Yahel Ben ishay on 1/3/18.
//

#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H


#include "Command.h"
#include "NetworkGame.h"

class JoinCommand: public Command {
public:
    JoinCommand(vector<NetworkGame *> *gamesList);
    void execute(vector<string> args, pthread_t threadId, int socket = 0);
private:
    void join();
    vector<NetworkGame *> *gamesList;
};

#endif //SERVER_JOINCOMMAND_H
