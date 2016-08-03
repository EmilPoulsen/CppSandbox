#ifndef VERTEX_H
#define VERTEX_H
#include <iostream>
using namespace std;


class Vertex
{
public:
    Vertex();
    Vertex(double x, double y);
    ~Vertex(); // destruktor
    double getX() const;
    double getY() const;
    std::string getXString(int decimals) ;
    std::string getYString(int decimals) ;
    //string testString;
private:
    double X;
    double Y;
};

#endif // VERTEX_H
