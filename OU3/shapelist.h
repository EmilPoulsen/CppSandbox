#ifndef SHAPELIST_H
#define SHAPELIST_H
#include "shape.h"
#include "node.h"


class ShapeList : public Shape
{
private:
    Node *_pHead; // pointer of head node
    Node *_pTail; // pointer of tail node
public:
    ShapeList();
    ShapeList(Shape shape);
};

#endif // SHAPELIST_H
