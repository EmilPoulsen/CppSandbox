#ifndef POINT_H
#define POINT_H
#include "shape.h";

class Point  : public Shape
{
public:
    Point();
    Point(double x, double y, double size);
    void print();
};

#endif // POINT_H
