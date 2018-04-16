#ifndef ASSIGNMENT4_BINARYSEARCHTREE_H
#define ASSIGNMENT4_BINARYSEARCHTREE_H

#include "Node.h"
#include <iostream>
#include <iomanip>

using namespace std;

class BinarySearchTree
{
private:

    void SingleRightRotate(NodePointer &node);

    void SingleLeftRotate(NodePointer &node);

    void DoubleRightRotate(NodePointer &node);

    void DoubleLeftRotate(NodePointer &node);

    int HeightOf(NodePointer &node);

public:
    NodePointer root;

    BinarySearchTree() : root(nullptr) {}

    void Insert(string value);

    void Insert(string value, NodePointer &node);

    void Search(string value, NodePointer &node);

    void PrintTree(ostream& output, NodePointer &node, int indent);

    void ReadFromFile(BinarySearchTree &tree, string fileName);


    friend ostream& operator<< (ostream &output, BinarySearchTree &binarySearchTree);

};


#endif //ASSIGNMENT4_BINARYSEARCHTREE_H
