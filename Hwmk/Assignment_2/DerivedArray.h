/*
 * File:    DerivedArray.h
 * Author:  Enrique Najera
 * Purpose: Derived class prints array
 * Date:    20 September 2015
 */

#ifndef DERIVEDARRAY_H
#define DERIVEDARRAY_H

// Q_LIBS
#include <QString>

// USER_LIBS
#include "AbstractArray.h"
#include "BaseArray.h"

// Start class DerivedArray
class DerivedArray
{
public:
    QString toPrint(); // Prints the char array
};

#endif // DERIVEDARRAY_H
