/*
 * File:    button.cpp
 * Author:  Enrique Najera
 * Purpose: Create buttons for main menu
 * 16 December 2015
 */

// USER_LIBS
#include "button.h"

// Start constructor Button
Button::Button(int y)
{
    sheet_button = new QPixmap(":/img/images/buttons.png");
    setPixmap(sheet_button->copy(0,y,64,32));
}// End constructor Button

// Start method mousePressEvent
void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit click();
}// End method mousePressEvent
