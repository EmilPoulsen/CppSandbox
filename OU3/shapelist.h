#ifndef SHAPELIST_H
#define SHAPELIST_H
#include "shape.h"
#include "node.h"
#include "vertex.h"


class ShapeList
{
public:
    ShapeList();
    ShapeList(Shape &shape);
    void remove( const Vertex &v);
    ShapeList( ShapeList& other );
    void add(Shape &shape);
    void print();
    double area();
    ~ShapeList();//Destructor
private:
    Node *_pHead; // pointer of head node
    Node *_pTail; // pointer of tail node
};

#endif // SHAPELIST_H
