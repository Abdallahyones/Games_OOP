#include <iostream>
#include "TicTacToePlayer.h"

TicTacToePlayer::TicTacToePlayer(int o, char symbol) : Player(o, symbol){}

void TicTacToePlayer::get_move(int &x, int &y){
    cout << "\n Please enter your move's coordinates (a and b): ";
    cin >> x >> y;
}