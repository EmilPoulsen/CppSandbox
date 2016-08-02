#include "shapelist.h"
#include "node.h"

ShapeList::ShapeList(){
    _pHead = _pTail = 0;
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

//destructor
ShapeList::~ShapeList(){

}


