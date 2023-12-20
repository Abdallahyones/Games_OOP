#include "BoardGame_Classes.hpp"
#include "Connect_Four.h"

using namespace std ;

Four_AI_Player :: Four_AI_Player(char symbol , Board*& bPtr): Player(symbol) {
    board = bPtr ;
    this->name = "AI Computer Player";
    cout << "My names is " << name << endl;
}

void Four_AI_Player::get_move(int &x, int &y) {
    y =  TheBestMove();
    get_x(x , y);
}

void Four_AI_Player :: get_x(int &x , int& y){
    // x = 5
    while (~x && y < 7 && this->board->board[x][y] != '#'){
        x--;
    }
}

int Four_AI_Player ::TheBestMove() {
    char **board =this->board->board;
    int bestMove = -1 , bestVal = INT_MIN , val ;
    for(int y = 0 ; y < 7 ; y++){
        int x = 5 ;
        get_x(x , y);
        if (~x && x < 6) {
            board[x][y] = this->symbol;
            val = MinMax(this->board->board, 4, INT_MIN, INT_MAX, false);
            board[x][y] = '#';
            if (bestVal < val)
                bestVal = val , bestMove = y ;
        }
    }
    return bestMove ;
}


int Four_AI_Player ::  MinMax(char**& board, int depth, int alpha, int beta, bool who ) {
    if (depth == 0 || isWinner(board, 'O') || isWinner(board, 'X')) {
        return evaluateBoard(symbol);
    }
    if (who) {
        int maxEval = INT_MIN;
        for (int y = 0; y < 7; ++y) {
            int x = 5 ;
            get_x(x , y );
            if (~x ) {
                board[x][y] = symbol;
                int eval = MinMax(board, depth - 1, alpha, beta, false );
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
        for (int y = 0; y < 7; ++y) {
            int x = 5 ;
            get_x(x , y);
            if (~x ) {
                board[x][y] = 'X';
                int eval = MinMax(board, depth - 1, alpha, beta, true );
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
int Four_AI_Player :: evaluateBoard( char player) {
    if (isWinner(board->board, 'O')) {
        return (player == 'O') ? 1 : -1;
    } else if (isWinner(board->board, 'X')) {
        return (player == 'X') ? 1 : -1;
    }
    return 0;
}

bool Four_AI_Player::isWinner(char**board, char player){
    // Check horizontally
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j <= 7 - 4; ++j) {
            if (board[i][j] == player &&
                board[i][j + 1] == player &&
                board[i][j + 2] == player &&
                board[i][j + 3] == player) {
                return true;
            }
        }
    }
    // Check vertically
    for (int i = 0; i <= 6 - 4; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (board[i][j] == player &&
                board[i + 1][j] == player &&
                board[i + 2][j] == player &&
                board[i + 3][j] == player) {
                return true;
            }
        }
    }

    // Check diagonally (positive slope)
    for (int i = 0; i <= 6 - 4; ++i) {
        for (int j = 0; j <= 7 - 4; ++j) {
            if (board[i][j] == player &&
                board[i + 1][j + 1] == player &&
                board[i + 2][j + 2] == player &&
                board[i + 3][j + 3] == player) {
                return true;
            }
        }
    }

    // Check diagonally (negative slope)
    for (int i = 3; i < 6; ++i) {
        for (int j = 0; j <= 7 - 4; ++j) {
            if (board[i][j] == player &&
                board[i - 1][j + 1] == player &&
                board[i - 2][j + 2] == player &&
                board[i - 3][j + 3] == player) {
                return true;
            }
        }
    }
    return false;
}