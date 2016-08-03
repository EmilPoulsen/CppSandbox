#include "shapelist.h"
#include "node.h"

ShapeList::ShapeList(){
    _pHead = _pTail = 0;
}

ShapeList::ShapeList( ShapeList& other ){
    _pHead = _pTail = 0;

    Node *current = other._pHead;
    while (current != 0){
        Shape* s = current->getValue();
        this->add(*(s->clone()));
        //s->print();
        current = current->getNext();
    }

}


void ShapeList::remove( const Vertex &v){
    Node *current = _pHead;
    Node *previous = _pHead;

    while (current != 0){ //->getNext() != 0) {
        Shape* s = current->getValue();

        if(s->IsCloseToVertex(v,1))
        {
            break;
            //s->print();
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


ShapeList::ShapeList(Shape &shape){
    _pHead = new Node(shape);
    _pTail = _pHead;
}

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

void ShapeList::print(){
    Node *current = _pHead;
    while (current != 0){ //->getNext() != 0) {
        Shape* s = current->getValue();
        s->print();
        current = current->getNext();
    }


}

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

//destructor
ShapeList::~ShapeList(){

}


