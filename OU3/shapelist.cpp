#include "shapelist.h"
#include "node.h"

/**
 * @brief ShapeList
 * Constructors with No Arguments
 */
ShapeList::ShapeList(){
    _pHead = _pTail = 0;
}

/**
 * @brief ShapeList::ShapeList
 * Constructor with a shape as input
 * @param shape
 */
ShapeList::ShapeList(Shape &shape){
    _pHead = new Node(shape);
    _pTail = _pHead;
}

/**
 * @brief ShapeList
 * Constructors with a given value of a list node
 * @param shape
 */
ShapeList::ShapeList( ShapeList& other ){
    _pHead = _pTail = 0;
    Node *current = other._pHead;
    while (current != 0){
        Shape* s = current->getValue();
        this->add(*(s->clone()));
        current = current->getNext();
    }
}

/**
 * @brief ShapeList::remove
 * Removes a shape in the linked list if it's closer than 1 to a given vertex
 * @param v
 * The vertex to check against.
 */
void ShapeList::remove( const Vertex &v){
    Node *current = _pHead;
    Node *previous = _pHead;
    while (current != 0){ //traverse the list.
        Shape* s = current->getValue();
        if(s->IsCloseToVertex(v,1)){
            break;
        }
        previous = current;
        current = current->getNext();
    }
    if(current == _pHead){
        _pHead = _pHead->getNext();
    }
    else{
        previous->setNext(current->getNext());
    }
}

/**
 * @brief add
 * Adds a shape to the linked list
 * @param shape
 * The shape to add
 */
void ShapeList::add(Shape &shape){
    if(_pHead == 0){
        _pHead = new Node(shape);
        _pTail = _pHead;
    }
    else{
        Node *current = _pHead;
        while (current->getNext() != 0) {
            current = current->getNext();
        }
        Node *newNode = new Node(shape);
        current->setNext(newNode);
    }
}

/**
 * @brief print
 * Prints the content of the linked list
 */
void ShapeList::print(){
    Node *current = _pHead;
    while (current != 0){ //->getNext() != 0) {
        Shape* s = current->getValue();
        s->print();
        current = current->getNext();
    }
}

/**
 * @brief ShapeList::area
 * Calculates the total area for all shapes in the list.
 * @return
 */
double ShapeList::area(){
    double totArea = 0;
    Node *current = _pHead;
    while (current != 0){ //->getNext() != 0) {
        Shape* s = current->getValue();
        totArea +=s->area();
        current = current->getNext();
    }
    return totArea;
}

/**
 * @brief ShapeList::~ShapeList
 * Default destructor
 */
ShapeList::~ShapeList(){
}


