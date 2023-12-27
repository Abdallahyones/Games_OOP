#include "gamemanager.h"
#include "xoboard.h"
#include "randomplayer.h"
#include "xogui.h"

#include "pyramidboard.h"
#include "pyramidgui.h"

#include "largeboard.h"
#include "largegui.h"

#include "connectboard.h"
#include "connectgui.h"

#include <QTimer>
#include <QEventLoop>
#include <QMessageBox>

GameManager::GameManager() {

}

void GameManager::setGameInfo(std::string code, bool is2Ply){
    //Setup Board
    Board* board;
    this->code = code;
    this->useCPU = !is2Ply;
    if (code == "normal"){
        board = new XOBoard();
        boardPtr = board;

        //Setup Player
        players[0] = new Player(1, 'X');
        if (is2Ply)
            players[1] = new Player (2, 'O');
        else
            players[1] = new RandomPlayer('O',3,3);

        loadNormalWindow();

    }
    else if (code == "pyramid"){
        board = new pyramidBoard();
        boardPtr = board;

        //Setup Player
        players[0] = new Player(1, 'X');
        if (is2Ply)
            players[1] = new Player (2, 'O');
        else
            players[1] = new RandomPlayer('O',5,3);

        loadPyramidWindow();
    }
    else if (code == "large"){
        board = new largeboard();
        boardPtr = board;

        //Setup Player
        players[0] = new Player(1, 'X');
        if (is2Ply)
            players[1] = new Player (2, 'O');
        else
            players[1] = new RandomPlayer('O',5,5);

        loadLargeWindow();
    }
    else {
        board = new connectboard();
        boardPtr = board;

        //Setup Player
        players[0] = new Player(1, 'X');
        if (is2Ply)
            players[1] = new Player (2, 'O');
        else
            players[1] = new RandomPlayer('O',7,6);

        loadConnectWindow();
    }

    run();
}

void GameManager::run() {
        int x, y;
    while (!boardPtr->game_is_over()) {
        for (int i:{0,1}) {
            do{
                if (!useCPU || (useCPU && !i)){
                // Wait for a specified number of milliseconds
                 int millisecondsToWait = 33; // Change this value to the desired delay time //2000 Debug // 33 Normal
                 QEventLoop loop;
                 QTimer::singleShot(millisecondsToWait, &loop, &QEventLoop::quit);
                 loop.exec();
                }

                players[i]->get_move(x, y, code);
            }
            while (!boardPtr->update_board (x, y, players[i]->get_symbol()));


            if (code == "normal")
                xoGui::updateBoard(boardPtr);
            else if (code == "pyramid")
                pyramidgui::updateBoard(boardPtr);
            else if (code == "large")
                largegui::updateBoard(boardPtr);
            else
                connectgui::updateBoard(boardPtr);

            if (boardPtr->is_winner()) {
                QString winnerMessage = QString::fromStdString(players[i]->to_string() + " wins!");
                QMessageBox::information(nullptr, "Winner", winnerMessage);


                if (code == "normal")
                    xoGui::setEnableEmpty(boardPtr,false);
                else if (code == "pyramid")
                    pyramidgui::setEnableEmpty(boardPtr,false);
                else if (code == "connect")
                    connectgui::setEnableEmpty(boardPtr,false);

                return;
            }
            if (boardPtr->is_draw()) {
                QMessageBox::information(nullptr, "Draw", "It's a draw!");
                return;
            }
            if (boardPtr->game_is_over()){
            // Assume it reaches here then it must be player 2 large (5x5)
            QString winnerMessage = QString::fromStdString(players[1]->to_string() + " wins!");
            QMessageBox::information(nullptr, "Winner", winnerMessage);
            }
        }
    }

}

void GameManager::loadNormalWindow(){
    xoGui *g = new xoGui();
    g->show();
}

void GameManager::loadPyramidWindow(){
    pyramidgui *g = new pyramidgui();
    g->show();
}

void GameManager::loadLargeWindow(){
    largegui *g = new largegui();
    g->show();
}

void GameManager::loadConnectWindow(){
    connectgui *g = new connectgui();
    g->show();
}
