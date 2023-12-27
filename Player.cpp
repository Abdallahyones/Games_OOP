#include "player.h"
#include "xogui.h"
#include "pyramidgui.h"
#include "largegui.h"
#include "connectgui.h"
// Give player a symbol to use in playing
// It can be X or O or others
// This is needed for computer players
// as it does not ask for a name
Player::Player(char symbol) {
    this->symbol = symbol;
}

// Optionally, you can give him ID or order
// Like Player 1 and Player 2
Player::Player (int order, char symbol) {
    name = "Player " + std::to_string(order);
    this->symbol = symbol;
}

char Player::get_symbol(){
    return this->symbol;
}

void Player::get_move (int& x, int& y, std::string code) {
    std::pair<int,int> p;

    if (code == "normal")
        p = xoGui::getCord();
    else if (code == "pyramid")
        p = pyramidgui::getCord();
    else if (code == "large")
        p = largegui::getCord();
    else
        p = connectgui::getCord();

    x = p.first;
    y = p.second;
}

std::string Player::to_string(){
    return this->name;
}
