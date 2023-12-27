#include "largeboard.h"

// Setting Board
largeboard::largeboard(){
    n_rows = 5;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; ++i) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; ++j) {
            board[i][j] = 0;
        }
    }
}
// Validation
bool largeboard::isValid(int &x, int &y){
    if (x < 0 || y < 0)
        return false;
    if(board[x][y] == 0 && 0 <= x <= n_rows-1 && 0 <= y <= n_cols-1){
        return true;
    }
    return false;
}

// Winner Check
int player1 = true;
int play = 0;
bool largeboard::is_winner(){
    if (!game_is_over()){
        return false;
    }
    if (play == 1 && player1){
        return true;
    }
    if (play == 2 && !player1){
        return true;
    }
    player1 = false;
    return false;
}

int largeboard::CalcPoints(){
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

    //Set Last Char
    for (int i = 0; i < n_rows; i++) {
        for (int j = 0; j < n_cols; j++) {
            if (board[i][j] == 0)
                board[i][j] = 'O';
        }
    }
    if(o_points > x_points) return 2;
    else if(o_points < x_points) return 1;
    else return 0;
}

bool largeboard::update_board(int x, int y, char symbol){
    // Checking if cell is empty and inside the board
    if (!isValid(x,y))
        return false;
    if(board[x][y] == 0 && 0 <= x <= n_rows-1 && 0 <= y <= n_cols-1){
        n_moves++;
        board[x][y] = symbol;
        return true;
    }
    return false;
}

bool largeboard::is_draw(){
    if(n_moves != n_rows * n_cols || play){
        return false;
    }
    return true;
}


// Game Over Check
bool largeboard::game_is_over(){
    if (n_moves == 25){
        play = CalcPoints();
        return true;
    }
    return false;
}


