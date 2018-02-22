#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include "StackNode.h"

using namespace std;
//enum of the possible codes for error and success
enum myerror_code { success, underflow, overflow };

class Stack
{
private:
    //the top node in the stack
    StackNode *_top;

public:
    //default constructor for the stack
    Stack();
    //virtual default destructor
    virtual ~Stack();

    //add a new value to the stack and return the error code
    myerror_code Push( string line );
    //get the data of the top node
    string Peek();
    //delete the top node from the stack
    myerror_code Pop();

    int GetStackSize();

    //overloaded output operator of stack
    friend ostream& operator<<( ostream& output, Stack& stack );
};

#endif
