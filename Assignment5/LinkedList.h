//
// Created by Coltin Elson on 4/16/18.
// based on code from Assignment 1
//

#ifndef ASSIGNMENT1_LINKEDLIST_H
#define ASSIGNMENT1_LINKEDLIST_H
#include <iostream>
#include "HashNode.h"

using namespace std;

class LinkedList {

public:
    //default constuctor
    LinkedList();

    //virtual destructor
    virtual ~LinkedList();

    //Add an item to the end of the list
    void Add(string value);

    //delete a node from the list based on its value
    void DeleteValue(string value);

    //delete a node from the list based on its position
    void DeleteNode(int nodeNumber);

    //insert a new value into the list after a specified value
    void InsertAfterValue(string existingValue, string newValue);

    //insert a new value into the list before the specified node
    void InsertBeforeNode(int nodeNumber, string newValue);

    //overloaded friend function output
    friend ostream &operator<<(ostream &output, LinkedList &list);

    int CountNodes();


//The initial node of the list
    HashNode *first;
};


#endif //ASSIGNMENT1_LINKEDLIST_H
