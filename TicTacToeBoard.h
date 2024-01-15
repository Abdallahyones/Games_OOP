#ifndef X_0_TICTACTOEBOARD_H
#define X_0_TICTACTOEBOARD_H
#include "BoardGame_Classes.hpp"

class TicTacToeBoard : public Board{
public:
    TicTacToeBoard();
    bool isValid(int& x, int& y);
    bool update_board (int x, int y, char symbol);
    void display_board();
    bool is_winner();
    bool is_draw();
    int CalcPoints();
    bool game_is_over();
};



#endif //X_0_TICTACTOEBOARD_H
