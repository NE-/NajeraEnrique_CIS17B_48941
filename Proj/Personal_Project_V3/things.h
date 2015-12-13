/*
 * File:    things.h
 * Author:  Enrique Najera
 * Purpose: Room objects
 * 16 December 2015
 */

#ifndef THINGS_H
#define THINGS_H

// Q_LIBS
#include <QGraphicsPixmapItem>

// Start class Things
class Things : public QGraphicsPixmapItem
{
    //Q_OBJECT
public:
    // (image's row,  actual image)
    Things(int row, int thing);

    QPixmap *sheet_things;
};// End class Things

#endif // ITEMS_H
