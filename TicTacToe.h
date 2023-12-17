#ifndef X_0_TICTACTOEBOARD_H
#define X_0_TICTACTOEBOARD_H
#include "BoardGame_Classes.hpp"


class TicTacToePlayer : public Player{
public:
    void get_move(int &x, int &y);
    TicTacToePlayer(int o, char symbol); // Order and the selected symbol
};

class TicTacToeBoard : public Board{
public:
    TicTacToeBoard();
    bool isValid(int& x, int& y);
    bool update_board (int x, int y, char symbol);
    void display_board();
    bool is_winner();
    bool is_draw();
    bool game_is_over();
    int CalcPoints();
};


#endif //X_0_TICTACTOEBOARD_H
