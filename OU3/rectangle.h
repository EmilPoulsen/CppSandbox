#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"

class Rectangle : public Shape
{
public:
    Rectangle();
    Rectangle( double x, double y, double width, double height);
    void print();
    string getPrintString();
     double calculateArea();
    Shape *clone () const;
private:
    double m_Width;
    double m_Height;
};

#endif // RECTANGLE_H
