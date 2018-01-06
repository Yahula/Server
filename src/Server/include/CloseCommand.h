//
// Created by Yahel Ben ishay on 1/3/18.
//

#ifndef SERVER_CLOSECOMMAND_H
#define SERVER_CLOSECOMMAND_H


#include "Command.h"

class CloseCommand: public Command {
public:
    CloseCommand() {}
    void execute(vector<string> args, pthread_t threadId, int socket = 0);
private:
    void close();
};

#endif //SERVER_CLOSECOMMAND_H
