/*
 * File:    Array.h
 * Author:  Enrique Najera
 * Purpose: Create & delete dynamic 2D array
 * Date:    09 September 2015
 */

#ifndef ARRAY_H
#define ARRAY_H

// Start class Array
class Array
{
private:
    int nRows;
    int nCols;
    int **array;
public:
    // Constructors / Destructor
    Array(int, int);
    ~Array();

    // Accessor Functions
    int getNrows() const
        { return nRows; }
    int getNcols() const
        { return nCols; }
    int **getArray() const
        { return array; }
}; // End class Array

#endif // ARRAY_H
