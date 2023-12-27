#ifndef LARGEGUI_H
#define LARGEGUI_H
#include "board.h"
#include <QPushButton>
#include <QMainWindow>

namespace Ui {
class largegui;
}

class largegui : public QMainWindow
{
    Q_OBJECT

public:
    explicit largegui(QWidget *parent = nullptr);
    ~largegui();
    static std::pair<int,int> getCord();
    static int x,y;
    static void updateBoard(Board *b);
    static QPushButton *buttons[25];

private:
    Ui::largegui *ui;
    void buttonPressed();
};

#endif // LARGEGUI_H
