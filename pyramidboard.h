#ifndef PYRAMIDBOARD_H
#define PYRAMIDBOARD_H
#include "board.h"
class pyramidBoard : public Board
{
public:
    pyramidBoard();
    bool update_board (int x, int y, char mark);
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    bool isValid(int &x, int &y);
};

#endif // PYRAMIDBOARD_H
