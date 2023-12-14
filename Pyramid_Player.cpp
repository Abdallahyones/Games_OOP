#include "Pyramid_Player.h"
pyramid_Player::pyramid_Player(char symbol) : Player(symbol){}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
pyramid_Player::pyramid_Player(int order, char symbol) : Player(order , symbol){}


void pyramid_Player ::get_move(int &x, int &y ) {
    cout << "\nPlease enter your row (0 - 2) and column (0 - 2 * row + 1) separated by spaces: ";
    cin >> x >> y ;
}