#include "BoardGame_Classes.hpp"

class pyramid_Player : public Player {
public:
    pyramid_Player (char symbol);
    pyramid_Player (int order, char symbol);
    void get_move(int &x, int &y);
};