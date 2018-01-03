cmake_minimum_required(VERSION 3.6)
project(Server)

set(CMAKE_CXX_FLAGS "-pthread")

#FIND_PACKAGE(Threads)


set(SOURCE_FILES src/Server/main.cpp src/Server/ReversiServer.cpp src/Server/include/ReversiServer.h src/Server/include/Command.h src/Server/include/CommandsManager.h src/Server/CommandManager.cpp src/Server/include/StartCommand.h)
add_executable(Server ${SOURCE_FILES})

#TARGET_LINK_LIBRARIES(Server ${CMAKE_THREAD_LIBS_INIT})
