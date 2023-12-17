//
// Created by dell on 12/12/2023.
//

#include "Connect_Four.h"

Four_Player::Four_Player(char symbol) : Player(symbol){}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Four_Player::Four_Player(int order, char symbol) : Player(order , symbol){}


void Four_Player ::get_move(int &x, int &y ) {
    cout << "\nPlease enter your number column (0 to 6) separated by spaces: ";
    cin >> y ;
    x = 5 ;
}
