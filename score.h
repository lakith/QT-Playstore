#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score : public QGraphicsTextItem
{
    Q_OBJECT
public:
    Score(QGraphicsItem * parent=0);
    void increase();
    int getScore();
private:
    int score;

signals:

public slots:
};

#endif // SCORE_H
