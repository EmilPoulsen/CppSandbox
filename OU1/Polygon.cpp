#include "Polygon.h"
#include <cmath>
using namespace std;
/**
 * @brief Polygon::Polygon
 * default constructor
 */
Polygon::Polygon()
{
    numOfVertices = 0;
    vertices = new Vertex[0]; //initialize pointer
}



/**
  * @brief Polygon::Polygon
  * constructor with vertices as input
  * @param v1
  * the array of vertices
  * @param arrSize
  * the amount of vertices in the polygon
  */
 Polygon::Polygon(Vertex v1[], int arrSize)
 {
     numOfVertices = arrSize;
     vertices = new Vertex[arrSize];

     //copy the inserted array into the object property
     for(int i = 0; i < arrSize; i = i + 1 )
     {
         vertices[i] = v1[i];
     }
 }

 Polygon::Polygon(const Polygon &other)
 {
     numOfVertices = other.numOfVertices;
     vertices = new Vertex[other.numOfVertices];

     for (int i = 0; i < other.numOfVertices; ++i) {
         vertices[i] = other.vertices[i];
     }
 }

 /**
  * @brief Polygon::calcArea
  * Calculates the area of the polygon
  * @return
  * returns the area in the same unit as the vertices
  */
 double Polygon:: calcArea() const {
     Vertex nextVert, currentVert;
     double areaSum = 0;

     //loop through the vertices
     for(int i = 0; i < numOfVertices; i = i + 1 )
     {
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
 }

 /**
  * @brief Polygon::add
  * Adds a vertex in the polygon
  * @param v
  * The vertex to add
  */
 void Polygon:: add(Vertex v){

     Vertex *newArr = new Vertex[numOfVertices + 1];

     for(int i = 0; i < numOfVertices; i = i + 1 )
     {
         newArr[i] = vertices[i]; // copy the allocated memory
     }
     newArr[numOfVertices] = v;
     delete [] vertices;
     vertices = newArr;

     numOfVertices++;
 }

 /**
  * @brief Polygon::area
  * Returns the area of the polygon
  * @return
  * returns the area in the same unit as the vertices
  */
 double Polygon::  area() const {
     return calcArea();
 }

 /**
  * @brief Polygon::minx
  * Calculates the minimum cartesian x value in the polygon
  * @return
  * minimum x value
  */
 double Polygon::minx(){
     double minX = vertices[0].getX(); //start with assigning the first vert as min
     for(int i = 1; i < numOfVertices; i++){
         double currX = vertices[i].getX();
         if(currX < minX){
             minX = currX;
         }
     }
     return minX;
 }

 /**
  * @brief Polygon::maxx
  * Calculates the maximum cartesian x value in the polygon
  * @return
  * maximum x value
  */
 double Polygon::maxx(){
     double maxX = vertices[0].getX(); //start with assigning the first vert as max
     for(int i = 1; i < numOfVertices; i++){
         double currX = vertices[i].getX();
         if(currX > maxX){
             maxX = currX;
         }
     }
     return maxX;
 }

 /**
  * @brief Polygon::miny
  * Calculates the minimum cartesian y value in the polygon
  * @return
  * minimum y value
  */
 double Polygon:: miny(){
     double minY= vertices[0].getY(); //start with assigning the first vert as min
     for(int i = 1; i < numOfVertices; i++){
         double currY = vertices[i].getY();
         if(currY < minY){
             minY = currY;
         }
     }
     return minY;
 }

 /**
  * @brief Polygon::maxy
  * Calculates the maximum cartesian y value in the polygon
  * @return
  * maximum y value
  */
 double Polygon::maxy(){
     double maxY = vertices[0].getY(); //start with assigning the first vert as max
     for(int i = 1; i < numOfVertices; i++){
         double currY = vertices[i].getY();
         if(currY > maxY){
             maxY = currY;
         }
     }
     return maxY;
 }

 /**
  * @brief Polygon::numVertices
  * returns the number of vertices in the polygon
  * @return
  * the number of vertices in the polygon
  */
 int Polygon::numVertices(){
    return numOfVertices;
 }

 string Polygon::print() const {
     string output = "{";
     for(int i = 0; i < numOfVertices; i++){
         //output += vertices[i].getXString(1) + ",";
         output = output + "(" + vertices[i].getXString(0) + "," + vertices[i].getYString(0) + ") ";
     }
     output += "}";
     return output;
 }

 /**
  * @brief Polygon::~Polygon
  * Deconstructor. Deletes all vertices
  */
 Polygon::~Polygon()
 {
     delete [] vertices;
 }

 /**
 * @brief operator <<
 * outputs print() to the console
 * @param os
 * @param v
 * @return
 */
std::ostream & operator<<(std::ostream& os, const Polygon& v){
     os << v.print();
     return os;
 }

/**
 * @brief operator <
 * Compares the areas of the polygons
 * @param c1
 * first polygon
 * @param c2
 * second polygon
 * @return
 */
bool operator< (const Polygon &c1, const Polygon &c2)
{
    return (c1.area()< c2.area());
}

/**
 * @brief operator >
 * Compares the areas of the polygons
 * @param c1
 * first polygon
 * @param c2
 * second polygon
 * @return
 */
bool operator> (const Polygon &c1, const Polygon &c2)
{
    return (c1.area()> c2.area());
}


