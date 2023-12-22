#include "Pyramid_Player.h"
#include "./Pyramid_Ai.h"

using namespace std;

int main(){
    int choice;
    Player* players[2];

    Board* b = new Pyramid_Board();
    cout << "Welcome to FCAI X-O Pyramid Game. :)\n";

    players[0] = new pyramid_Player (1, 'X');

    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1){
        players[1] = new pyramid_Player (2, 'O');
    }
    else{
        //Player pointer points to child
        players[1] = new PyramidAi('O', b);
    }
    GameManager pyramid_game (b, players);
    pyramid_game.run();
    system ("pause");
    return 0;
}