//
// Created by Yahel Ben ishay on 1/1/18.
//

#ifndef SERVER_COMMANDSMANAGER_H
#define SERVER_COMMANDSMANAGER_H

#include <map>
#include "StartCommand.h"
#include "ListGamesCommand.h"
#include "JoinCommand.h"
#include "PlayCommand.h"
#include "CloseCommand.h"

class CommandsManager {
public:
    static CommandsManager* getInstance();
    void executeCommand(string command, vector<string> args, int socket = 0);
private:
    // A singleton
    CommandsManager();
    CommandsManager(const CommandsManager &);
    ~CommandsManager();
    static CommandsManager* instance;
    static pthread_mutex_t lock;
    map<string, Command *> commandsMap;
};

#endif //SERVER_COMMANDSMANAGER_H
