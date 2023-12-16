#include "BoardGame_Classes.hpp"

class TicTacToePlayer : public Player{
public:
    void initialize_move(int& a, int& b);
    TicTacToePlayer(int o, char symbol); // Order and the selected symbol
};