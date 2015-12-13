/*
 * File:    things.cpp
 * Author:  Enrique Najera
 * Purpose: Room objects
 * 16 December 2015
 */

// USER_LIBS
#include "things.h"

// Start constructor Things
Things::Things(int row, int thing)
{
    // Set furniture image
    sheet_things = new QPixmap(":/img/images/things.png");

    // Create item accordingly
    // -table      0
    // -flower    32
    // -window    64
    // -chair     96
    // -picture  128
    // -carpet   160
    // -cupboard 192
    // -couch    224
    setPixmap(sheet_things->copy(row, thing, 32, 32));
}// End constructor Things

