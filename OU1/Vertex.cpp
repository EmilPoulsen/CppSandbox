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
    X = 99;
    Y = 99;
}

Vertex::Vertex(const Vertex& other ) :
   X(other.getX()), Y(other.getY())
{}

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
    //cout << "Nu försvinner punkten med koordinaterna " << int(X) << ", " << int(Y) << endl;
}

/**
 * @brief Vertex::getX
 * returns x value of vertex
 * @return
 * x value
 */
double Vertex:: getX() const{
    return X;
}

/**
 * @brief Vertex::getY
 * returns y value of vertex
 * @return
 * y value
 */
double Vertex:: getY() const{
    return Y;
}

std::string Vertex::getXString(int decimals) const{
    std::stringstream stream;
    //stream << "X value";
    stream << std::fixed << setprecision(decimals) << X;
    string s = stream.str();
    return s;
}

std::string Vertex::getYString(int decimals) const{
    std::stringstream stream;
    //stream << "Y value";
    stream << std::fixed << setprecision(decimals) << Y;
    string s = stream.str();
    return s;
}



