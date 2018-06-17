#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <stdlib.h>
#include <QTimer>

class cEnemy : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    cEnemy();

public slots:
        void move();
};


#endif // ENEMY_H
