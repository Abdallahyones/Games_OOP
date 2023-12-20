// Author:  Abdullah


#include <iostream>
#include <random>
#include <algorithm>
#include"Connect_Four.h"

using namespace std;

bool Four_Board :: isvalid(int x, int y) {
    return (x >= 0 && x < 6) && (y >= 0 && y < 7);
}
bool Four_Board ::horizontally(int x, int y) {
    if (board[x][y] == '#') return false;
    string s (4 , board[x][y]) , w = "";
    for (int i = 0 ; i < 4 ; i++){
        if (isvalid(x , y+i)) w += board[x][y+i];
    }
    return (s == w) ;
}
bool Four_Board ::vertically(int x, int y) {
    if (board[x][y] == '#') return false;
    string s (4 , board[x][y]) , w = "";
    for (int i = 0 ; i < 4 ; i++){
        if (isvalid(x+i , y)) w += board[x+i][y];
    }

    return (s == w) ;
}
bool Four_Board ::diagonally(int x, int y) {
    if (board[x][y] == '#') return false;
    string s (4 , board[x][y]) , w = "";
    for (int i = 0 ; i < 4 ; i++){
        if (isvalid(x+i , y+i)) w += board[x+i][y+i];
    }
    if (s == w){
        return true;
    }
    w = "";
    for (int i = 0 ; i < 4 ; i++){
        if (isvalid(x-i , y+i)) w += board[x-i][y+i];
    }
    return (s == w) ;
}

void Four_Board :: get_x(int &x , int& y ){
    while (~x && y < 7 && board[x][y] != '#'){
        x--;
    }
}

// Set the board
Four_Board::Four_Board () {
    n_rows = 6 ,  n_cols = 7;  // 6x7
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = '#';
    }
}

// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise

bool Four_Board::update_board (int x, int y, char mark){
    // Only update if move is valid
    x = 5 ;
    get_x(x , y);
    if (isvalid(x ,  y) && (board[x][y] == '#')) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else{
        return false;
    }

}

// Display the board and the pieces on it
void Four_Board::display_board() {
    for (int i = 0 ; i < 6 ; i++ ) {
        cout << "\n| ";
        for (int j: {0,1,2,3,4,5,6}) {
            cout << board [i][j] << " | ";
        }
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O

bool Four_Board::is_winner() {
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
bool Four_Board::is_draw() {
    return (n_moves == 42 && !is_winner());
}
bool Four_Board::game_is_over () {
    return n_moves >= 42;
}
