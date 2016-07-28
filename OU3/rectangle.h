#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h";

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle( double x, double y, double width, double height);
};

#endif // RECTANGLE_H
