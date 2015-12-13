/*
 * File:    button.h
 * Author:  Enrique Najera
 * Purpose: Create buttons for main menu
 * 16 December 2015
 */

#ifndef BUTTON_H
#define BUTTON_H

// Q_LIBS
#include <QGraphicsPixmapItem>

// Start class Button
class Button : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Button(int y);

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
    QPixmap *sheet_button;
signals:
    void click();
};// End class Button

#endif // BUTTON_H
