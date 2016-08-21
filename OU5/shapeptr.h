#ifndef SHAPEPTR_H
#define SHAPEPTR_H
#include "../OU3/shape.h"


class ShapePtr
{
public:
    ShapePtr();
    ShapePtr(Shape* shape);
    ~ShapePtr();
private:
    Shape* m_pShape;
};

#endif // SHAPEPTR_H
