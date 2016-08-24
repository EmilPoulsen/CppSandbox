#include "shape.h"
#include "vertex.h"

#include <cmath>
using namespace std;

/**
 * @brief Shape
 * default constructor
 */
Shape::Shape(){
}

/**
 * @brief area
 * Returns the area of the shape.
 * @return
 */
double Shape::area(){
    return calculateArea();
}

/**
 * @brief Shape::copyBaseProperties
 * Copies all internal field members for the base class shape
 * @param other
 */
void Shape::copyBaseProperties(Shape& other){
    m_X = other.m_X;
    m_Y = other.m_Y;
}

/**
 * @brief Shape::IsCloseToVertex
 * Checks if the x or the y value is close to a given vertex. Note, its not the euclidean distance
 * @param v
 * The vertex to check against
 * @param tol
 * The tolerance of the check
 * @return
 * True if the shape is close, false if not.
 */
bool Shape::IsCloseToVertex(const Vertex &v, double tol) const{
    if((abs(v.getX() - m_X) < tol) && ((abs(v.getY() - m_Y) < tol)))
        return true;
    else
        return false;
}

/**
 * @brief Shape::getX
 * Returns the x value of the shape
 * @return
 */
double Shape::getX(){
    return m_X;
}

/**
 * @brief Shape::getY
 * Returns the x value of the shape
 * @return
 */
double Shape::getY(){
    return m_Y;
}




