#include "pyramidgui.h"
#include "ui_pyramidgui.h"


QPushButton* pyramidgui::buttons[9] = { nullptr };
int pyramidgui::x = -1;
int pyramidgui::y = -1;


pyramidgui::pyramidgui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::pyramidgui)
{
    ui->setupUi(this);
    this->setWindowTitle("Pyramid Game");
    x = -1;
    y = -1;
    int counter = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2 * i + 1; j++){
            QString buttonName = "c" + QString::number(i) + QString::number(j);
            buttons[counter] = findChild<QPushButton*>(buttonName);
            buttons[counter]->setText(" ");
            buttons[counter]->setStyleSheet("QPushButton:disabled { color: black; }");;
            connect(buttons[counter], &QPushButton::clicked, this, &pyramidgui::buttonPressed);
            counter++;
        }
    }
}

pyramidgui::~pyramidgui()
{
    delete ui;
}


std::pair<int,int> pyramidgui::getCord(){
    return std::make_pair(x,y);
}

void pyramidgui::buttonPressed(){
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

//Board* pyramidgui::b;

void pyramidgui::updateBoard(Board* c) {
    if (c != nullptr && c->board != nullptr) {
        int counter = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 2 * i + 1; j++){
                // Convert each character from char to QString and set it as button text
                QString buttonText = QString::fromLatin1(&(c->board[i][j]), 1);
                buttons[counter]->setText(buttonText);
                if (c->board[i][j] != 0){
                    buttons[counter]->setEnabled(false);
                }
                counter++;
            }
        }
    }
}

void pyramidgui::setEnableEmpty(Board *b,bool value) {
    if (b != nullptr && b->board != nullptr) {
        int counter = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 2 * i + 1; j++){
                if (b->board[i][j] == 0){
                    buttons[counter]->setEnabled(value);
                }
                counter++;
            }
        }
    }
}
