/*
 * File:    score.cpp
 * Author:  Enrique Najera
 * Purpose: Holds player score
 * 18 November 2015
 */

#include "score.h"

// Start constructor Score
Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    score = 0;

    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times", 16));
}// End constructor Score

// Start method increase
void Score::increase()
{
    // Increase score then update text
    score++;
    setPlainText(QString("Score: ") + QString::number(score));
}// End method increase

// Start method decrease
void Score::decrease()
{
    // Decrease score then update text
    score--;
    setPlainText(QString("Score: ") + QString::number(score));
}// End method decrease

// Start method getScore
int Score::getScore() const
{
    return score;
}// End method getScore
