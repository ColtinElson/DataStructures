#include <iostream>
#include "StackNode.h"
#include "Stack.h"

using namespace std;


//default constructor
Stack::Stack() : _top(nullptr)
{
}

//stack destructor, pop all values in stack
Stack::~Stack()
{
    while( _top != nullptr )
    {
        Pop();
    }
}

//add a new node with given value to the top
myerror_code Stack::Push( string line )
{
    _top = new StackNode( line, _top );
    return(success);
}

//get the data of the top node
string Stack::Peek()
{
    return _top->getData();
}

//delete the first value of the node
myerror_code Stack::Pop()
{
    //check if the stack is empty
    if (_top != nullptr) {

        //if not, set the next node down in the list to the top and then delete the old top
        StackNode* node = _top;
        _top = _top->getNext();
        delete node;
        return(success);
    }
        //if the stack is empty return an error
    else {
        return(underflow);
    }
}

//overloaded stack output
ostream& operator<<( ostream& output, Stack& stack )
{
    //get the top node
    StackNode *node = stack._top;

    //while it's not null
    while( node != nullptr )
    {
        //output the node's data and loop to the next node in the stack
        cout << node->getData() << endl;
        node = node->getNext();
    }

    return output;
}

int Stack::GetStackSize() {

    int stackSize = 0;

    //get the top node
    StackNode *node = Stack::_top;

    //while it's not null
    while( node != nullptr )
    {
        //add 1 to the stack size
        stackSize++;
        node = node->getNext();
    }
    return stackSize;

}

