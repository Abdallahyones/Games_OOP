cmake_minimum_required(VERSION 3.26)
project(AI)

set(CMAKE_CXX_STANDARD 20)

add_executable(AI
        SmartPlayer.cpp
        TicTacToeApp.cpp
        GameManager.cpp
        Player.cpp
        RandomPlayer.cpp
        TicTacToePlayer.cpp)
