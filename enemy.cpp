#include "enemy.h"
#include "gamebase.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>

#include <QDebug>

extern GameBase *game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    int random_number = rand() % 700;
    setPos(random_number,0);

    // drew the rect
    QPixmap pixmap(":/new/images/resource/images/enemy.png");
    setPixmap(pixmap.scaled(50,50));
    setTransformOriginPoint(25,25);
    setRotation(180);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void Enemy::move()
{

       setPos(x(),y()+5);


       if (pos().y() > 600){
           game->health->decrease();


           scene()->removeItem(this);
           delete this;
    }
}



