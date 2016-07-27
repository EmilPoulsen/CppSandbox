#include "Vertex.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

/**
 * @brief Vertex::Vertex
 * Default constructor, x,y = 0.
 */
Vertex::Vertex()
{
    //this->testString = "rufus test";
    X = 0;
    Y = 0;
}

/**
 * @brief Vertex::Vertex
 * Constructor with x and y value
 * @param x
 * x value
 * @param y
 * y value
 */
Vertex::Vertex(double x, double y)
{
    X = x;
    Y = y;
}

/**
 * @brief Vertex::~Vertex
 * deconstructor
 */
Vertex::~Vertex()
{
    //cout << "Nu försvinner punkten med koordinaterna " << int(X) << int(Y) << endl;
}

/**
 * @brief Vertex::getX
 * returns x value of vertex
 * @return
 * x value
 */
double Vertex:: getX(){
    return X;
}

/**
 * @brief Vertex::getY
 * returns y value of vertex
 * @return
 * y value
 */
double Vertex:: getY(){
    return Y;
}

std::string Vertex::getXString(int decimals){
    std::stringstream stream;
    stream << std::fixed << setprecision(decimals) << this->X;
    string s = stream.str();
    return s;
}

std::string Vertex::getYString(int decimals){
    std::stringstream stream;
    stream << std::fixed << setprecision(decimals) << this->Y;
    string s = stream.str();
    return s;
}



