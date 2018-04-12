#ifndef ASSIGNMENT4_NODE_H
#define ASSIGNMENT4_NODE_H

class Node;

typedef Node* NodePointer;

class Node
{


public:
    int data;
    NodePointer left;
    NodePointer right;

    Node() : data(0), left(nullptr), right(nullptr) {};
};


#endif //ASSIGNMENT4_NODE_H
