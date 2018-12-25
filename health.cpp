#include "health.h"
#include<QFont>
#include "mainwindow.h"
#include "gamebase.h";

extern GameBase *game;

Health::Health(QGraphicsItem *parent) :QGraphicsTextItem (parent)
{
    // initialize the score to 0
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease()
{
    health--;
    if(health < 0){
        game->close();
    }

    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth()
{
   return health;
}
