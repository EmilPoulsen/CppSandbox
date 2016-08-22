#include "circle.h"
using namespace std;
#include <iostream>
#include "../OU2/utility.h"
#include <math.h>

Circle::Circle()
{

}

Circle::Circle( double x, double y, double radie){
    m_X = x;
    m_Y = y;
    this->m_Radius = radie;

}

void Circle::print(){
        cout << getPrintString() << endl;
}

string Circle::getPrintString(){
    string output = "CIRCLE: (";
    output += utility::doubleToStringDecimalPlaces(m_X, 0) + ",";
    output += utility::doubleToStringDecimalPlaces(m_Y, 0) + ")";
    output += " ";
    output += utility::doubleToStringDecimalPlaces(m_Radius, 0);
    return output;

}

    double Circle::calculateArea(){
        return m_Radius * m_Radius * M_PI;//this->;
    }

Shape* Circle::clone(){
    Shape* cloned = new Circle(m_X, m_Y, m_Radius);
    return cloned;
}

