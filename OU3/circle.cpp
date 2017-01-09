#include "circle.h"
using namespace std;
#include <iostream>
#include "../OU2/utility.h"
#include <math.h>

Circle::Circle(){
}

Circle::Circle( double x, double y, double radie){
    m_X = x;
    m_Y = y;
    this->m_Radius = radie;
}

/**
 * @brief print
 * prints information about the shape
 */
void Circle::print(){
        cout << getPrintString() << endl;
}

/**
 * @brief Circle::getPrintString
 * generates a representative string of the object
 * @return
 */
string Circle::getPrintString(){
    string output = "CIRCLE: (";
    output += utility::doubleToStringDecimalPlaces(m_X, 0) + ",";
    output += utility::doubleToStringDecimalPlaces(m_Y, 0) + ")";
    output += " ";
    output += utility::doubleToStringDecimalPlaces(m_Radius, 0);
    return output;
}

/**
 * @brief calculateArea
 * Calculates the area of the shape
 * @return
 */
double Circle::calculateArea(){
    return m_Radius * m_Radius * M_PI;
}

/**
 * @brief Circle::clone
 * Performs a deep copy of the object
 * @return
 * The cloned object
 */
Shape* Circle::clone() const{
    Shape* cloned = new Circle(m_X, m_Y, m_Radius);
    return cloned;
}

