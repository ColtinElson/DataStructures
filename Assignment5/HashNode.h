#ifndef ASSIGNMENT5_HASHNODE_H
#define ASSIGNMENT5_HASHNODE_H

#include <iostream>

using namespace std;

class HashNode
{
public:
    HashNode(int key, string value) : key(key), value(value), next(nullptr) {}
    int key;
    string value;
    HashNode *next;
};


#endif //ASSIGNMENT5_HASHNODE_H
