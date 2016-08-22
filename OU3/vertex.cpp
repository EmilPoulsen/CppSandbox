#include "Vertex.h"
#include <iostream>
#include <sstream>
#include <iomanip>
#include<math.h> //for pow

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

bool Vertex::isCloseTo(Vertex other, double tolerance){
    return distanceTo(other) < tolerance;
}

/**
 * @brief Vertex::distanceTo
 * Euclidean distance
 * @param other
 * @return
 */
double Vertex::distanceTo(Vertex other)
{
    double x = X - other.getX(); //calculating number to square in next step
    double y = Y - other.getY();
    double dist = pow(x, 2) + pow(y, 2);       //calculating Euclidean distance
    dist = sqrt(dist);
    return dist;
}
