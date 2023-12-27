#ifndef XOBOARD_H
#define XOBOARD_H
#include "board.h"

class XOBoard :public Board {
public:
    XOBoard();
    bool update_board (int x, int y, char mark);
    bool is_winner();
    bool is_draw();
    bool game_is_over();
};

#endif // XOBOARD_H
