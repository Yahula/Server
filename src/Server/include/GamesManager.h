//
// Created by Yahel Ben ishay on 1/4/18.
//

#ifndef SERVER_GAMESMANAGER_H
#define SERVER_GAMESMANAGER_H

#include "ReversiServer.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

class GamesManager{
public:
    GamesManager();

private:
    ReversiServer* server;
    vector<char*> gamesList();

};


#endif //SERVER_GAMESMANAGER_H
