/*
 * File:    BaseArray.cpp
 * Author:  Enrique Najera
 * Purpose: Base class to fill array and convert to string
 * Date:    20 September 2015
 */

// SYS_LIBS
#include <cstdlib>
#include <QDebug>

// USER_LIBS
#include "BaseArray.h"

// Start constructor acts as mutator
BaseArray::BaseArray(int rows, int cols)
{
    nRows = rows;
    nCols = cols;
} // End constructor

// Start destructor allocates memory
BaseArray::~BaseArray()
{
    // Deallocate Memory
    for (int i = 0; i < nRows; ++i)
        delete [] array[i];
    delete [] array;
} // End destructor

// Start method fillArray fills array random numbers 9 > < 100
void **BaseArray::fillArray()
{
    // Allocate memory
    array = new int*[nRows];
    for (int i = 0; i < nRows; ++i)
        array[i] = new int[nCols];

    // Fill Array with Random 2 Digit Numbers
    for (int i = 0; i < nRows; ++i)
        for (int j = 0; j < nCols; ++j)
            array[i][j] = rand()%90 + 10;

    // DEBUG
    for (int i = 0; i < nRows; ++i)
        for (int j = 0; j < nCols; ++j)
            qDebug() << array[i][j];

} // End method fillArray

// Start method toString array to char
char *BaseArray::toString()
{
    char *charArray = reinterpret_cast<char *>(array);

    return charArray;
} // End method toString

