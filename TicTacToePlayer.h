#include "BoardGame_Classes.hpp"

class TicTacToePlayer : public Player{
public:
    void get_move(int& x, int& y);
    TicTacToePlayer(int o, char symbol); // Order and the selected symbol
};