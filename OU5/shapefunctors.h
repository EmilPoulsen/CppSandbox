#ifndef SHAPEFUNCTORS_H
#define SHAPEFUNCTORS_H
#include "shapeptr.h"

class CloseTo{
public:
    CloseTo(Vertex v){
        m_Vertex = v;
    }

    bool operator()(ShapePtr shapePointer){
        return shapePointer.isCloseTo(m_Vertex,1);
    }
private:
    Vertex m_Vertex;
};

struct SortByAreaKey
{
    inline bool operator() (const ShapePtr& shape1, const ShapePtr& shape2)
    {
        return (shape1.getArea() < shape2.getArea());
    }
};

struct SortByXkey
{
    inline bool operator() (const ShapePtr& shape1, const ShapePtr& shape2)
    {
        return (shape1.getX() < shape2.getY());
    }
};

struct SortByYkey
{
    inline bool operator() (const ShapePtr& shape1, const ShapePtr& shape2)
    {
        return (shape1.getY() < shape2.getY());
    }
};

#endif // SHAPEFUNCTORS_H
