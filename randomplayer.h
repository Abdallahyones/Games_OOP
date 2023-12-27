#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H
#include "player.h"
class RandomPlayer: public Player {
protected:
    int dimension;
    int dimension2;
public:
    // Take a symbol and pass it to parent
    RandomPlayer (char symbol, int dimension, int dimension2);
    // Generate a random move
    void get_move(int& x, int& y, std::string code);
};

#endif // RANDOMPLAYER_H
