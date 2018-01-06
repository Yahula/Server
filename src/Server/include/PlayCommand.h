//
// Created by Yahel Ben ishay on 1/3/18.
//

#ifndef SERVER_PLAYCOMMAND_H
#define SERVER_PLAYCOMMAND_H


#include "Command.h"

class PlayCommand: public Command {
public:
    PlayCommand() {}
    void execute(vector<string> args, pthread_t threadId, int socket = 0);
private:
    void play();
};

#endif //SERVER_PLAYCOMMAND_H
