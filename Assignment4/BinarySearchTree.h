#ifndef ASSIGNMENT4_BINARYSEARCHTREE_H
#define ASSIGNMENT4_BINARYSEARCHTREE_H

#include "Node.h"
#include <iostream>
#include <iomanip>

using namespace std;

class BinarySearchTree
{
private:
    NodePointer root;

public:
    BinarySearchTree() : root(nullptr) {}

    void Insert(int number);

    void Insert(int number, NodePointer &node);

    void Remove(int number);

    void PrintTree(ostream& output, NodePointer &node, int indent);

    friend ostream& operator<< (ostream &output, BinarySearchTree &binarySearchTree);

};


#endif //ASSIGNMENT4_BINARYSEARCHTREE_H
