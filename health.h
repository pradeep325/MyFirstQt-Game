#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QFont>

class cHealth : public QGraphicsTextItem
{
public:
    cHealth(QGraphicsItem * parent = 0);
    virtual ~cHealth();

public:
    int getHealth();
    void setHealth();

private:
    int m_health;

};

#endif // HEALTH_H
