#ifndef MAINMENU_H
#define MAINMENU_H

#include <QMainWindow>
#include <QPushButton>
#include "gamemanager.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainMenu;
}
QT_END_NAMESPACE

class MainMenu : public QMainWindow
{
    Q_OBJECT
signals:
    void startGame(std::string code, bool is2Ply);
public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();
    bool Is2Players();
    void gameSelected(std::string code);

private:
    Ui::MainMenu *ui;
    QPushButton *buttons[4];
    GameManager *gm;
};
#endif // MAINMENU_H
