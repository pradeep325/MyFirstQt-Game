#include "enemy.h"
#include "player.h"
#include <QDebug>

extern cGame *game;
cEnemy::cEnemy()
{
    setPixmap(QPixmap(":/images/enemy.png"));
    int random_position = rand() % 700;

    setPos(random_position, 0);

    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);

}

void cEnemy::move()
{
    setPos(x(), y()+2);
    if (pos().y() > scene()->height())
    {
        scene()->removeItem(this);
        delete this;
        qDebug() << "deleted!!";
    }

    QList<QGraphicsItem *> colliding_enemies = collidingItems();
    for (int i = 0, n = colliding_enemies.size(); i < n ; ++i)
    {
        if (typeid(*(colliding_enemies[i])) == typeid(cPlayer))
        {
            game->health->setHealth();
            scene()->removeItem(colliding_enemies[i]);
            delete colliding_enemies[i];
            return;
        }
    }
}

