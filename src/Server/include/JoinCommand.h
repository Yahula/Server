//
// Created by Yahel Ben ishay on 1/3/18.
//

#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H


#include "Command.h"

class JoinCommand: public Command {
public:
    JoinCommand() {}
    void execute(vector<string> args, int socket = 0);
private:
    void join();
};

#endif //SERVER_JOINCOMMAND_H
