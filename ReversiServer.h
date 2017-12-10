//
// Created by sagi shaashua on 07/12/2017.
//

#ifndef SERVER_REVERSISERVER_H
#define SERVER_REVERSISERVER_H


class ReversiServer {
public:
    ReversiServer(int port);
    void start();
    void stop();
private:
    int port;
    int serverSocket;
    char* move;
    void hendleClient(int clientServer);

};


#endif //SERVER_REVERSISERVER_H
