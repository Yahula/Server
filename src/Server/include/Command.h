//
// Created by Yahel Ben ishay on 1/1/18.
//

#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H


#include <vector>
#include <string>
#include <pthread.h>
#include "unistd.h"
#include "NetworkGame.h"

using namespace std;

class Command {
public:
    virtual void execute(vector<string> args,  NetworkGame *cio) = 0;
    virtual ~Command() {}

   // NetworkGame *clio;

protected:


};

#endif //SERVER_COMMAND_H
