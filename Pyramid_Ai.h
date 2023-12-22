#include <iostream>
#include "./Pyramid_Board.h"

class PyramidAi : public Player{
    private:
    int depth;
    char symbol;
    Board *board;
    public:
    PyramidAi(char Symbol, Board *board);
    int minMax(int depth, Board *&board, bool isCPU);
    void get_move(int &x, int &y);
};