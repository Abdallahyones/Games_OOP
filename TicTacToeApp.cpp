#include "./TicTacToePlayer.h"
#include "./TicTacToeBoard.h"
#include "SmartPlayer.cpp"
#include <iostream>

using namespace std;

int main(){
    auto *board = new TicTacToeBoard();
    Player* opponents[2];
    int choice;
    cout << "Welcome to X-O TicTacToe 5x5 Game. \n";
    opponents[0] = new TicTacToePlayer(1, 'X');
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    switch(choice){
        case 1:
            opponents[1] = new TicTacToe_AI_Player('O',board);
            break;
        case 2:
            opponents[1] = new TicTacToePlayer(2, 'O');
            break;
    }
    GameManager Game(board, opponents);
    Game.run();
    system ("pause");
    return 0;
}