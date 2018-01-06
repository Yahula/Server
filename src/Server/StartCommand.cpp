//
// Created by Yahel Ben ishay on 1/4/18.
//


#include "include/StartCommand.h"


StartCommand::StartCommand(map<string, pthread_t *> &gamesMap) : gamesMap(gamesMap) {}

void StartCommand::execute(vector <string> args, pthread_t threadId, int socket) {
    gamesMap[args[0]] = new NetworkGame(args[0], &threadId, socket);
    char msg[] = "Wait for remote player to join...";
    int w = write(socket, msg, strlen(msg));
    if (w == -1) {
        std::cout << "Error writing to client" << std::endl;
        return;
    }
}

void StartCommand::start() {

}

