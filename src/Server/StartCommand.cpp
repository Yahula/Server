//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include "include/StartCommand.h"

StartCommand::StartCommand(map<string, pthread_t *> &gamesMap) : gamesMap(gamesMap) {}

void StartCommand::execute(vector <string> args, pthread_t threadId, int socket) {
    gamesMap[args[0]] = &threadId;


}

void StartCommand::start() {

}

