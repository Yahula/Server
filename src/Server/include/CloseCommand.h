//
// Created by Yahel Ben ishay on 1/3/18.
//

#ifndef SERVER_CLOSECOMMAND_H
#define SERVER_CLOSECOMMAND_H


#include "Command.h"

class CloseCommand : public Command {
public:
    CloseCommand(vector<NetworkGame> *gamesList);

    void execute(vector<string> args, NetworkGame *gameInfo);

private:
    vector<NetworkGame> *gamesList;
};

#endif //SERVER_CLOSECOMMAND_H
