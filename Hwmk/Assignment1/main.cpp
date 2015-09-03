/*
 * File: main.cpp
 * Author: Enrique Najera
 * Purpose: Assignment 1 refresh on classes,
 *          headers, & cpp files/syntax
 * 09 September 2015
 */

// SYS_LIBS
#include <iostream>
#include <cstdlib>

// USER_LIBS
#include "Rectangle.h"

// Namespaces
using namespace std;

// Start method main
int main()
{
    // Declare Variables
    Rectangle rect;   // Rectangle obj
    float rectWidth;  // Local width
    float rectLength; // Local length

    // Prompt for width and length
    cout << "Rectangle area calculator\n";
    cout << "Enter the width of the recatngle: ";
    cin  >> rectWidth;
    cout << "Enter the length of the rectangle: ";
    cin  >> rectLength;

    // Set values and check for errors
    try
    {
        rect.setWidth(rectWidth);
        rect.setLength(rectLength);

        // Output data if all went well
        cout << "Width: "  << rect.getWidth()  << endl;
        cout << "Length: " << rect.getLength() << endl;
        cout << "Area: "   << rect.getArea()   << endl;
    }
    catch(Rectangle::InvalidWorL)
    {
        cout << "\nERROR: Numbers must be over 0!\n";
        exit(EXIT_FAILURE);
    }

    // EXIT SUCCESS
    return 0;
}// End method main

