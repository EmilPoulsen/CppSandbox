#ifndef SHAPEPTR_H
#define SHAPEPTR_H
#include "../OU3/shape.h"


class ShapePtr
{
public:
    ShapePtr();
    ShapePtr(Shape* shape);
    friend std::ostream & operator<<(std::ostream& os, const ShapePtr& p);
    Shape* getShape() const;
    std::string print() const;
    ~ShapePtr();
private:
    Shape* m_pShape;
};

#endif // SHAPEPTR_H
