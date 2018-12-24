#ifndef MYPLAYER_H
#define MYPLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class MyPlayer : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    MyPlayer(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    QMediaPlayer *bulletSound;
};

#endif // MYPLAYER_H
