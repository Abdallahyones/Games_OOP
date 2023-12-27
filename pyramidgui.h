#ifndef PYRAMIDGUI_H
#define PYRAMIDGUI_H
#include "board.h"
#include <QPushButton>
#include <QMainWindow>

namespace Ui {
class pyramidgui;
}

class pyramidgui : public QMainWindow
{
    Q_OBJECT

public:
    explicit pyramidgui(QWidget *parent = nullptr);
    ~pyramidgui();
    static std::pair<int,int> getCord();
    static int x,y;
    static void updateBoard(Board *b);
    static QPushButton *buttons[9];
    static void setEnableEmpty(Board *b,bool bl);

private:
    Ui::pyramidgui *ui;
    void buttonPressed();
};

#endif // PYRAMIDGUI_H
