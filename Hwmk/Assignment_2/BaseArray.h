/*
 * File:    BaseArray.h
 * Author:  Enrique Najera
 * Purpose: Base class to fill array and convert to string
 * Date:    20 September 2015
 */

#ifndef BASEARRAY_H
#define BASEARRAY_H

// USER_LIBS
#include "AbstractArray.h"

// Start class BaseArray
class BaseArray : public AbstractArray
{
public:
    // Constructor / Destructor
    BaseArray(int, int); // Sets rows and columns
    ~BaseArray();        // Deallocates memory

    // Class functions
    void **fillArray();   // Fill array with random numbers 9 > < 100
    char *toString();    // Convert array to string
};// End class BAseArray

#endif // BASEARRAY_H
