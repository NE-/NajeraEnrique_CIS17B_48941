/*
 * File:    Array.cpp
 * Author:  Enrique Najera
 * Purpose: Create & delete dynamic 2D array
 * Date:    09 September 2015
 */

// Q_LIBS
#include <QDebug>

// SYS_LIBS
#include <cstdlib>

// USER_LIBS
#include "Array.h"

// Start Constructor Create Dynamic 2D Array
Array::Array(int rows, int cols)
{
    // Mutate in Constructor
    // For Destructor Purposes
    nRows = rows;
    nCols = cols;
    // Allocate Memory
    array = new int*[rows];
    for (int i = 0; i < rows; ++i)
        array[i] = new int[cols];

    // Fill Array with Random 2 Digit Numbers
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            array[i][j] = rand()%90 + 10;
} // End Constructor Array

// Start Destructor Free Dynamic Allocated Memory
Array::~Array()
{
    // Deallocate Memory
    for (int i = 0; i < nRows; ++i)
        delete [] array[i];
    delete [] array;
} // End Destructor
