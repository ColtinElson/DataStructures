#ifndef ASSIGNMENT4_NODE_H
#define ASSIGNMENT4_NODE_H

#include <iostream>

using namespace std;

class Node;

typedef Node* NodePointer;

class Node
{


public:
    string data;
    NodePointer left;
    NodePointer right;
    int height;

    Node() : data(""), left(nullptr), right(nullptr), height(0) {};
};


#endif //ASSIGNMENT4_NODE_H
