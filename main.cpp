#include <bits/stdc++.h>
#include "BoardGame_Classes.hpp"
#include "Four_in_a_row.h"


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
    int choice;
    Player* players[2];
    cout << "Welcome to FCAI X-O Game. :)\n";

    players[0] = new Four_Player (1, 'X');

    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1){
        players[1] = new Four_Player (2, 'O');
    }
    else{
        //Player pointer points to child
        players[1] = new RandomPlayer ('O', 7);
    }
    GameManager four_game (new Four_Board(), players);
    four_game.run();
    return 0;
}

/*
Abdullah
2
Mohamed
0 0
1 0
0 1
1 1
0 2
 */   // input game(x, o) x , o ;
