#include "shape.h"
#include "vertex.h"

#include <cmath>
using namespace std;

Shape::Shape()
{

}



double Shape::area(){
    return calculateArea();
}

void Shape::copyBaseProperties(Shape& other){
    m_X = other.m_X;
    m_Y = other.m_Y;
}

bool Shape::IsCloseToVertex(const Vertex &v, double tol) const{
    if((abs(v.getX() - m_X) < tol) && ((abs(v.getY() - m_Y) < tol)))
        return true;
    else
        return false;
}




