//
// Created by Coltin Elson on 1/15/18.
//

#ifndef ASSIGNMENT1_LINKEDLIST_H
#define ASSIGNMENT1_LINKEDLIST_H
#include <iostream>
#include "Node.h"

using namespace std;

class LinkedList {
private:
    //The initial node of the list
    Node *first;

public:
    //default constuctor
    LinkedList();

    //virtual destructor
    virtual ~LinkedList();

    //Add an item to the end of the list
    void Add(int num);

    //delete a node from the list based on its value
    void DeleteValue(int value);

    //delete a node from the list based on its position
    void DeleteNode(int nodenum);

    //insert a new value into the list after a specified value
    void InsertAfterValue(int value, int num);

    //insert a new value into the list before the specified node
    void InsertBeforeNode(int nodenum, int num);

    //overloaded friend function output
    friend ostream &operator<<(ostream &output, LinkedList &list);



};


#endif //ASSIGNMENT1_LINKEDLIST_H
