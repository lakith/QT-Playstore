#ifndef GAMEBASE_H
#define GAMEBASE_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include "myplayer.h"
#include "score.h"
#include "health.h"

class GameBase: public QGraphicsView
{
public:
   GameBase(QWidget * parent=0);

   QGraphicsScene * scene;
   MyPlayer * player;
   Score * score;
   Health * health;
};

#endif // GAMEBASE_H
