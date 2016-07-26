#include "Vertex.h"
#include <iostream>

using namespace std;

/**
 * @brief Vertex::Vertex
 * Default constructor, x,y = 0.
 */
Vertex::Vertex()
{
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



