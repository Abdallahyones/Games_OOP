#include "connectboard.h"

#include <iostream>
using namespace std;

bool connectboard :: isvalid(int x, int y) {
    return (x >= 0 && x < 6) && (y >= 0 && y < 7);
}
bool connectboard ::horizontally(int x, int y) {
    if (board[x][y] == 0) return false;
    string s (4 , board[x][y]) , w = "";
    for (int i = 0 ; i < 4 ; i++){
        if (isvalid(x , y+i)) w += board[x][y+i];
    }
    return (s == w) ;
}
bool connectboard ::vertically(int x, int y) {
    if (board[x][y] == 0) return false;
    string s (4 , board[x][y]) , w = "";
    for (int i = 0 ; i < 4 ; i++){
        if (isvalid(x+i , y)) w += board[x+i][y];
    }

    return (s == w) ;
}
bool connectboard ::diagonally(int x, int y) {
    if (board[x][y] == 0) return false;
    string s (4 , board[x][y]) , w = "";
    for (int i = 0 ; i < 4 ; i++){
        if (isvalid(x+i , y+i)) w += board[x+i][y+i];
    }

    return (s == w) ;
}

void connectboard :: get_x(int &x , int& y ){
    while (x > 0 && y < 7 && board[x-1][y] == 0){
        x--;
    }
}

// Set the board
connectboard::connectboard () {
    n_rows = 6 ,  n_cols = 7;  // 6x7
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise

bool connectboard::update_board (int x, int y, char mark){
    // Only update if move is valid
    x = 5 ;
    get_x(x , y);
    if (isvalid(x ,  y) && (board[x][y] == 0)) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else{
        return false;
    }

}



// Returns true if there is any winner
// either X or O

bool connectboard::is_winner() {
    for(int i : {0,1,2,3,4,5}){
        for (int j : {0,1,2,3,4,5,6}){
            if (horizontally(i ,j) || vertically(i ,j) || diagonally(i ,j)){
                return true;
            }
        }
    }
    return false;
}

// Return true if 42 moves are done and no winner
bool connectboard::is_draw() {
    return (n_moves == 42 && !is_winner());
}
bool connectboard::game_is_over () {
    return n_moves >= 42;
}
