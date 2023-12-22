#include <iostream>
#include "Pyramid_Player.h"
#include "Pyramid_Ai.h"
#include <map>
#include<random>
using namespace std;
multimap<int, pair<int, int>> pos;

PyramidAi::PyramidAi(char Symbol, Board *board) : Player(Symbol)
{

    //cout << "Enter Depth Level: (1-4)\n";
    //cin >> depth;
    string n = "Computer Player"; //, Depth ";
    /*
    if (depth < 1)
        depth = 1;
    else if (depth > 4)
        depth = 4;

    switch (depth)
    {
    case 1:
        n += "1";
        break;
     case 2:
        n += "2";
        break;
     case 3:
        n += "3";
        break;
    
    default:
        n += "4";
    } */
    cout << endl;
    depth = 2;
    this->name = n;
    this->symbol = Symbol;
    this->board = board;
}

void PyramidAi::get_move(int &x, int &y)
{
    pos.clear();
    int s = minMax(depth, board, true);
    vector<int> v;
    int evli = pos.begin()->first;
    auto newe = pos.begin();
    for (int i = 1; i <= pos.size(); i++)
    {
        if (evli == newe->first)
            v.push_back(i);
        else if (evli < newe->first)
        {
            evli = newe->first;
            v.clear();
            v.push_back(i);
        }
        newe++;
    }
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, v.size() - 1);

    int randomIndex = v[dist(gen)];
    auto p = pos.begin();
    for (int i = 1; i < randomIndex; i++)
        p++;
    x = p->second.first;
    y = p->second.second + (2 - x);
}

int PyramidAi::minMax(int dep, Board *&b, bool isCPU) {
    if (dep == 0 || b->is_winner()|| b->game_is_over()) {
        // Return evaluation for terminal states
        if (b->is_winner()) {
            return (isCPU) ? -1 : 1; // Swap signs for correct evaluation
        }
        return 0; // Tie
    }

    if (isCPU) {
        int maxE = INT_MIN; // Initialize for finding maximum

        for (auto p : b->availableSpaces()) {
            int x = p.first;
            int y = p.second;
            if (maxE >= 0)
                maxE = INT_MIN;

            if (b->board[x][y] == '#') {
                b->board[x][y] = 'O';
                int eval = minMax(dep - 1, b, !isCPU);
                maxE = max(maxE, eval); // Update maximum evaluation
                b->board[x][y] = '#'; // Revert board change
            }
            if (depth == dep) { // Store best move positions at maximum depth
                pos.insert({maxE, {x, y}});
            }
        }

        return maxE;
    } else {
        int minE = INT_MAX; // Initialize for finding minimum

        for (auto p : b->availableSpaces()) {
            int x = p.first;
            int y = p.second;

            if (b->board[x][y] == '#') {
                b->board[x][y] = 'X';
                int eval = minMax(dep - 1, b, !isCPU);
                minE = min(minE, eval); // Update minimum evaluation
                b->board[x][y] = '#'; // Revert board change
            }
            if (depth == dep) { // Store best move positions at minimum depth
                pos.insert({minE, {x, y}});
            }
        }

        return minE;
    }
}
