#ifndef _STACKNODE_H
#define _STACKNODE_H

#include <string>

using namespace std;

class StackNode
{
private:
    //data represented in the node
    string _data;
    //pointer to the next node in the stack
    StackNode *_next;

public:
    //default constructor for the stack node
    StackNode();
    //constructor when given data
    StackNode( string data, StackNode* next );
    //virtual destructor
    virtual ~StackNode();

    //get data from node
    string getData();
    //set data in node
    void setData( string data );

    //get the next node in the stack
    StackNode* getNext();
    //set the next node in the stack
    void setNext( StackNode *next );
};

#endif
