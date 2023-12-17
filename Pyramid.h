//
// Created by Eyad Ahmed on 13/12/2023.
//

#ifndef ASSIGNMENT3_PYRAMID_BOARD_H
#define ASSIGNMENT3_PYRAMID_BOARD_H

#include "BoardGame_Classes.hpp"


class pyramid_Player : public Player {
public:
    pyramid_Player (char symbol);
    pyramid_Player (int order, char symbol);
    void get_move(int &x, int &y);
};


class Pyramid_Board : public Board {
protected:

public:
    Pyramid_Board();
    bool isValid(int &x, int &y);
    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    void toBoardDimentions(int &x, int &y);
};
#endif

