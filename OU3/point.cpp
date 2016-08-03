using namespace std;

#include <iostream>
#include "point.h"
#include "../OU2/utility.h"
#include "../OU2/utility.cpp"

Point::Point()
{

}
Point::Point(double x, double y, double size)
{
    m_X = x;
    m_Y = y;
    m_Size = size;
}

void Point::print(){
    string output = "POINT: (";
    output += utility::doubleToStringDecimalPlaces(m_X, 0) + ", ";
    output += utility::doubleToStringDecimalPlaces(m_Y, 0) + ")";
    output += " "
            + utility::doubleToStringDecimalPlaces(m_Size, 0);

            cout << output << endl;
}

double Point::calculateArea(){
    return m_Size;
}

Shape* Point::clone(){
    Shape* cloned = new Point(m_X, m_Y, m_Size);
    return cloned;
}
