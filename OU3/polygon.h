#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h";
#include "vertex.h";

class Polygon : public Shape
{
public:
    Polygon();
    Polygon( double x, double y, Vertex *varr, int num);
};

#endif // POLYGON_H
