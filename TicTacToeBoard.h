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
    bool game_is_over();
    int CalcPoints();
};

class TicTacToe_AI_Player : public Player {
public:
    Board* board;
    TicTacToe_AI_Player(char symbol , Board* PB);
    int MinMax(char**& board, int depth, int alpha, int beta, bool maximizingPlayer);
    int evalBoard(char player);
    bool isWinner(char** board, char player);
    int BestMove();
    // Random Moves.
    void get_move(int& x, int& y);
    void get_x(int &x , int& y);
};

#endif //X_0_TICTACTOEBOARD_H