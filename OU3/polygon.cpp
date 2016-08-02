using namespace std;
#include <iostream>
#include "polygon.h"
#include "../OU2/utility.h"

Polygon::Polygon()
{

}
Polygon::Polygon( double x, double y, Vertex *varr, int num){
    this->m_X = x;
    this->m_Y = y;
    numOfVertices = num;
    vertices = new Vertex[num];

    //copy the inserted array into the object property
    for(int i = 0; i < num; i = i + 1 )
    {
        vertices[i] = varr[i];
    }

}

void Polygon::print(){
    string output = "POLYGON: (";
    output += utility::doubleToStringDecimalPlaces(m_X, 0) + ",";
    output += utility::doubleToStringDecimalPlaces(m_Y, 0) + ") ";
    //output += utility::doubleToStringDecimalPlaces(this->m_X,0) + ",";
    //output += utility::doubleToStringDecimalPlaces(this->m_Y,0) + ") ";

        output += "{";
        for(int i = 0; i < numOfVertices; i++){
            output = output + "("
                    + vertices[i].getXString(0)
                    + "," + vertices[i].getYString(0) + ") ";
        }
        output += "}";
        cout << output << endl;


            //cout << "hi from polygon" << endl;

}
