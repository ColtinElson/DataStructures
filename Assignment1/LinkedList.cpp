//
// Created by Coltin Elson on 1/15/18.
//

#include <iostream>
#include "LinkedList.h"

using namespace std;

    //initialize an empty list with the first node being null
    LinkedList::LinkedList() : first(nullptr) {};

    //default destructor, goes through the list and deletes all the nodes
    LinkedList::~LinkedList()
    {
        //set node to be the first node in the list
        Node *node = first;

        //while there is something in the list
        while (node != nullptr)
        {
            //make a temporary node
            Node *temp = node;

            //set the node you're on equal to the next in the list
            node = node->next;

            //delete the temporary node
            delete temp;
        }
    }

    void LinkedList::Add(string value)
    {
        //make a new nodeToAdd to be added
        Node *nodeToAdd = new Node();

        //make the new nodeToAdd's data equal to what you want to insert
        nodeToAdd->data = value;

        //if the list is empty, add it to the beginning
        if (first == nullptr)
        {
            first = nodeToAdd;
        }
            //otherwise, add it to the end of the list
        else
        {
            //get the current nodeToAdd you're on and initialize the previous nodeToAdd to null
            Node *currentNode = first;
            Node *previousNode = nullptr;

            //loop through all the nodes until you reach a nullptr (end of list)
            while (currentNode != nullptr)
            {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
            //if the previous nodeToAdd is not null
            if (previousNode != nullptr)
            {
                //set the next nodeToAdd equal to the new nodeToAdd
                previousNode->next = nodeToAdd;
            }
        }
    }

    //delete a node based on it's value
    void LinkedList::DeleteValue(string value)
    {
        //get the first node and initialize a value for the previous node
        Node *node = first;
        Node *previousNode = nullptr;

        //while the list isn't empty
        while (node != nullptr)
        {
            //if the data in the node you're on is equal to the value to delete
            if (node-> data == value)
            {
                //break out of the while loop
                break;
            }

            //continue looping through the list
            previousNode = node;
            node = node->next;
        }

        //if the current node is not null
        if (node != nullptr)
        {
            //if the node is the first in the list
            if (node == first)
            {
                //set the first node equal to the next in the list
                first = node->next;
            }
            else
            {
                //otherwise, set the current node equal to the next node
                previousNode->next = node->next;
            }

            //finally, delete the node
            delete node;
        }

    }

    //delete a node based on the node position
    void LinkedList::DeleteNode(int nodeNumber)
    {
        //set the index equal to -1
        int index = -1;

        //get the first node and initialize a value for the previous node
        Node *node = first;
        Node *previousNode = nullptr;

        //loop through the node until you reach the end or the node position wanted
        while (node != nullptr)
        {
            //increase the index
            index++;

            //if the index is equal to the position wanted
            if (index == nodeNumber)
            {
                //break out of the loop
                break;
            }

            //otherwise, loop to the next node in the list
            previousNode = node;
            node = node->next;
        }

        //if the index is not equal to -1 (the node was found
        if (index >= 0)
        {
            //if the node is the first in the list
            if (node == first)
            {
                //set the first node equal to the next in the list
                first = node->next;
            }
            else
            {
                //otherwise, set the current node equal to the next node
                previousNode->next = node->next;
            }

            //finally, delete the node
            delete node;
        }
    }

    //insert a new node after a node containing the specified data
    void LinkedList::InsertAfterValue(string existingValue, string newValue)
    {
        //Make a new node and give it the data
        Node *newNode = new Node();
        newNode->data = newValue;

        //get the first node
        Node *node = first;

        //loop through the list until you find the specified node
        while (node != nullptr)
        {
            //if the current node is the on you want
            if (node->data == existingValue)
            {
                //break out of the loop
                break;
            }

            //move to the next node in the list
            node = node->next;
        }

        //if the list is empty
        if (first == nullptr)
        {
            //make the first node equal to the new one
            first = node;
        }
        //otherwise, make sure the current node isn't a nullptr and then add it after that node
        else
        {
            if (node != nullptr)
            {
                //set the new node's next to be whatever was in that position
                newNode->next = node->next;
                //set the old node's next to be the new node
                node->next = newNode;
            }
                //if you can't find the node in the list
            else
            {
                //add the new node to the end of the list
                Add(newValue);
            }
        }
    }

    //insert a new value before the current index
    void LinkedList::InsertBeforeNode(int nodenum, string newValue)
    {
        //set the index to -1 initially
        int index = -1;
        //then make a new node with given data
        Node *newNode = new Node();
        newNode->data = newValue;
        //then get the current and previous nodes
        Node *currentNode = first;
        Node *previousNode = first;

        //loop through the node until you reach the end or the node position wanted
        while (currentNode != nullptr)
        {
            //increase the index
            index++;

            //if the index is equal to the position wanted
            if (index == nodenum)
            {
                //break out of the loop
                break;
            }

            //otherwise, loop to the next node in the list
            previousNode = currentNode;
            currentNode = currentNode->next;
        }

        //if the list is empty
        if (first == nullptr)
        {
            //set the first node equal to the new node
            first = newNode;
        }
        //otherwise
        else
        {
            //if the current node is not a nullptr
            if (currentNode != nullptr)
            {
                //set the previous node to point to the new node
                previousNode->next = newNode;
                //then set the new node to point to the current node
                newNode->next = currentNode;
            }
                //if you can't find the node in the list
            else
            {
                //add the new node to the end of the list
                Add(newValue);
            }
        }

    }

    //overloaded output operator
    ostream &operator<<(ostream &output, LinkedList &list)
    {
        //get the first item in the list
        Node *currentNode = list.first;

        int nodeNumber = 1;
        //while there is more items in the list
        while (currentNode != nullptr)
        {
            //output the data for the given node and then loop to the next node
            output << nodeNumber << " - " << currentNode->data << endl;
            currentNode = currentNode->next;
            nodeNumber++;
        }
        //return the output
        return output;
    }

int LinkedList::CountNodes() {
    int numberOfNodes = 0;

    Node *currentNode = first;

    while (currentNode != nullptr)
    {
        numberOfNodes++;
        currentNode = currentNode->next;
    }

    return numberOfNodes;
}
