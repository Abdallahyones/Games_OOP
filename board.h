#ifndef BOARD_H
#define BOARD_H

class Board {
protected:
    int n_rows, n_cols;
    int  n_moves = 0;

public:
    char** board;
    // Return true  if move is valid and put it on board
    // within board boundaries in empty cell
    // Return false otherwise
    virtual bool update_board (int x, int y, char symbol) = 0;
    // Returns true if there is any winner
    // either X or O
    // Written in a complex way. DO NOT DO LIKE THIS.
    virtual bool is_winner() = 0;
    // Return true if all moves are done and no winner
    virtual bool is_draw() = 0;
    // Display the board and the pieces on it
    //virtual void display_board() = 0;
    // Return true if game is over
    virtual bool game_is_over() = 0;
};

#endif // BOARD_H
