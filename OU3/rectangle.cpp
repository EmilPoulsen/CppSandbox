#include "rectangle.h"
using namespace std;
#include <iostream>
#include "../OU2/utility.h"


Rectangle::Rectangle()
{

}
Rectangle::Rectangle( double x, double y, double width, double height){
    m_X = x;
    m_Y = y;
    m_Width = width;
    m_Height = height;

}

void Rectangle::print(){

    cout << getPrintString() << endl;
}

string Rectangle::getPrintString(){
    string output = "RECTANGLE: (";

    output += utility::doubleToStringDecimalPlaces(m_X, 0) + ", ";
    output += utility::doubleToStringDecimalPlaces(m_Y, 0) + ")";
    output += " (" + utility::doubleToStringDecimalPlaces(m_Width, 0)
            + ","
            + utility::doubleToStringDecimalPlaces(m_Height, 0)
            + ")";
    return output;

}

double Rectangle::calculateArea(){
    return m_Width * m_Height;
}

Shape* Rectangle::clone(){
    Shape* cloned = new Rectangle(m_X, m_Y,m_Width, m_Height);
    return cloned;
}
