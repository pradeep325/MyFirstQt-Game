#ifndef MYBULLET_H
#define MYBULLET_H

#include "game.h"
#include "enemy.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QTimer>
#include <QKeyEvent>

class cBullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    cBullet(QGraphicsItem * parent = 0);
private:
    QMediaPlayer * m_explosion;
public slots:
    void move();
};

#endif // MYBULLET_H
