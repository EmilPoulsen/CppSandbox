#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"


class Circle : public Shape
{
public:
    Circle();
    Circle( double x, double y, double radie);
    void print();
    string getPrintString();
    double calculateArea();
    Shape *clone ();
private:
    double m_Radius;
};

#endif // CIRCLE_H
