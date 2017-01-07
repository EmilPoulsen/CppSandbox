#ifndef NODE_H
#define NODE_H
#include "shape.h"


class Node
{
    friend class ShapeList;
public:
    Node();
    ~Node();
    Node(Shape &shape);
    Node(Shape &shape, Node *next);
    Shape* getValue();
    Node* getNext();
    void setNext(Node *next);
private:
    Shape *mShape;
    Node *mNext; /* pointer to the next node */
};

#endif // NODE_H
