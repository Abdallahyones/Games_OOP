#include "BoardGame_Classes.hpp"
#include "TicTacToeBoard.h"
using namespace std;

TicTacToe_AI_Player::TicTacToe_AI_Player(char symbol, Board *bPtr) : Player(symbol){
    board = bPtr;
    this->name = "AI Computer Player";
    cout << "My name is " << name << endl;
}

void TicTacToe_AI_Player::get_move(int &x, int &y) {
    y = BestMove();
    get_x(x, y);
}

void TicTacToe_AI_Player::get_x(int &x, int &y) {
    while (~x && y < 5 && this->board->board[x][y] != '#') {
        x--;
    }
}

int TicTacToe_AI_Player::BestMove() {
    char **b = this->board->board;
    int bestMove = -1, bestVal = INT_MIN, val;
    for (int y = 0; y < 5; y++) {
        int x = 4;
        get_x(x, y);
        if (~x && x < 5) {
            b[x][y] = this->symbol;
            val = MinMax(this->board->board, 4, INT_MIN, INT_MAX, false);
            b[x][y] = '#';
            if (bestVal < val)
                bestVal = val, bestMove = y;
        }
    }
    return bestMove;
}

int TicTacToe_AI_Player::MinMax(char **&board, int depth, int alpha, int beta, bool who) {
    if (depth == 0 || isWinner(board, 'O') || isWinner(board, 'X')) {
        return evalBoard(symbol);
    }
    if (who) {
        int maxEval = INT_MIN;
        for (int y = 0; y < 5; ++y) {
            int x = 4;
            get_x(x, y);
            if (~x) {
                board[x][y] = symbol;
                int eval = MinMax(board, depth - 1, alpha, beta, false);
                maxEval = max(maxEval, eval);
                alpha = max(alpha, eval);
                board[x][y] = '#';
                if (beta <= alpha)
                    break;
            }
        }
        return maxEval;
    } else {
        int minEval = INT_MAX;
        for (int y = 0; y < 5; ++y) {
            int x = 4;
            get_x(x, y);
            if (~x) {
                board[x][y] = 'X';
                int eval = MinMax(board, depth - 1, alpha, beta, true);
                minEval = min(minEval, eval);
                beta = min(beta, eval);
                board[x][y] = '#';
                if (beta <= alpha)
                    break;
            }
        }
        return minEval;
    }
}

int TicTacToe_AI_Player::evalBoard(char player) {
    if (isWinner(board->board, 'X')) {
        return (player == 'X') ? 1 : -1;
    }
    else if(isWinner(board->board, 'O')) {
        return (player == 'O') ? 1 : -1;
    }
    return 0;
}

bool TicTacToe_AI_Player::isWinner(char **b, char player) {
    // Rows
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5/2 +1; j++){
            if(b[i][j] == b[i][j+1] && b[i][j+1] == b[i][j+2]){
                return true;
            }
        }
    }
    // Columns
    for(int i = 0; i < 5/2 +1; i++){
        for(int j = 0; j < 5; j++){
            if(b[i][j] == b[i+1][j] && b[i+1][j] == b[i+2][j]){
                return true;
            }
        }
    }
    // Diagonals
    for(int i = 0; i < 5/2 +1; i++){
        for(int j = 0; j < 5/2 +1; j++){
            if(b[i][j] == b[i+1][j+1] && b[i+1][j+1] == b[i+2][j+2]){
                return true;
            }
        }
    }
    return false;
}