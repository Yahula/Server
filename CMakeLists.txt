cmake_minimum_required(VERSION 3.6)
project(Server)

set(CMAKE_CXX_FLAGS "-pthread")

#FIND_PACKAGE(Threads)


#set(H_FILES src/Server/include/ReversiServer.h src/Server/include/Command.h src/Server/include/CommandsManager.h src/Server/include/StartCommand.h src/Server/include/GamesManager.h)
#set(SOURCE_FILES src/Server/main.cpp src/Server/ReversiServer.cpp src/Server/CommandManager.cpp src/Server/StartCommand.cpp src/Server/JoinCommand.cpp src/Server/ListGamesCommand.cpp src/Server/PlayCommand.cpp src/Server/CloseCommand.cpp src/Server/GamesManager.cpp)

set(H_FILES src/Server/include/ReversiServer.h src/Server/include/Command.h src/Server/include/CommandsManager.h src/Server/include/StartCommand.h src/Server/include/ListGamesCommand.h src/Server/include/NetworkGame.h src/Server/include/JoinCommand.h src/Server/include/PlayCommand.h)
set(SOURCE_FILES src/Server/main.cpp src/Server/ReversiServer.cpp src/Server/CommandManager.cpp src/Server/StartCommand.cpp src/Server/ListGamesCommand.cpp src/Server/NetworkGame.cpp src/Server/JoinCommand.cpp src/Server/PlayCommand.cpp)


add_executable(Server ${SOURCE_FILES} ${H_FILES})

#TARGET_LINK_LIBRARIES(Server ${CMAKE_THREAD_LIBS_INIT})
