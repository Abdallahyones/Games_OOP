#include "xogui.h"
#include "ui_xogui.h"

QPushButton* xoGui::buttons[9] = { nullptr };
int xoGui::x = -1;
int xoGui::y = -1;

xoGui::xoGui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::xoGui)
{
    ui->setupUi(this);
    this->setWindowTitle("Classic Game");
    x = -1;
    y = -1;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            QString buttonName = "c" + QString::number(i) + QString::number(j);
            buttons[i * 3 + j] = findChild<QPushButton*>(buttonName);
            buttons[i * 3 + j]->setText(" ");
            buttons[i * 3 + j]->setStyleSheet("QPushButton:disabled { color: black; }");;
            connect(buttons[i * 3 + j], &QPushButton::clicked, this, &xoGui::buttonPressed);
        }
    }
}

xoGui::~xoGui()
{
    delete ui;
}

std::pair<int,int> xoGui::getCord(){
    return std::make_pair(x,y);
}

void xoGui::buttonPressed(){
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

void xoGui::updateBoard(Board *b) {
    if (b != nullptr && b->board != nullptr) {
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                // Convert each character from char to QString and set it as button text
                QString buttonText = QString::fromLatin1(&(b->board[i][j]), 1);
                buttons[i * 3 + j]->setText(buttonText);
                if (b->board[i][j] != 0){
                    buttons[i * 3 + j]->setEnabled(false);
                }
            }
        }
    }
}

void xoGui::setEnableEmpty(Board *b,bool value) {
    if (b != nullptr && b->board != nullptr) {
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (b->board[i][j] == 0){
                    buttons[i * 3 + j]->setEnabled(value);
                }
            }
        }
    }
}
