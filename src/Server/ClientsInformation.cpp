//
// Created by sagi shaashua on 08/01/2018.
//

#include "include/ClientsInformation.h"

//ClientsInformation::ClientsInformation(int socket, pthread_t* id) {
//    this->socket = socket;
//    threadId = id;
//    socket2 = -1;
//}

ClientsInformation::ClientsInformation(int socket) {
    //threadId = NULL;
    socket2 = -1;
    this->socket = socket;
}

int ClientsInformation::getsocket() {
    return socket;
}

int ClientsInformation::getsocket2() {
    return socket2;
}

pthread_t* ClientsInformation::getthread() {
    return &threadId;
}

void ClientsInformation::setsocket2(int s) {
    socket2 = s;
}


//void ClientsInformation::setThread(pthread_t *id) {
//    threadId = id;
//
//}


