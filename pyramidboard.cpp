#include "pyramidboard.h"

#include <iostream>
// Set the board
pyramidBoard::pyramidBoard() {
    n_rows = 3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[2 * i + 1];
        for (int j = 0; j < 2 * i + 1; j++){
            board[i][j] = 0;
        }
    }
}

//Check if Valid Move
bool pyramidBoard::isValid(int &x, int &y){
    if (y < 0 || x < 0){
        return false;
    }

    switch (x){
    case 0:
        return y == 0;
    case 1:
        return y < 3;
    default:
        return y < 5;
    }
}

//Check if Winner
bool pyramidBoard::is_winner(){
    //Check Column (1)
    bool column = board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != 0;
    if (column){
        return true;
    }

    //Check Diagonals (2)
    bool diagonal_right = board[0][0] == board[1][2] && board[1][2] == board[2][4] && board[2][4] != 0;
    bool diagonal_left = board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] != 0;
    if (diagonal_left || diagonal_right){
        return true;
    }

    //Check Rows (4)
    bool row_middle = board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] != 0;
    if (row_middle){
        return true;
    }
    bool row_bottom = false;
    for (int i = 0; i < n_cols / 2 + 1; i++){
        row_bottom = row_bottom || ( board[2][i] == board[2][i + 1] && board[2][i + 1] == board[2][i + 2] && board[2][i + 2] != 0);
    }
    return row_bottom;
}

//Check for Draw and Game is Over
bool pyramidBoard::is_draw() {
    return (n_moves == 9 && !is_winner());
}
bool pyramidBoard::game_is_over () {
    return n_moves >= 9;
}

//Update Board
bool pyramidBoard::update_board(int x, int y, char mark){
    // Only update if move is valid
    if (isValid(x, y) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else{
        return false;
    }

}


