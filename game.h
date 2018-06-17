#ifndef GAME_H
#define GAME_H

#include "enemy.h"
#include "mybullet.h"
#include "player.h"
#include "score.h"
#include "health.h"
#include <QGraphicsView>
#include <QWidget>

class cGame: public QGraphicsView
{
public:
    cGame(QWidget * parent = 0);
    virtual ~cGame();
public:
    cScore *score;
    cHealth *health;
};

#endif // GAME_H
