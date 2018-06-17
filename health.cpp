#include "health.h"


cHealth::cHealth(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    m_health = 3;
    setPlainText(QString("Health: ") + QString::number(m_health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times,16"));
    setPos(x(), y()+15);
}

cHealth::~cHealth()
{

}

int cHealth::getHealth()
{
    return m_health;
}

void cHealth::setHealth()
{
    m_health--;
    setPlainText(QString("Health: ") + QString::number(m_health));
}
