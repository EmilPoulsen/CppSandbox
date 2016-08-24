#ifndef POLYGON_H
#define POLYGON_H
#include "Vertex.h"


class Polygon
{
public:
    Polygon();
    Polygon(Vertex v1[], int arrSize);

    void add(Vertex &v);
    string print() const;
    double area() const;
    double minx();
    double maxx();
    double miny();
    double maxy();
    int numVertices();
    ~Polygon();
    friend std::ostream & operator<<(std::ostream& os, const Polygon& v);
    friend bool operator< (const Polygon &c1, const Polygon &c2);
    friend bool operator> (const Polygon &c1, const Polygon &c2);

private:
    Vertex *vertices;
    double calcArea() const;
    int numOfVertices;
};

#endif // POLYGON_H
