#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"


class Circle : public Shape
{
public:
    Circle();
    Circle( double x, double y, double radie);
private:
    double mX;
    double mY;
    double size;
};

#endif // CIRCLE_H
