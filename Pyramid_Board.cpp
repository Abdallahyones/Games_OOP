#include "./Pyramid_Board.h"

// Set the board
Pyramid_Board::Pyramid_Board() {
    n_rows = 3;
    n_cols = 5;
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board [i] = new char[2 * i + 1];
        for (int j = 0; j < 2 * i + 1; j++){
            board[i][j] = '#';
        }
    }
}

//Check if Valid Move
bool Pyramid_Board::isValid(int &x, int &y){
    if (y < 0){
        return false;
    }

    switch (x){
    case 0:
        return y == 0;
    case 1:
        return y < 3;
    default:
        return y < 5;
    }
}

//Check if Winner
bool Pyramid_Board::is_winner(){
    //Check Column (1)
    bool column = board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[2][2] != '#';
    if (column){
        return true;
    }

    //Check Diagonals (2)
    bool diagonal_right = board[0][0] == board[1][2] && board[1][2] == board[2][4] && board[2][4] != '#';
    bool diagonal_left = board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[2][0] != '#';
    if (diagonal_left || diagonal_right){
        return true;
    }

    //Check Rows (4)
    bool row_middle = board[1][0] == board[1][1] && board[1][1] == board[1][2] && board[1][2] != '#';
    if (row_middle){
        return true;
    }
    bool row_bottom = false;
    for (int i = 0; i < n_cols / 2 + 1; i++){
        row_bottom = row_bottom || ( board[2][i] == board[2][i + 1] && board[2][i + 1] == board[2][i + 2] && board[2][i + 2] != '#');
    }
    return row_bottom;
}

//Check for Draw and Game is Over
bool Pyramid_Board::is_draw() {
    return (n_moves == 9 && !is_winner());
}
bool Pyramid_Board::game_is_over () {
    return n_moves >= 9;
}

//Convert Row Column Input to Board
void Pyramid_Board::toBoardDimentions(int &x, int &y){
    int row_size = x * 2 + 1;
    int maxnum = (n_cols - row_size) / 2;
    y -= maxnum;
}

//Update Board
bool Pyramid_Board::update_board(int x, int y, char mark){
    // Only update if move is valid
    toBoardDimentions(x,y);
    if (isValid(x, y) && (board[x][y] == '#')) {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else{
        return false;
    }

}

// Display the board and the pieces on it
void Pyramid_Board::display_board() {
    cout << "R" << endl;
    for (int i = 0 ; i < n_rows ; i++ ) {
        cout << i << " ";
        int row_size = i * 2 + 1;
        int max_row = n_cols * 2;

        string row;
        for (int j = 0; j < max_row; j++){
            row.push_back(' ');
        }
        int k = 0;
        for (int j = 0; j < row_size; j++){
            int pos = (max_row / 2) - row_size + k;
            row[pos] = board[i][j];
            k += 2;
        }

    cout << row << endl;
    }
    cout << "C 0 1 2 3 4" << endl;
}