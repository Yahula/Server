//
// Created by sagi shaashua on 07/12/2017.
//

#include "./include/ReversiServer.h"


#define MAX_CONNECTED_CLIENTS 10
#define MAX_COMMAND_LEN 50


static void *acceptClients(void *);

static void *handleClient(void *);

ReversiServer::ReversiServer(int port) : port(port), serverSocket(0) {
    move = new char[10];
    move[0] = 'O';
    move[1] = 'K';
    move[2] = '.';
    noMovesCounter = 0;
    clients = new int[MAX_CONNECTED_CLIENTS];
    firstMove = true;

    std::cout << "Server" << std::endl;
}

void ReversiServer::start() {
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }

    struct sockaddr_in serverAddress;
    bzero((void *) &serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);

    if (bind(serverSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }

    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    pthread_create(&serverThreadId, NULL, &acceptClients, (void *) serverSocket);
}

static void *acceptClients(void *socket) {
    long serverSocket = (long) socket;
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;

    while (true) {
        std::cout << "Waiting for client connections..." << std::endl;

        int clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);
        if (clientSocket == -1)
            throw "Error on accept";
        std::cout << "Client connected" << std::endl;

        NetworkGame *info = new NetworkGame(clientSocket);

        struct ReversiServer::commandInfo cominf = ReversiServer::recieveCommand(clientSocket);
        CommandsManager::getInstance()->executeCommand(cominf.command, cominf.args, info);
        if (info->getSocket2() != -1) {
            pthread_create(&info->gameThread, NULL, &handleClient, info);
        }
    }
}

static void *handleClient(void *info) {
    NetworkGame *gameInfo = (NetworkGame *) info;
    int turn = 1;
    while (true) {
        if (turn == 1) {
            struct ReversiServer::commandInfo cominf = ReversiServer::recieveCommand(gameInfo->getSocket1());
            CommandsManager::getInstance()->executeCommand(cominf.command, cominf.args, gameInfo);
            if (!cominf.command.compare("close")) {
                break;
            }
            turn = 2;
        } else if (turn == 2) {
            struct ReversiServer::commandInfo cominf = ReversiServer::recieveCommand(gameInfo->getSocket2());
            CommandsManager::getInstance()->executeCommand(cominf.command, cominf.args, gameInfo);
            if (!cominf.command.compare("close")) {
                break;
            }
            turn = 1;
        }
    }
    pthread_exit(NULL);
    return NULL;
}

ReversiServer::commandInfo ReversiServer::recieveCommand(int socket) {
    struct ReversiServer::commandInfo info;

    char commandStr[MAX_COMMAND_LEN] = "\0";
    // Read the command from the socket
    int n = read(socket, commandStr, MAX_COMMAND_LEN);
    if (n == -1) {
        cout << "Error reading command" << endl;
        return info;
    }
    cout << "Received command: " << commandStr << endl;
    // Split the command string to the command name and the arguments
    string str(commandStr);
    istringstream iss(str);
    iss >> info.command;
    while (iss) {
        string arg;
        iss >> arg;
        info.args.push_back(arg);
    }
    return info;
}

/**
 * closes the socket.
 */
void ReversiServer::stop() {
    vector<NetworkGame> games = CommandsManager::getInstance()->getGamesList();
    for (std::vector<NetworkGame>::iterator it = games.begin(); it != games.end(); ++it) {
        close(it->getSocket1());
        if (it->getSocket2() != -1) {
            close(it->getSocket2());
        }
    }
    CommandsManager::getInstance()->deleteCommandManager();
    pthread_cancel(serverThreadId);
    close(serverSocket);
    cout << "Server stopped" << endl;
}
