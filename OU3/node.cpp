#include "node.h"
#include "shape.h"

/**
 * @brief Node
 * Constructor with no arguments
 */
Node::Node() : mNext(nullptr){
}

/**
 * @brief Node
 * Constructors with a given shape
 * @param shape
 */
Node::Node(Shape &shape)
    :mShape(&shape), mNext(nullptr){
}

/**
 * @brief Node
 *  Constructors with a given value and a link of the next node
 * @param shape
 * @param next
 */
Node::Node(Shape &shape, Node *next)
    :mShape(&shape), mNext(next){
}

/**
 * @brief getValue
 * Returns the shape of the node
 * @return
 */
Shape* Node::getValue(){
    return mShape;
}

/**
 * @brief getNext
 * Returns the next node in the linked list
 * @return
 */
Node* Node::getNext(){
    return mNext;
}

/**
 * @brief setNext
 * Set the next node in the list
 * @param next
 */
void Node::setNext(Node *next){
    this->mNext = next;
}
