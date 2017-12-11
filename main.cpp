#include <iostream>

#include "ReversiServer.h"
#include <iostream>
#include <stdlib.h>
using namespace std;


int main() {
    ReversiServer server(5001);
    try {
        server.start();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}