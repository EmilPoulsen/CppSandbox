#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h";
#include "vertex.h";


class Polygon : public Shape
{
public:
    Polygon();
    Polygon( double x, double y, Vertex *varr, int num);
    void print();
        double calculateArea();
    Shape *clone ();
private:
    Vertex *vertices;
    double calcArea() const;
    int numOfVertices;

};

#endif // POLYGON_H
