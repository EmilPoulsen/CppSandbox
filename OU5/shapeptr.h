#ifndef SHAPEPTR_H
#define SHAPEPTR_H
#include "../OU3/shape.h"


class ShapePtr
{
public:
    ShapePtr();
    ShapePtr(Shape* shape);
    ShapePtr( const ShapePtr& other );
    friend std::ostream& operator<<(std::ostream& os, const ShapePtr& p);
    friend std::istream& operator>>(std::istream& is, ShapePtr& sp);
    static Shape* createShapeFromString(string s);
    Shape* getShape() const;
    std::string print() const;
    static Shape* createPolygon(string s);
    static Shape* createCircle(string s);
    static Shape* createRectangle(string s);
    static Shape* createPoint(string s);
    static void getCoordinatesFromString(string s, double &x, double &y);
    bool isCloseTo(Vertex other, double tolerance);
    double getArea() const;
    double getX() const;
    double getY() const;
    ~ShapePtr();
    static int numshapes;


private:
    Shape* m_pShape;
    void incrementShapeCounter();
    void decrementShapeCounter();
};

#endif // SHAPEPTR_H
