//
// Created by Yahel Ben ishay on 1/1/18.
//

#ifndef SERVER_COMMANDSMANAGER_H
#define SERVER_COMMANDSMANAGER_H

#include <map>
#include "StartCommand.h"
#include "JoinCommand.h"
#include "PlayCommand.h"
#include "CloseCommand.h"
#include "NetworkGame.h"

class CommandsManager {
public:
    static CommandsManager* getInstance();
    void executeCommand(string command, vector<string> args, NetworkGame *cio);
    ClientsInformation *clio;

    const vector<NetworkGame, allocator<NetworkGame> > &getGamesList() const;

private:



    // A singleton
    CommandsManager();
    CommandsManager(const CommandsManager &);
    ~CommandsManager();
    static CommandsManager* instance;
    static pthread_mutex_t lock;
    map<string, Command *> commandsMap;
    vector<NetworkGame> gamesList;

};

#endif //SERVER_COMMANDSMANAGER_H
