#include <fstream>
#include "BinarySearchTree.h"

//tries to insert value at root
void BinarySearchTree::Insert(string value)
{
    Insert(value, root);
}

//finds correct place for value and inserts it, balancing as needed
void BinarySearchTree::Insert(string value, NodePointer &node)
{
    //if the node is null (first value)
    if (node == nullptr)
    {
        //make a new node with given value as data
        node = new Node();
        node->data = value;
    }
        //otherwise, if the value is less than the data of current node, insert it to the left
    else if (value < node->data)
    {
        Insert(value, node->left);

        //if the height difference of the two different nodes is more than one, rotate as needed
        if(HeightOf(node->right) - HeightOf(node->left) > 1)
        {
            if (value < node->left->data)
            {
                SingleRightRotate(node);
            }
            else
            {
                DoubleRightRotate(node);
            }
        }
    }
        //if the value is more than the data of the current node, insert it to the right
    else if (value > node->data)
    {
        Insert(value, node->right);

        //if the height difference of the two different nodes is more than one, rotate as needed
        if(HeightOf(node->right) - HeightOf(node->left) > 1)
        {
            if (value > node->right->data)
            {
                SingleLeftRotate(node);
            }
            else
            {
                DoubleLeftRotate(node);
            }
        }
    }

    //if the left node is now the heighest, set current node's height to left+1
    if (HeightOf(node->left) >= HeightOf(node->right))
    {
        node->height = HeightOf(node->left) + 1;
    }
        //otherwise it's right+1
    else
    {
        node->height = HeightOf(node->right) + 1;
    }
}

//search through the tree to see if you the value exists
void BinarySearchTree::Search(string value, NodePointer &node)
{
    //if it doesn't, display the value
    if (node == nullptr)
    {
        if (value.length() >= 1)
        {
            cout << "- " << value << endl;
        }

    }
    else
    {
        //if the value is less than the current value, check to the left
        if (value < node->data)
        {
            Search(value, node->left);
        }
            //otherwise check to the right
        else if (value > node->data)
        {
            Search(value, node->right);
        }
        //otherwise it must be equal to current value and we found the word
    }
}

//print the tree
//prints each node with an increasing indent to get the tree appearance
void BinarySearchTree::PrintTree(ostream &output, NodePointer &node, int indent)
{
    if (node != nullptr)
    {
        PrintTree(output, node->right, indent + 15);
        output << setw(indent) << node->data << endl;
        PrintTree(output, node->left, indent + 15);
    }
}

//overloaded << operator. calls printtree on root with an initial indent of 0
ostream &operator<<(ostream &output, BinarySearchTree &binarySearchTree)
{
    binarySearchTree.PrintTree(output, binarySearchTree.root, 0);

    return output;
}

//rotates nodes from c<-b<-a to c<-b->a
void BinarySearchTree::SingleRightRotate(NodePointer &node)
{
    //set a temporary node to hold values as we replace
    NodePointer temporaryNode = node->left;
    //set the node's left child to be it's right child
    node->left = temporaryNode->right;
    //then set the right child to the original value
    temporaryNode->right = node;

    //set the new heights
    if (HeightOf(node->left) >= HeightOf(node->right))
    {
        node->height = HeightOf(node->left) + 1;
    }
    else
    {
        node->height = HeightOf(node->right) + 1;
    }

    if (HeightOf(node) >= HeightOf(temporaryNode->right))
    {
        temporaryNode->height = HeightOf(node) + 1;
    }
    else
    {
        temporaryNode->height = HeightOf(temporaryNode->right) + 1;
    }

    //make the original node the temporary node
    node = temporaryNode;
}

//rorates nodes from a->b->c to a<-b->c
void BinarySearchTree::SingleLeftRotate(NodePointer &node)
{
    //set temp node as original right child
    NodePointer temporaryNode = node->right;
    //set the originals right child to be the temp's left child
    node->right = temporaryNode->left;
    //set the temp's left node to be the orignal node
    temporaryNode->left = node;

    //set the new heights
    if (HeightOf(node->left) >= HeightOf(node->right))
    {
        node->height = HeightOf(node->left) + 1;
    }
    else
    {
        node->height = HeightOf(node->right) + 1;
    }

    if (HeightOf(temporaryNode->left) >= HeightOf(node))
    {
        temporaryNode->height = HeightOf(temporaryNode->left) + 1;
    }
    else
    {
        temporaryNode->height = HeightOf(node) + 1;
    }

    //set the original node to be the temporary node
    node = temporaryNode;
}

//call left first to turn it into a c<-b<-a scenario then call right rotate
void BinarySearchTree::DoubleRightRotate(NodePointer &node)
{
    SingleLeftRotate(node->left);
    SingleRightRotate(node);
}

//call right first to turn it into a a->b->c scenario then call left rotate
void BinarySearchTree::DoubleLeftRotate(NodePointer &node)
{
    SingleRightRotate(node->right);
    SingleLeftRotate(node);
}

//gets the height property of a node or returns -1 if it's null
int BinarySearchTree::HeightOf(NodePointer &node)
{
    if (node == nullptr)
    {
        return -1;
    }
    else
    {
        return node->height;
    }
}

//reads lines from a file into a tree
void BinarySearchTree::ReadFromFile(BinarySearchTree &tree, string fileName)
{
    //open file
    ifstream file;
    file.open(fileName);
    //declare string variable
    string line;

    //while there are lines to read
    while (getline(file, line))
    {
        //if they have something in them
        if (!line.empty())
        {
            //add them to the searchTree
            tree.Insert(line);
        }
    }

    //close the file
    file.close();
}


