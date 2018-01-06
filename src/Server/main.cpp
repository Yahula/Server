#include <iostream>

#include "include/ReversiServer.h"
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

    ReversiServer server(5001);

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