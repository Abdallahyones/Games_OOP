#include "TicTacToe.h"

TicTacToePlayer::TicTacToePlayer(int o, char symbol) : Player(o, symbol){}

void TicTacToePlayer::initialize_move(int &a, int &b) {
    cout << "\n Please enter your move's coordinates (a and b): ";
    cin >> a >> b;
}