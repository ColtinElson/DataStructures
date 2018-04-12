#include "BinarySearchTree.h"

void BinarySearchTree::Insert(int number)
{
    Insert(number, root);
}

void BinarySearchTree::Insert(int number, NodePointer &node)
{
    if (node == nullptr)
    {
        node = new Node();
        node->data = number;
    }
    else if (number < node->data)
    {
        Insert(number, node->left);
    }
    else if (number > node->data)
    {
        Insert(number, node->right);
    }
}

void BinarySearchTree::Remove(int num)
{

}

void BinarySearchTree::PrintTree(ostream &output, NodePointer &node, int indent)
{
    if (node != nullptr)
    {
        PrintTree(output, node->right, indent + 5);
        output << setw(indent) << node->data << endl;
        PrintTree(output, node->left, indent + 5);
    }
}

ostream &operator<<(ostream &output, BinarySearchTree &binarySearchTree)
{
    binarySearchTree.PrintTree(output, binarySearchTree.root, 0);

    return output;
}
