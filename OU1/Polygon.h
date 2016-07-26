#ifndef POLYGON_H
#define POLYGON_H
#include "Vertex.h"


class Polygon
{
public:
    Polygon();
    Polygon(Vertex v1[], int arrSize);

    void add(Vertex v);
    double area();
    double minx();
    double maxx();
    double miny();
    double maxy();
    int numVertices();
    ~Polygon();

private:
    Vertex *vertices;
    double calcArea();
    int numOfVertices;
};

#endif // POLYGON_H
