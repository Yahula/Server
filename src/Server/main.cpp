#include <iostream>

#include "include/ReversiServer.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;


int main() {
    ifstream serverConfig;
    serverConfig.open("../exe/server_config.txt");
    string p;
    getline(serverConfig, p);
    int port;
    istringstream(p) >> port;

    ReversiServer server(port);

    try {
        server.start();
        cout << "Enter exit to stop server" << endl;
        string str;
        cin >> str;
        if (str == "exit")
            server.stop();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}