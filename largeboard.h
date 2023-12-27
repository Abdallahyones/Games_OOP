#ifndef LARGEBOARD_H
#define LARGEBOARD_H
#include "board.h"
class largeboard : public Board
{
public:
    largeboard();
    bool isValid(int& x, int& y);
    bool update_board (int x, int y, char symbol);
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int CalcPoints();
};

#endif // LARGEBOARD_H
