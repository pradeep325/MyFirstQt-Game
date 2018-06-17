#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "game.h"

cGame *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new cGame();
    game->show();


//    QGraphicsScene *scene = new QGraphicsScene();
//    QGraphicsView *view = new QGraphicsView();
//    cPlayer *player = new cPlayer();

//    player->setRect(0,0,100,100);

//    scene->addItem(player);


//    player->setFlag(QGraphicsItem::ItemIsFocusable);
//    player->setFocus();


//    view->setScene(scene);
//    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

//    view->setFixedSize(800,600);
//    scene->setSceneRect(0,0,800,600);
//    player->setPos(view->width()/2, view->height()-player->rect().height());

//    QTimer *timer = new QTimer();
//    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));

//    timer->start(2000);


//    view->show();




    return a.exec();
}
