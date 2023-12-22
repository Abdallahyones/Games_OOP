//
// Created by Eyad Ahmed on 13/12/2023.
//

#ifndef ASSIGNMENT3_PYRAMID_BOARD_H
#define ASSIGNMENT3_PYRAMID_BOARD_H
#endif

#include <iostream>
#include "BoardGame_Classes.hpp"

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
    vector <pair<int,int>> availableSpaces();
};
