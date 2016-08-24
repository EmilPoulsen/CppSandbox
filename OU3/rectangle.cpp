#include "rectangle.h"
using namespace std;
#include <iostream>
#include "../OU2/utility.h"

/**
 * @brief Rectangle::Rectangle
 * Default constructor. Does nothing atm
 */
Rectangle::Rectangle(){
}

/**
 * @brief Rectangle::Rectangle
 * Constructor which takes the x and y value of the centre, the width and height
 * @param x
 * the x value of the centre
 * @param y
 * the y value of the centre
 * @param width
 * width of the rectangle
 * @param height
 * the height of the rectangle
 */
Rectangle::Rectangle( double x, double y, double width, double height){
    m_X = x;
    m_Y = y;
    m_Width = width;
    m_Height = height;
}

/**
 * @brief print
 * prints information about the shape
 */
void Rectangle::print(){
    cout << getPrintString() << endl;
}

/**
 * @brief Circle::getPrintString
 * generates a representative string of the object
 * @return
 */
string Rectangle::getPrintString(){
    string output = "RECTANGLE: (";

    output += utility::doubleToStringDecimalPlaces(m_X, 0) + ",";
    output += utility::doubleToStringDecimalPlaces(m_Y, 0) + ")";
    output += " (" + utility::doubleToStringDecimalPlaces(m_Width, 0)
            + ","
            + utility::doubleToStringDecimalPlaces(m_Height, 0)
            + ")";
    return output;
}

/**
 * @brief calculateArea
 * Calculates the area of the shape
 * @return
 */
double Rectangle::calculateArea(){
    return m_Width * m_Height;
}

/**
 * @brief Circle::clone
 * Performs a deep copy of the object
 * @return
 * The cloned object
 */
Shape* Rectangle::clone(){
    Shape* cloned = new Rectangle(m_X, m_Y,m_Width, m_Height);
    return cloned;
}
