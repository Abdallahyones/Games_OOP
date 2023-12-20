#include "Connect_Four.h"
#include "Pyramid.h"
#include "TicTacToe.h"

#define Body_code  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define files_out  freopen("output.txt", "w", stdout);
#define files_in   freopen("input.txt", "r", stdin);
#define all(ele)  ele.begin(), ele.end()
#define fo(i , n) for (long long int i =0 ; i < n ; i++)
#define MX INT_MAX
#define MN INT_MIN
#define X first
#define Y second
typedef long long ll ;

using namespace std;

int main() {
//    files_in
//    files_out
    int choice , num ;
    Player* players[2];
    Board* board = new Pyramid_Board ;
    cout << "Welcome to FCAI Games. :)\n Plesse Closse The Game\n";
    cout << "1- Pyramic Tic-Tac-Toe\n"
    << "2- Four-in-a-row\n"
    << "3- 5 x 5 Tic Tac Toe\n"
    << "4- X/O Game\n"
    << "5-Exit\n" ;
    cin >> num ;
    switch (num) {
        case 1:
            players[0] = new pyramid_Player (1, 'X');
            board = new Pyramid_Board   ;
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice;
            if (choice != 1){
                players[1] = new pyramid_Player (2, 'O');
            }
            else{
                //Player pointer points to child
                players[1] = new RandomPlayer ('O', 5 , 3);
            }
            break;
        case 2:
            players[0] = new Four_Player (1, 'X');
            board = new Four_Board   ;
            cout << "Press 1 if you want to play with computer or press 2 if you want to play with AI_player  ";
            cin >> choice;
            if (choice != 1 && choice != 2){
                players[1] = new Four_Player (2, 'O');
            }else if (choice == 2){
                players[1] = new Four_AI_Player('O', board);
            }else{
                //Player pointer points to child
                players[1] = new RandomPlayer ('O', 7, 6);
            }
            break;
        case 3:
            board = new TicTacToeBoard ;
            players[0] = new TicTacToePlayer(1, 'X');
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice;
            if (choice != 1){
                players[1] = new TicTacToePlayer(2, 'O');
            }
            else{
                //Player pointer points to child
                players[1] = new RandomPlayer ('O', 5 , 5);
            }
            break;
        case 4:
            board = new X_O_Board() ;
            players[0] = new Player (1, 'x');
            cout << "Welcome to FCAI X-O Game. :)\n";
            cout << "Press 1 if you want to play with computer: ";
            cin >> choice;
            if (choice != 1)
                players[1] = new Player (2, 'o');
            else
                //Player pointer points to child
                players[1] = new RandomPlayer ('o', 3 , 3);
            break;
        default:
            cout <<"Thank You ;) " ;
            return 0 ;
    }
    GameManager four_game (board, players);
    four_game.run();
    return 0 ;
}

