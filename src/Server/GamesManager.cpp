//
// Created by Yahel Ben ishay on 1/4/18.
//

#include "./include/GamesManager.h"

GamesManager::GamesManager() {
    ifstream sconfig;
    sconfig.open("../../exe/client_config.txt");

    string p;
    getline(sconfig, p);
    int port;
    istringstream(p) >> port ;

    server = new ReversiServer(port);
    try {
        server->start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }

}
