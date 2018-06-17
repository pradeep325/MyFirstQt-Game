#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QFont>

class cScore : public QGraphicsTextItem
{
public:
    cScore(QGraphicsItem * parent = 0);
    virtual ~cScore();

public:
    int getScore();
    void setScore();

private:
    int m_score;

};

#endif // SCORE_H
