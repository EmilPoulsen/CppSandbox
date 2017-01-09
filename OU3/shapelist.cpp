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
        //don't clone since the object is being cloned
        //in the add method.
        this->add(*s);//this->add(*(s->clone()));
        current = current->getNext();
    }
}

/**
 * @brief ShapeList::remove
 * Removes a shape in the linked list if it's
 * closer than 1 to a given vertex
 * @param v
 * The vertex to check against.
 */
void ShapeList::remove( const Vertex &v){
    Node *current = _pHead;
    Node *previous = _pHead;
    //find which one to delete
    while (current != 0){ //traverse the list.
        Shape* s = current->getValue();
        if(s->IsCloseToVertex(v,1)){
            break;
        }
        previous = current;
        current = current->getNext();
    }
    //delete it
    if(current == _pHead){
        Node *toBeDeleted = _pHead;
        _pHead = _pHead->getNext(); //bypass
        delete toBeDeleted; //delete it
    }
    else{
        previous->setNext(current->getNext()); //bypass
        delete current; //delete current
    }
}

/**
 * @brief add
 * Adds a shape to the linked list
 * @param shape
 * The shape to add
 */
void ShapeList::add(Shape const &shape){

    if(_pHead == 0){
        _pHead = new Node(*(shape.clone()));//clone shape before creating new
        _pTail = _pHead;
    }
    else{
        Node *current = _pHead;
        while (current->getNext() != 0) {
            current = current->getNext();
        }
        Node *newNode = new Node(*(shape.clone()));//clone shape before creating new
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
    //iterate through the linked list and
    //free the memory of the nodes.
    Node *current = _pHead;
    while (current != 0){
        Node *toBeDeleted = current;
        current = current->getNext();
        delete toBeDeleted;
    }
}
