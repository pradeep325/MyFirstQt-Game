#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include "mybullet.h"
#include "enemy.h"

class cPlayer : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    cPlayer(QGraphicsItem * parent = 0);
    virtual ~cPlayer();
    void keyPressEvent(QKeyEvent* event);
private:
    QMediaPlayer * bulletSound;
public slots:
    void spawn();

};

#endif // MYRECT_H
