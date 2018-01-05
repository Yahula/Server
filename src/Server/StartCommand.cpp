//
// Created by Yahel Ben ishay on 1/4/18.
//

#include <string>
#include "include/StartCommand.h"


void StartCommand::execute(vector <string> args, int socket) {
    gamesMap.insert ( pair<args,int>('a',100) );

}

void StartCommand::start() {


}

StartCommand::StartCommand(map<string, int> &gamesMap) : gamesMap(gamesMap) {}
