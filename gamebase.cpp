#include "gamebase.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsScene>
#include "enemy.h"
#include "myplayer.h"
#include <QMediaPlayer>

GameBase::GameBase(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/new/images/resource/images/bg_game.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);


    player = new MyPlayer();
    player->setPos(400,500);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/new/sounds/resource/sounds/war_sound.mp3"));
    music->play();

    show();
}
