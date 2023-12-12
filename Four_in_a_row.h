//
// Created by Abdullah Mohamed on 12/12/2023.
//

#ifndef ASSIGNMENT3_FOUR_IN_A_ROW_H
#define ASSIGNMENT3_FOUR_IN_A_ROW_H

#include <iostream>
#include "BoardGame_Classes.hpp"

class Four_Board : public Board{
private:
    int n_column[7] = {0,0,0,0,0,0,0};
public:
    Four_Board();
    bool isvalid(int x , int y);
    bool horizontally(int x , int y);
    bool vertically (int x , int y);
    bool diagonally(int x  , int y);
    void get_x(int &x , int& y );

    bool update_board (int x, int y, char mark);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

class Four_Player : public Player{
public:
    Four_Player (char symbol);
    Four_Player (int order, char symbol);
    void get_move(int &x, int &y);
};

#endif //ASSIGNMENT3_FOUR_IN_A_ROW_H
