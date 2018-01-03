#include <iostream>

#include "./include/ReversiServer.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;


int main() {
    ifstream sconfig;
    sconfig.open("../../exe/client_config.txt");

    string p;
    getline(sconfig, p);
    int port;
    istringstream(p) >> port ;

    ReversiServer server(port);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}