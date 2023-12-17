#include "Connect_Four.h"
#include "Pyramid.h"
#include "TicTacToe.h"

using namespace std;

int main()
{

    int playCPU, mode;
    Player *players[2];
    Board *board = new Pyramid_Board;

    cout << "Welcome to FCAI Games. :)\n Plesse Closse The Game\n";
    cout << "1- Pyramic Tic-Tac-Toe\n"
         << "2- Four-in-a-row\n"
         << "3- 5 x 5 Tic Tac Toe\n"
         << "4-Exit\n";

    cin >> mode;
    switch (mode){
    case 1:
        players[0] = new pyramid_Player(1, 'X');
        board = new Pyramid_Board;

        cout << "Press 1 if you want to play with computer: ";
        cin >> playCPU;

        if (playCPU != 1){
            players[1] = new pyramid_Player(2, 'O');
        }
        else{
            // Player pointer points to child
            players[1] = new RandomPlayer('O', 5, 3);
        }

        break;
    case 2:
        players[0] = new Four_Player(1, 'X');
        board = new Four_Board;

        cout << "Press 1 if you want to play with computer: ";
        cin >> playCPU;

        if (playCPU != 1){
            players[1] = new Four_Player(2, 'O');
        }
        else{
            // Player pointer points to child
            players[1] = new RandomPlayer('O', 7, 6);
        }

        break;
    case 3:
        board = new TicTacToeBoard;
        players[0] = new TicTacToePlayer(1, 'X');

        cout << "Press 1 if you want to play with computer: ";
        cin >> playCPU;

        if (playCPU != 1){
            players[1] = new TicTacToePlayer(2, 'O');
        }
        else{
            // Player pointer points to child
            players[1] = new RandomPlayer('O', 5, 5);
        }

        break;
    default:
        cout << "Thank You ;) ";
        return 0;
    }
    
    GameManager game(board, players);
    game.run();
    return 0;
}
