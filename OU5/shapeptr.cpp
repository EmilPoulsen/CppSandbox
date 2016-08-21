#include "shapeptr.h"

ShapePtr::ShapePtr()
{
}

ShapePtr::ShapePtr(Shape* shape)
    : m_pShape(shape)
{
}

ShapePtr::~ShapePtr(){
    //delete m_pShape;
}

Shape* ShapePtr::getShape() const{
    return m_pShape;
}

std::string ShapePtr::print() const {
    return m_pShape->getPrintString();
}

std::ostream & operator<<(std::ostream& os, const ShapePtr& v){
     os << v.print();
     return os;
 }

