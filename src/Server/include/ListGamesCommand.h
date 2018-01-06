//
// Created by Yahel Ben ishay on 1/3/18.
//

#ifndef SERVER_LISTGAMESCOMMAND_H
#define SERVER_LISTGAMESCOMMAND_H


#include "Command.h"
#include "NetworkGame.h"
#include <map>

class ListGamesCommand: public Command {
public:
    ListGamesCommand(map<string, NetworkGame> &gamesList) {}
    virtual void execute(vector<string> args, pthread_t threadId, int socket = 0);
private:
    void ListGames();
    map<string, NetworkGame> gamesMap;
};

#endif //SERVER_LISTGAMESCOMMAND_H
