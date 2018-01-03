//
// Created by Yahel Ben ishay on 1/1/18.
//

#include <map>
#include "Command.h"

#ifndef SERVER_COMMANDSMANAGER_H
#define SERVER_COMMANDSMANAGER_H

#endif //SERVER_COMMANDSMANAGER_H

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