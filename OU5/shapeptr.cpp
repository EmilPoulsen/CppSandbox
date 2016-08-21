#include "shapeptr.h"
#include "../OU3/vertex.h"
#include "../OU3/polygon.h"
#include "../OU3/shape.h"
#include "../OU3/circle.h"
#include "../OU3/rectangle.h"
#include "../OU3/point.h"


ShapePtr::ShapePtr()
    : m_pShape(0)
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

std::istream& operator>>(std::istream& is, ShapePtr& sp){
    Shape* newShape;
    string s;
    istream& localis = std::getline(is, s);
    newShape = ShapePtr::createShapeFromString(s);
    sp.m_pShape = newShape;
    return localis;
}

Shape* ShapePtr::createShapeFromString(string s){
    string type = s.substr(0,3);
    Shape* newShape;
    if(type == "POL"){

    }
    else if(type == "CIR"){
        return createCircle(s);
    }
    else if(type == "REC"){

    }
    else if(type == "POI"){

    }
    else{

    }
    return newShape;
}




Shape* ShapePtr::createPolygon(string s){

}

Shape* ShapePtr::createCircle(string s){
    double x = atof(s.substr(9,10).c_str());
    double y = atof(s.substr(12,13).c_str());
    double r = atof(s.substr(15,16).c_str());
    return new Circle(x, y, r);
}

Shape* ShapePtr::createRectangle(string s){
    double x = atof(s.substr(12,13).c_str());
    double y = atof(s.substr(12,13).c_str());


    //Rectangle( double x, double y, double width, double height);
}

Shape* ShapePtr::createPoint(string s){

}

