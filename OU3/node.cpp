#include "node.h"
#include "shape.h"


Node::Node() : mNext(nullptr){

}

Node::Node(Shape &shape)
    :mShape(shape), mNext(nullptr){
}

Node::Node(Shape &shape, Node *next)
    :mShape(shape), mNext(next){
}

Shape& Node::getValue(){
    return mShape;
}

Node* Node::getNext(){
    return mNext;
}

void Node::setNext(Node *next){
    this->mNext = next;
}
