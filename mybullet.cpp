#include <QDebug>
#include <QList>
#include "mybullet.h"
#include <QLabel>
#include <QMovie>
#include <QGraphicsProxyWidget>

extern cGame *game;

cBullet::cBullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{

    setPixmap(QPixmap(":/images/missile.png"));
    QTimer *timer = new QTimer();


    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    m_explosion = new QMediaPlayer();
    m_explosion->setMedia(QUrl("qrc:/sounds/ExplosionSoundEffect.mp3"));


     timer->start(50);

}

void cBullet::move()
{
    setPos(x(), y()-10);

    if (pos().y()+this->pixmap().height() < 0 )
    {
        scene()->removeItem(this);
        delete this;
    }

    QLabel *gif_anim = new QLabel();

    QList<QGraphicsItem *> colliding_enemies = collidingItems();
    for (int i = 0, n = colliding_enemies.size(); i < n ; ++i)
    {
        if (typeid(*(colliding_enemies[i])) == typeid(cEnemy))
        {
            gif_anim->setAttribute(Qt::WA_NoSystemBackground);
            QMovie *movie = new QMovie(":/images/collision1.gif");

            gif_anim->setMovie(movie);

           QGraphicsProxyWidget * proxy = scene()->addWidget(gif_anim);
           proxy->setPos(x()-40, y()-50);

          if ( m_explosion->state() == QMediaPlayer::PlayingState)
          {
              m_explosion->setPosition(0);
          }
          else if (m_explosion->state() == QMediaPlayer::StoppedState)
          {
              m_explosion->play();
          }

          movie->start();

            game->score->setScore();
            scene()->removeItem(colliding_enemies[i]);
            scene()->removeItem(this);

            delete colliding_enemies[i];
            delete this;
            return;
        }
    }
}

