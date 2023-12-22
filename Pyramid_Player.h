#include "BoardGame_Classes.hpp"

#ifndef ASSIGNMENT3_PYRAMID_PLAYER_H
#define ASSIGNMENT3_PYRAMID_PLAYER_H
#endif

class pyramid_Player : public Player {
public:
    pyramid_Player (char symbol);
    pyramid_Player (int order, char symbol);
    void get_move(int &x, int &y);
};

