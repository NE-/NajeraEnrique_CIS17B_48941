/*
 * File:    score.h
 * Author:  Enrique Najera
 * Purpose: Holds player score
 *          NON FUNCTIONING AT THE MOMENT
 * 18 November 2015
 */

#ifndef SCORE_H
#define SCORE_H

// Q_LIBS
#include <QGraphicsTextItem>
#include <QFont>

class Score : public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent=0);

    void increase();
    int getScore() const;
private:
    int score;
};

#endif // SCORE_H
