#include "randomplayer.h"

RandomPlayer::RandomPlayer (char symbol, int dimension, int dimension2 = 0):Player(symbol)
{
    this->dimension = dimension;
    if (!dimension2){
        dimension2 = dimension;
    }
    this->dimension2 = dimension2;
    this->name = "Random Computer Player";
}

// Generate a random move
void RandomPlayer::get_move (int& x, int& y, std::string code) {
    x = (int) (rand()/(RAND_MAX + 1.0) * dimension2);
    y = (int) (rand()/(RAND_MAX + 1.0) * dimension);
}
