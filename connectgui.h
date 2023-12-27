#ifndef CONNECTGUI_H
#define CONNECTGUI_H

#include <QMainWindow>
#include <Qpushbutton>
#include "board.h"

namespace Ui {
class connectgui;
}

class connectgui : public QMainWindow
{
    Q_OBJECT

public:
    explicit connectgui(QWidget *parent = nullptr);
    ~connectgui();
    static std::pair<int,int> getCord();
    static int x,y;
    static void updateBoard(Board *b);
    static QPushButton *buttons[42];
    static void setEnableEmpty(Board *b,bool bl);

private:
    Ui::connectgui *ui;
    void buttonPressed();
};


#endif // CONNECTGUI_H
