#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "player.h"
#include "board.h"
#include <QObject>

class GameManager : public QObject {
    Q_OBJECT

private:
          Board* boardPtr;
          Player* players[2];
          void loadNormalWindow();
          void loadPyramidWindow();
          void loadLargeWindow();
          void loadConnectWindow();
          std::string code;
          bool useCPU;

public:
    GameManager();
    void setup(Board*, Player* playerPtr[2]);
    void run();

public slots:
    void setGameInfo(std::string, bool);
};

#endif // GAMEMANAGER_H
