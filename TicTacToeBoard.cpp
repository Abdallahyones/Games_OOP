#include "./TicTacToeBoard.h"

// Setting Board
TicTacToeBoard::TicTacToeBoard(){
    n_rows = 5, n_cols = 5;
    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_cols; j++){
            board[i][j] = '#';
        }
    }
}
// Validation
bool TicTacToeBoard::isValid(int &x, int &y){
    if(board[x][y] == '#' && 0 <= x <= n_rows-1 && 0 <= y <= n_cols-1){
        return true;
    }
    return false;
}

// Winner Check
int player1 = true;
bool TicTacToeBoard::is_winner(){
    int play = CalcPoints();
    if (play == 1 && player1){
        return true;
    }
    if (play == 2 && !player1){
        return true;
    }
    player1 = false;
    return false;
}

int TicTacToeBoard::CalcPoints(){
    int x_points = 0, o_points = 0;
    // Rows
    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_cols/2 +1; j++){
            if(board[i][j] == board[i][j+1] && board[i][j+1] == board[i][j+2]){
                if(board[i][j] == 'O') o_points++;
                else if(board[i][j] == 'X') x_points++;
            }
        }
    }
    // Columns
    for(int i = 0; i < n_rows/2 +1; i++){
        for(int j = 0; j < n_cols; j++){
            if(board[i][j] == board[i+1][j] && board[i+1][j] == board[i+2][j]){
                if(board[i][j] == 'O') o_points++;
                else if(board[i][j] == 'X') x_points++;
            }
        }
    }
    // Diagonals
    for(int i = 0; i < n_rows/2 +1; i++){
        for(int j = 0; j < n_cols/2 +1; j++){
            if(board[i][j] == board[i+1][j+1] && board[i+1][j+1] == board[i+2][j+2]){
                if(board[i][j] == 'O') o_points++;
                else if(board[i][j] == 'X') x_points++;
            }
        }
    }
    if(o_points > x_points) return 2;
    else if(o_points < x_points) return 1;
    else return 0;
}

bool TicTacToeBoard::update_board(int x, int y, char symbol){
    // Checking if cell is empty and inside the board
    if(board[x][y] == '#' && 0 <= x <= n_rows-1 && 0 <= y <= n_cols-1){
        ++n_moves;
        board[x][y] = symbol;
        return true;
    }
    return false;
}

bool TicTacToeBoard::is_draw(){
    if(n_moves != n_rows * n_cols){
        return false;
    }
    return true;
}


// Game Over Check
bool TicTacToeBoard::game_is_over(){
    return n_moves > 24;
}

void TicTacToeBoard::display_board(){
    for(int i = 0; i < n_rows; i++){
        for(int j = 0; j < n_cols; j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
        cout << "---------" << endl;
    }
    cout << endl;
}