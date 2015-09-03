/*
 * File: Rectangle.h
 * Author: Enrique Najera
 * Purpose: Assignment 1 refresh on classes,
 *          headers, & cpp files/syntax
 * 09 September 2015
 */

#ifndef RECTANGLE_H
#define RECTANGLE_H

// Start class Rectangle
class Rectangle
{
private:
    float width;
    float length;
public:
    //Default constructor
    Rectangle()
        { width = 0.0, length = 0.0; }

    //Exception class
    class InvalidWorL{};

    //Mutator Functions
    void setWidth(float);
    void setLength(float);

    //Accessor Functions
    float getWidth()  const
          { return width; }
    float getLength() const
          { return length; }
    float getArea()   const
          { return width * length; }

}; // End class Rectangle

#endif // RECTANGLE_H
