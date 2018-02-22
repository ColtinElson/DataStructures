#include <iostream>
#include "StackNode.h"

using namespace std;

//default constructor - initialize with blank value
StackNode::StackNode() : _data(""), _next(nullptr)
{
}

//constructor when stack already exists
StackNode::StackNode( string data, StackNode* next ) : _data(data), _next(next)
{
}

//default constructor
StackNode::~StackNode()
{
}

//get the data from the node
string StackNode::getData()
{
    return _data;
}

//set the data in the node
void StackNode::setData( string data )
{
    _data = data;
}

//get the next node
StackNode* StackNode::getNext()
{
    return _next;
}

//set the next node value
void StackNode::setNext( StackNode *next )
{
    _next = next;
}
