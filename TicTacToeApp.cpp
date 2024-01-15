#include "./TicTacToePlayer.h"
#include "./TicTacToeBoard.h"
#include <iostream>

using namespace std;

int main(){
    Player* opponents[2];
    int choice;
    cout << "Welcome to X-O TicTacToe 5x5 Game. \n";
    opponents[0] = new TicTacToePlayer(1, 'O');
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    switch(choice){
        case 1:
            opponents[1] = new RandomPlayer('X',5,5);
            break;
        case 2:
            opponents[1] = new TicTacToePlayer(2, 'O');
            break;
    }
    GameManager Game(new TicTacToeBoard(), opponents);
    Game.run();
    system ("pause");
    return 0;
}
