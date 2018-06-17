#include "player.h"
#include "QDebug"
#include <QKeyEvent>
#include <QGraphicsScene>

cPlayer::cPlayer(QGraphicsItem * parent): QGraphicsPixmapItem(parent)
{
    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/bullet_sound.mp3"));

    setPixmap(QPixmap(":/images/player.png"));
}

cPlayer::~cPlayer()
{

}

void cPlayer::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        {
            setPos(x()-10, y());
        }
    }
    else if (event->key() == Qt::Key_Right)
    {
        if (pos().x() + this->pixmap().width() < scene()->width())
        setPos(x()+10,y());
    }
    else if (event->key()==Qt::Key_Up)
    {
        setPos(x(), y()-10);
    }
    else if (event->key()==Qt::Key_Down)
    {
        setPos(x(), y()+10);
    }
    else if (event->key() == Qt::Key_Space)
    {
        cBullet *bullet = new cBullet();
        bullet->setPos(x()+40, y());
        scene()->addItem(bullet);
        if (bulletSound->state() == QMediaPlayer::PlayingState)
        {
          bulletSound->setPosition(0);
        }
        else if (bulletSound->state() == QMediaPlayer::StoppedState)
        {
            bulletSound->play();
        }
    }
    else
    {
        qDebug() << "wrong key pressed!!";
    }
}

void cPlayer::spawn()
{
    cEnemy *enemies = new cEnemy();
    scene()->addItem(enemies);

}
