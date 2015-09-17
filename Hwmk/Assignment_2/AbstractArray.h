/*
 * File:    AbstractArray.h
 * Author:  Enrique Najera
 * Purpose: Abstract class to fill array
 * Date:    20 September 2015
 */

#ifndef ABSTRACTARRAY_H
#define ABSTRACTARRAY_H

// Start class AbstractArray
class AbstractArray
{
protected:
    int nRows;   // Number of rows
    int nCols;   // Number of columns
    int **array; // 2D dynamic array to hold rand numbers
public:
    virtual void **fillArray() = 0; // Pure fills array
}; // End class AbstractArray

#endif // ABSTRACTARRAY_H
