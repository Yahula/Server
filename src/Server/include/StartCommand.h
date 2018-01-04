//
// Created by Yahel Ben ishay on 1/3/18.
//

#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H


#include "Command.h"

class StartCommand: public Command {
public:
    StartCommand() {}
    void execute(vector<string> args, int socket = 0);
private:
    void start();
};



#endif //SERVER_STARTCOMMAND_H
