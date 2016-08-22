#include "shapeptr.h"
#include "../OU3/vertex.h"
#include "../OU3/polygon.h"
#include "../OU3/shape.h"
#include "../OU3/circle.h"
#include "../OU3/rectangle.h"
#include "../OU3/point.h"
#include <string>
#include <iostream>
#include <algorithm>


ShapePtr::ShapePtr()
    : m_pShape(0)
{

}

ShapePtr::ShapePtr(Shape* shape)
    : m_pShape(shape)
{
}

ShapePtr::~ShapePtr(){
    //delete m_pShape;
}

Shape* ShapePtr::getShape() const{
    return m_pShape;
}

std::string ShapePtr::print() const {
    return m_pShape->getPrintString();
}

std::ostream & operator<<(std::ostream& os, const ShapePtr& v){
     os << v.print();
     return os;
 }

std::istream& operator>>(std::istream& is, ShapePtr& sp){
    Shape* newShape;
    string s;
    istream& localis = std::getline(is, s);
    newShape = ShapePtr::createShapeFromString(s);
    sp.m_pShape = newShape;
    return localis;
}

Shape* ShapePtr::createShapeFromString(string s){
    string type = s.substr(0,3);
    Shape* newShape;
    if(type == "POL"){
        //newShape = createPolygon(s);
    }
    else if(type == "CIR"){
        newShape = createCircle(s);
    }
    else if(type == "REC"){

    }
    else if(type == "POI"){

    }
    else{
        newShape = nullptr;
    }
    return newShape;
}

//Example of format: "POLYGON: (1,4) {(0,0) (10,0) (5,2) (5,5) }"
Shape* ShapePtr::createPolygon(string s){
    //find the centre coordinates in the string
    int iFirstLeftParenthesis = s.find_first_of("("); //9
    int iFirstRightParenthesis = s.find_first_of(")"); //9
    int endCutOfCentreString = iFirstRightParenthesis - iFirstLeftParenthesis +1;
    string strCentre = s.substr(iFirstLeftParenthesis, endCutOfCentreString);
    double x, y;
    getCoordinatesFromString(strCentre, x,y);

    //find the vertex part of the string
   int iFirstLeftBracket = s.find_first_of("{"); //9
   int iFirstRightBracket= s.find_first_of("}"); //9
   int endCutOfVertexString = s.length() - iFirstLeftBracket-3;
   string vertices = s.substr(iFirstLeftBracket + 1, endCutOfVertexString);

   //there could be an arbitrary number of vertices, needs iteration.
   bool allVerticesFound = false;
   vector<Vertex> vList;
   while(!allVerticesFound){
       int iStart = vertices.find_first_of("("); //find the first left bracket
       if(iStart == -1){ //no vertices left!
           allVerticesFound = true;
       }
       else{
           int iEnd = vertices.find_first_of(")");
           string currVertex = vertices.substr(iStart, iEnd - iStart + 1);
           double currX, currY;
           getCoordinatesFromString(currVertex, currX,currY);
           Vertex v(0,0); //create the vertex
           vList.push_back(v); //add to list
           if(iEnd + 2 >= vertices.length()){
               allVerticesFound = true;
           }
           else{
               //cut the string for the next iteration
               vertices = vertices.substr(iEnd + 2, vertices.length() - iEnd - 2);
           }
       }
   }
   Vertex* varr =  &vList[0]; //convert to array
   return new Polygon(x, y, varr, vList.size() ); //create and return the polygon
}

//comes in form of "(1,4)"
 void ShapePtr::getCoordinatesFromString(string str, double &x, double &y){
    str.erase(std::remove(str.begin(), str.end(), '('), str.end());
    str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
    int posOfComma = str.find_first_of(",");
    string sX = str.substr(0, posOfComma);
    string sY = str.substr(posOfComma + 1, str.length() - posOfComma);
    x =   atof(sX.c_str());
    y = atof(sY.c_str());
}

//CIRCLE: (5,5) 4
Shape* ShapePtr::createCircle(string s){
    /*
    double x = atof(s.substr(9,10).c_str());
    double y = atof(s.substr(12,13).c_str());
    double r = atof(s.substr(15,16).c_str());
    return new Circle(x, y, r);
    */
}

//RECTANGLE: (4,10) (2,4)
Shape* ShapePtr::createRectangle(string s){
    double x = atof(s.substr(12,13).c_str());
    double y = atof(s.substr(12,13).c_str());


    //Rectangle( double x, double y, double width, double height);
}
//POINT: (6,7) 1
Shape* ShapePtr::createPoint(string s){

}

