using namespace std;

#include <iostream>
#include "point.h"
#include "../OU2/utility.h"
#include "../OU2/utility.cpp"

Point::Point(){

}

Point::Point(double x, double y, double size){
    m_X = x;
    m_Y = y;
    m_Size = size;
}

/**
 * @brief print
 * prints information about the shape
 */
void Point::print(){
    cout << getPrintString() << endl;
}

/**
 * @brief Circle::getPrintString
 * generates a representative string of the object
 * @return
 */
string Point::getPrintString(){
    string output = "POINT: (";
    output += utility::doubleToStringDecimalPlaces(m_X, 0) + ",";
    output += utility::doubleToStringDecimalPlaces(m_Y, 0) + ")";
    output += " "
            + utility::doubleToStringDecimalPlaces(m_Size, 0);
    return output;
}

/**
 * @brief calculateArea
 * Calculates the area of the shape
 * @return
 */
double Point::calculateArea(){
    return m_Size;
}

/**
 * @brief Circle::clone
 * Performs a deep copy of the object
 * @return
 * The cloned object
 */
Shape* Point::clone(){
    Shape* cloned = new Point(m_X, m_Y, m_Size);
    return cloned;
}

