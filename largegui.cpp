#include "largegui.h"
#include "ui_largegui.h"

QPushButton* largegui::buttons[25] = { nullptr };
int largegui::x = -1;
int largegui::y = -1;

largegui::largegui(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::largegui)
{
    ui->setupUi(this);
    this->setWindowTitle("Large Game");
    x = -1;
    y = -1;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            QString buttonName = "c" + QString::number(i) + QString::number(j);
            buttons[i * 5 + j] = findChild<QPushButton*>(buttonName);
            buttons[i * 5 + j]->setText(" ");
            buttons[i * 5 + j]->setStyleSheet("QPushButton:disabled { color: black; }");
            connect(buttons[i * 5 + j], &QPushButton::clicked, this, &largegui::buttonPressed); 
        }
    }
}

largegui::~largegui()
{
    delete ui;
}

std::pair<int,int> largegui::getCord(){
    return std::make_pair(x,y);
}

void largegui::buttonPressed(){
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

void largegui::updateBoard(Board *b) {
    if (b != nullptr && b->board != nullptr) {
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                // Convert each character from char to QString and set it as button text
                QString buttonText = QString::fromLatin1(&(b->board[i][j]), 1);
                buttons[i * 5 + j]->setText(buttonText);
                if (b->board[i][j] != 0){
                    buttons[i * 5 + j]->setEnabled(false);

                }
            }
        }
    }
}

