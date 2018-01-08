//
// Created by Yahel Ben ishay on 1/1/18.
//

#include "./include/CommandsManager.h"


CommandsManager* CommandsManager::instance = 0;

pthread_mutex_t CommandsManager::lock;

CommandsManager* CommandsManager::getInstance() {
    if (instance == 0) {
        pthread_mutex_lock(&lock);
        if (instance == 0) {
            instance = new CommandsManager();
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}

CommandsManager::CommandsManager() {
    commandsMap["start"] = new StartCommand(&gamesList);
    commandsMap["list_games"] = new ListGamesCommand(&gamesList);
    commandsMap["join"] = new JoinCommand(&gamesList);
    commandsMap["play"] = new PlayCommand(&gamesList);
//    commandsMap["close"] = new CloseCommand();
}

void CommandsManager::executeCommand(string command, vector<string> args, ClientsInformation *cio) {
    Command *commandObj = commandsMap[command];
    commandObj->execute(args, cio);
}

CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}