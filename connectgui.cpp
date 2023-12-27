#include "connectgui.h"
#include "ui_connectgui.h"

QPushButton* connectgui::buttons[42] = { nullptr };
int connectgui::x = -1;
int connectgui::y = -1;

connectgui::connectgui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::connectgui)
{
    ui->setupUi(this);
    this->setWindowTitle("Connect 4 Game");
    x = -1;
    y = -1;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            QString buttonName = "c" + QString::number(i) + QString::number(j);
            buttons[i * 7 + j] = findChild<QPushButton*>(buttonName);
            buttons[i * 7 + j]->setText(" ");
            buttons[i * 7 + j]->setStyleSheet("QPushButton:disabled { color: black; }");;
            connect(buttons[i * 7 + j], &QPushButton::clicked, this, &connectgui::buttonPressed);
        }
    }
}

connectgui::~connectgui()
{
    delete ui;
}

std::pair<int,int> connectgui::getCord(){
    int oldx = x, oldy = y;
    if (x != -1 && y != -1){
        x = -1;
        y = -1;
    }
    return std::make_pair(oldx,oldy);
}

void connectgui::buttonPressed(){
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender()); // Get the sender button

    if (clickedButton) {
        QString buttonName = clickedButton->objectName(); // Retrieve the object name of the button
        if (buttonName.length() == 3) {
            QChar firstIndex = buttonName.at(1);
            QChar secondIndex = buttonName.at(2);

            // Assuming the button names follow the pattern "cXY" where X and Y are indices
            x = firstIndex.digitValue();
            y = secondIndex.digitValue();
        }
    }
}

void connectgui::updateBoard(Board *b) {
    if (b != nullptr && b->board != nullptr) {
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 7; j++){
                // Convert each character from char to QString and set it as button text
                QString buttonText = QString::fromLatin1(&(b->board[i][j]), 1);
                buttons[i * 7 + j]->setText(buttonText);
                if (b->board[i][j] != 0){
                    buttons[i * 7 + j]->setEnabled(false);
                }
            }
        }
    }
}

void connectgui::setEnableEmpty(Board *b,bool value) {
    if (b != nullptr && b->board != nullptr) {
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 7; j++){
                if (b->board[i][j] == 0){
                    buttons[i * 7 + j]->setEnabled(value);
                }
            }
        }
    }
}

