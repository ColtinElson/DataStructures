//
// Created by Coltin Elson on 1/15/18.
//

#ifndef ASSIGNMENT1_NODE_H
#define ASSIGNMENT1_NODE_H

#include <string>

using namespace std;

class Node
{
public:
    //Data in the linked list
    string data;

    //Pointer pointing to the next node
    Node *next;

    //Default constructor for the node
    //Constructs the pointer to a null pointer,
    //assuming there is no other nodes in the link
    //also assign data to an empty string
    Node() : next(nullptr), data("") {}

};


#endif //ASSIGNMENT1_NODE_H
