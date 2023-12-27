#ifndef CONNECTBOARD_H
#define CONNECTBOARD_H

#include "board.h"

class connectboard : public Board
{
private:
    int n_column[7] = {0,0,0,0,0,0,0};
public:
    connectboard();
    bool isvalid(int x , int y);
    bool horizontally(int x , int y);
    bool vertically (int x , int y);
    bool diagonally(int x  , int y);
    void get_x(int &x , int& y );

    bool update_board (int x, int y, char mark);
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

#endif // CONNECTBOARD_H
