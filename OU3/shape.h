#ifndef SHAPE_H
#define SHAPE_H
#include "vertex.h"


class Shape
{
protected:
    double m_X; //anchor position x
    double m_Y; //anchor position y
public:
    Shape();
    virtual void print() = 0;
    virtual string getPrintString() = 0;
    double area();
    virtual double calculateArea() = 0;
    void copyBaseProperties(Shape& other);
    virtual Shape *clone () = 0;
    bool IsCloseToVertex(const Vertex &v, double tol) const;
    double getX();
    double getY();
};

#endif // SHAPE_H
