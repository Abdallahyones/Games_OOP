#include "mainmenu.h"
#include "./ui_mainmenu.h"
#include <QRadioButton>

MainMenu::MainMenu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);
     this->setWindowTitle("XO Hub");

    // Setup Buttons
    buttons[0] = findChild<QPushButton*>("normal");
    buttons[1] = findChild<QPushButton*>("pyramid");
    buttons[2] = findChild<QPushButton*>("connect");
    buttons[3] = findChild<QPushButton*>("large");

    // Create an instance of GameManager
    gm = new GameManager();

    // Setup Connections
    connect(buttons[0], &QPushButton::clicked, [=]() {
        gameSelected("normal");
    });
    connect(buttons[1], &QPushButton::clicked, [=]() {
        gameSelected("pyramid");
    });
    connect(buttons[2], &QPushButton::clicked, [=]() {
        gameSelected("connect");
    });
    connect(buttons[3], &QPushButton::clicked, [=]() {
        gameSelected("large");
    });

    // Setup signals
    connect(this, SIGNAL(startGame(std::string,bool)), gm, SLOT(setGameInfo(std::string,bool)));
}

MainMenu::~MainMenu()
{
    delete ui;
    delete gm;
}

bool MainMenu::Is2Players(){
    QRadioButton *b = findChild<QRadioButton *>("use2Button");
    return b->isChecked();
}

void MainMenu::gameSelected(std::string code){
    emit startGame(code, Is2Players());
}
