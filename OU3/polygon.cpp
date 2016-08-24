using namespace std;
#include <iostream>
#include <cmath>
#include "polygon.h"
#include "../OU2/utility.h"

/**
 * @brief Polygon::Polygon
 * Default constructor
 */
Polygon::Polygon()
{

}

/**
 * @brief Polygon::Polygon
 * Constructor which takes x and y values for centre, an array of the vertices and the size of the array
 * @param x
 * the x value of the centre
 * @param y
 * the y value of the centre
 * @param varr
 * Array of vertices
 * @param num
 * The size of the array
 */
Polygon::Polygon( double x, double y, Vertex *varr, int num){
    this->m_X = x;
    this->m_Y = y;
    numOfVertices = num;
    vertices = new Vertex[num];

    //copy the inserted array into the object property
    for(int i = 0; i < num; i = i + 1 ){
        vertices[i] = varr[i];
    }
}

/**
 * @brief print
 * prints information about the shape
 */
void Polygon::print(){
        cout << getPrintString() << endl;
}

/**
 * @brief Circle::getPrintString
 * generates a representative string of the object
 * @return
 */
string Polygon::getPrintString(){
    string output = "POLYGON: (";
    output += utility::doubleToStringDecimalPlaces(m_X, 0) + ",";
    output += utility::doubleToStringDecimalPlaces(m_Y, 0) + ") ";
    output += "{";
    for(int i = 0; i < numOfVertices; i++){
        output = output + "("
                + vertices[i].getXString(0)
                + "," + vertices[i].getYString(0) + ") ";
    }
    output += "}";
    return output;
}

/**
 * @brief calculateArea
 * Calculates the area of the shape
 * @return
 */
double Polygon::calculateArea(){
    Vertex nextVert, currentVert;
    double areaSum = 0;

    //loop through the vertices
    for(int i = 0; i < numOfVertices; i = i + 1 ){
        currentVert = vertices[i];
        if(i == numOfVertices - 1){ //it's the last vertex, take the first vertex
            nextVert =  vertices[0];
        }
        else{
           nextVert = vertices[i+1]; //it's not the last vertex, take the next vertex
        }

        areaSum += (currentVert.getX()*nextVert.getY()
                    - nextVert.getX()*currentVert.getY()) / 2;
    }
   return abs(areaSum); //compute absolute value to eliminate any negative areas
    return 1;
}

/**
 * @brief Circle::clone
 * Performs a deep copy of the object
 * @return
 * The cloned object
 */
Shape* Polygon::clone(){
    Shape* cloned = new Polygon(m_X, m_Y,vertices,numOfVertices);
    return cloned;
}
