#include "game.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

cGame::cGame(QWidget * parent)
{
    QGraphicsScene *scene = new QGraphicsScene();
    cPlayer *player = new cPlayer();

    score = new cScore();
    health = new cHealth();

    scene->addItem(player);
    scene->addItem(score);
    scene->addItem(health);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));


    setFixedSize(800,600);
    player->setPos(width()/2, height() - player->pixmap().height());



    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/my_first_game_background_music.mp3"));

    music->play();

    timer->start(2000);

}

cGame::~cGame()
{

}
