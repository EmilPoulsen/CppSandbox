#ifndef NODE_H
#define NODE_H
#include "shape.h"


class Node
{
public:
    Node();
    Node(Shape shape);
private:
    Shape *mShape;
    Node *mNext; /* pointer to the next node */
};

#endif // NODE_H
