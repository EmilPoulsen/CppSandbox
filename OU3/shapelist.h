#ifndef SHAPELIST_H
#define SHAPELIST_H
#include "shape.h"
#include "node.h"
#include "vertex.h"


class ShapeList
{
private:
    Node *_pHead; // pointer of head node
    Node *_pTail; // pointer of tail node
public:
    /**
     * @brief ShapeList
     * Constructors with No Arguments
     */
    ShapeList();

    /**
     * @brief ShapeList
     * Constructors with a given value of a list node
     * @param shape
     */
    ShapeList(Shape &shape);

    void remove( const Vertex &v);

    ShapeList( ShapeList& other );

    /**
     * @brief add
     * Adds a shape to the linked list
     * @param shape
     * The shape to add
     */
    void add(Shape &shape);

    /**
     * @brief print
     * Prints the content of the linked list
     */
    void print();

    double area();


    //Destructor
    ~ShapeList();


};

#endif // SHAPELIST_H
