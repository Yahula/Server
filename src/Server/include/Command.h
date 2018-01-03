//
// Created by Yahel Ben ishay on 1/1/18.
//

#ifndef SERVER_COMMAND_H_H
#define SERVER_COMMAND_H_H

#endif //SERVER_COMMAND_H_H

#include <vector>
#include <string>
#include <pthread.h>

using namespace std;

class Command {
public:
    virtual void execute(vector<string> args, int socket = 0) = 0;
    virtual ~Command() {}
};