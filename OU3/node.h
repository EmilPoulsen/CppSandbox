#ifndef NODE_H
#define NODE_H
#include "shape.h"


class Node
{
    friend class ShapeList;
public:
    /**
     * @brief Node
     * Constructor with no arguments
     */
    Node();

    /**
     * @brief Node
     * Constructors with a given shape
     * @param shape
     */
    Node(Shape &shape);

    /**
     * @brief Node
     *  Constructors with a given value and a link of the next node
     * @param shape
     * @param next
     */
    Node(Shape &shape, Node *next);

    /**
     * @brief getValue
     * Returns the shape of the node
     * @return
     */
    Shape* getValue();

    /**
     * @brief getNext
     * Returns the next node in the linked list
     * @return
     */
    Node* getNext();

    /**
     * @brief setNext
     * Set the next node in the list
     * @param next
     */
    void setNext(Node *next);

private:
    Shape *mShape;
    Node *mNext; /* pointer to the next node */
};

#endif // NODE_H
