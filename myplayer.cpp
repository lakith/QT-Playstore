#include "myplayer.h"
#include<QDebug>
#include <QKeyEvent>
#include<QGraphicsScene>
#include<QGraphicsItem>
#include<QMediaPlayer>

#include "bullet.h"
#include "myplayer.h"
#include "enemy.h"

MyPlayer::MyPlayer(QGraphicsItem *parent):  QGraphicsPixmapItem(parent)
{
  bulletSound = new QMediaPlayer();
  bulletSound->setMedia(QUrl("qrc:/new/sounds/resource/sounds/Cannon.mp3"));
  QPixmap pixmap(":/new/images/resource/images/player.png");
  setPixmap(pixmap.scaled(50,50));
}

void MyPlayer::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x()-10,y());
        }
    } else if(event->key() == Qt::Key_Right){
        if(pos().x()+100 < 800){
             setPos(x()+10,y());
        }
    }  else if(event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();
        bullet->setPos(x()+25,y());
        scene()->addItem(bullet);

        if (bulletSound->state() == QMediaPlayer::PlayingState){
            bulletSound->setPosition(0);
        } else if (bulletSound->state() == QMediaPlayer::StoppedState){
            bulletSound->play();
        }

    }
}

void MyPlayer::spawn()
{
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}
