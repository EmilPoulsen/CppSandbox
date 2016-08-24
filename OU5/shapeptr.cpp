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

/**
 * @brief ShapePtr::numshapes
 * Static class field for counting the number of instances created of ShapePtr
 */
int ShapePtr::numshapes;

/**
 * @brief ShapePtr::ShapePtr
 * Default constructor
 */
ShapePtr::ShapePtr()
    : m_pShape(0){
}

/**
 * @brief ShapePtr::ShapePtr
 * Constructor with the containing shape as argument
 * @param shape
 */
ShapePtr::ShapePtr(Shape* shape)
    : m_pShape(shape){
}

/**
 * @brief ShapePtr::ShapePtr
 * Copy constructor. Will increment numshapes
 * @param other
 * The instance of ShapePtr to copy
 */
ShapePtr::ShapePtr(const ShapePtr &other)
    :m_pShape(other.m_pShape){
    incrementShapeCounter();
}

/**
 * @brief ShapePtr::~ShapePtr
 * Default deconstructor. Will decrement numshapes
 */
ShapePtr::~ShapePtr(){
    decrementShapeCounter();
    //delete m_pShape;
}

/**
 * @brief ShapePtr::incrementShapeCounter
 * Method to call to increment instance counter
 */
void ShapePtr::incrementShapeCounter(){
    numshapes++;
}

/**
 * @brief ShapePtr::decrementShapeCounter
 * Method to call to decrement instance counter
 */
void ShapePtr::decrementShapeCounter(){
    numshapes--;
}

/**
 * @brief ShapePtr::getShape
 * Returns a pointer to the contained object
 * @return
 *
 */
Shape* ShapePtr::getShape() const{
    return m_pShape;
}

/**
 * @brief ShapePtr::print
 * Returns a string containing information about the shape. Direct call to Shape::print()
 * @return
 */
std::string ShapePtr::print() const {
    return m_pShape->getPrintString();
}

/**
 * @brief operator <<
 * Implementation of out stream operator
 * @param os
 * @param v
 * @return
 */
std::ostream & operator<<(std::ostream& os, const ShapePtr& v){
     os << v.print();
     return os;
 }

/**
 * @brief operator >>
 * Implementation of instream operator. Will create a new instance based on text input
 * @param is
 * @param sp
 * @return
 */
std::istream& operator>>(std::istream& is, ShapePtr& sp){
    Shape* newShape;
    string s;
    istream& localis = std::getline(is, s);
    newShape = ShapePtr::createShapeFromString(s);
    sp.m_pShape = newShape;
    return localis;
}

/**
 * @brief ShapePtr::createShapeFromString
 * Creates a polymorphic instance of shape based on text input "POL", "CIR", "REC" or "POI"
 * @param s
 * The input string. See implementation of print() in the different shapes for exact formatting
 * @return
 */
Shape* ShapePtr::createShapeFromString(string s){
    string type = s.substr(0,3);
    Shape* newShape;
    if(type == "POL"){
        newShape = createPolygon(s);
    }
    else if(type == "CIR"){
        newShape = createCircle(s);
    }
    else if(type == "REC"){
        newShape = createRectangle(s);
    }
    else if(type == "POI"){
        newShape = createPoint(s);
    }
    else{
        newShape = nullptr;
    }
    return newShape;
}


//TODO: break up this function in smaller portions..
/**
 * @brief ShapePtr::createPolygon
 * Creates an instance of polygon including its vertices based on text input
 * @param s
 * Input string. Example of format: "POLYGON: (1,4) {(0,0) (10,0) (5,2) (5,5) }"
 * @return
 */
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
           Vertex v(currX,currY); //create the vertex
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

/**
  * @brief ShapePtr::getCoordinatesFromString
  * Transforms a string containing coordinates to a pair of double x and y values
  * @param str
  * The input string of the coordinates. comes in form of "(1,4)"
  * @param x
  * The x value transformed to a double (reference)
  * @param y
  * The y value transformed to a double (reference)
  */
 void ShapePtr::getCoordinatesFromString(string str, double &x, double &y){
    str.erase(std::remove(str.begin(), str.end(), '('), str.end());
    str.erase(std::remove(str.begin(), str.end(), ')'), str.end());
    int posOfComma = str.find_first_of(",");
    string sX = str.substr(0, posOfComma);
    string sY = str.substr(posOfComma + 1, str.length() - posOfComma);
    x =   atof(sX.c_str());
    y = atof(sY.c_str());
}

//
 /**
 * @brief ShapePtr::createCircle
 * Creates an instance of a circle based on text input
 * @param s
 * The input string of the coordinates. Comes in the form of a "CIRCLE: (5,5) 4"
 * @return
 * The generated circle
 */
Shape* ShapePtr::createCircle(string s){
    //get the radius in the last position of the input string.
    string sRadius = s.substr(s.length() - 1, 1);
    double r = atof(sRadius.c_str());
    int vStart = s.find_first_of("(");
    int vEnd = s.find_first_of(")");
    string currVertex = s.substr(vStart, vEnd - vStart + 1);
    double x, y;
    getCoordinatesFromString(currVertex, x,y);
    // cout << currVertex << endl;
     return new Circle(x, y, r);
}

/**
 * @brief ShapePtr::createRectangle
 * Creates an instance of a rectangle based on text input
 * @param s
 * The input string. Comes in the form of "RECTANGLE: (4,10) (2,4)"
 * @return
 */
Shape* ShapePtr::createRectangle(string s){
    double x, y, width, height;
    for(int i = 0; i < 2; i++){ //same procedure for both coordinates and dimesion, so why not loop it..
        int iStart = s.find_first_of("(");
        int iEnd = s.find_first_of(")");
        string currVertex = s.substr(iStart, iEnd - iStart + 1);
        //cout << currVertex << endl;
        if(i == 0){
            getCoordinatesFromString(currVertex, x,y);
            s = s.substr(iEnd + 2, s.length() - iEnd - 2);
        }
        else if(i == 1){
            getCoordinatesFromString(currVertex, width,height);
            break;
        }
        else{}//should never hit this point.
    }
    return new Rectangle(x, y, width, height);
}

/**
 * @brief ShapePtr::createPoint
 * Creates an instance of a point based on text input
 * @param s
 * The input string. Comes in form of "POINT: (6,7) 1"
 * @return
 */
Shape* ShapePtr::createPoint(string s){ //essentially the same code as createCircle
    //get the radius in the last position of the input string.
    string sRadius = s.substr(s.length() - 1, 1);
    double size = atof(sRadius.c_str());
    int vStart = s.find_first_of("(");
    int vEnd = s.find_first_of(")");
    string currVertex = s.substr(vStart, vEnd - vStart + 1);
    double x, y;
    getCoordinatesFromString(currVertex, x,y);
    // cout << currVertex << endl;
     return new Point(x, y, size);
}

/**
 * @brief ShapePtr::isCloseTo
 * Checks if the containing shape is closer to a given vertex based on a tolerance
 * @param vertex
 * The vertex to check against
 * @param tolerance
 * @return
 * True if the shape is within the tolerance, false if not.
 */
bool ShapePtr::isCloseTo(Vertex vertex, double tolerance){
    return m_pShape->IsCloseToVertex(vertex, 1);
}

/**
 * @brief ShapePtr::getArea
 * Get the area of the contained shape
 * @return
 */
double ShapePtr::getArea() const{
    return m_pShape->area();
}

/**
 * @brief ShapePtr::getX
 * Get the x value (centre) of the contained shape
 * @return
 */
double ShapePtr::getX() const{
    return m_pShape->getX();
}

/**
 * @brief ShapePtr::getY
 * Get the y value (centre) of the contained shape
 * @return
 */
double ShapePtr::getY() const{
    return m_pShape->getY();
}

