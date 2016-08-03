#include "shape.h"

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





