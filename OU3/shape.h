#ifndef SHAPE_H
#define SHAPE_H
#include "vertex.h"


class Shape
{
protected:
    double m_X; //anchor position x
    double m_Y; //anchor position y
public:
    /**
     * @brief Shape
     * default constructor
     */
    Shape();

    /**
     * @brief print
     * prints information about the shape
     */
    virtual void print() = 0;

    /**
     * @brief area
     * Returns the area of the shape.
     * @return
     */
    double area();

    /**
     * @brief calculateArea
     * Calculates the area of the shape
     * @return
     */
    virtual double calculateArea() = 0;

    void copyBaseProperties(Shape& other);

    virtual Shape *clone () = 0;

    bool IsCloseToVertex(const Vertex &v, double tol) const;
};

#endif // SHAPE_H
