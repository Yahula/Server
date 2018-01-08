//
// Created by sagi shaashua on 08/01/2018.
//

#ifndef SERVER_CLIENTINFO_H
#define SERVER_CLIENTINFO_H

#include <pthread.h>
#include <iostream>

using namespace std;

class ClientsInformation {

public:
    ClientsInformation(int socket, pthread_t* id);
    ClientsInformation(int socket);




    int getsocket();
    int getsocket2();
    pthread_t* getthread();

    void setThread(pthread_t *id);
    void setsocket2(int s);
    pthread_t threadId;

private:
    int socket;
    int socket2;



};


#endif //SERVER_CLIENTINFO_H
