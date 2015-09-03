/*
 * File: Rectangle.cpp
 * Author: Enrique Najera
 * Purpose: Assignment 1 refresh on classes,
 *          headers, & cpp files/syntax
 * 09 September 2015
 */

// Libraries
#include "Rectangle.h"

// Start method setWidth
void Rectangle::setWidth(float w)
{
    if (w > 0)
        width = w;
    else
        throw InvalidWorL();
} // End method setWidth

// Start method setLength
void Rectangle::setLength(float l)
{
    if (l > 0)
        length = l;
    else
        throw InvalidWorL();
} // End method setLength

