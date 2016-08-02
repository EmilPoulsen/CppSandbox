#include "circle.h"
using namespace std;
#include <iostream>
#include "../OU2/utility.h"

Circle::Circle()
{

}

Circle::Circle( double x, double y, double radie){
    m_X = x;
    m_Y = y;
    this->m_Radius = radie;

}

void Circle::print(){
    string output = "CIRCLE: (";
    output += utility::doubleToStringDecimalPlaces(m_X, 0) + ", ";
    output += utility::doubleToStringDecimalPlaces(m_Y, 0) + ")";
    output += " ";
    output += utility::doubleToStringDecimalPlaces(m_Radius, 0);


        cout << output << endl;
}
