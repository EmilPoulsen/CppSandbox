#include "shapeptr.h"

ShapePtr::ShapePtr()
{
}

ShapePtr::ShapePtr(Shape* shape)
    : m_pShape(shape)
{
}

ShapePtr::~ShapePtr(){
    delete m_pShape;
}
