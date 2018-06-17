#include "score.h"


cScore::cScore(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    m_score = 0;
    setPlainText(QString("Score: ") + QString::number(m_score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times,16"));
}

cScore::~cScore()
{

}

int cScore::getScore()
{
    return m_score;
}

void cScore::setScore()
{
    m_score++;
    setPlainText(QString("Score: ") + QString::number(m_score));
}
