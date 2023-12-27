#ifndef XOGUI_H
#define XOGUI_H

#include <QMainWindow>
#include <Qpushbutton>
#include "board.h"

namespace Ui {
class xoGui;
}

class xoGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit xoGui(QWidget *parent = nullptr);
    ~xoGui();
    static std::pair<int,int> getCord();
    static int x,y;
    static void updateBoard(Board *b);
    static QPushButton *buttons[9];
    static void setEnableEmpty(Board *b,bool bl);

private:
    Ui::xoGui *ui;
    void buttonPressed();
};

#endif // XOGUI_H
