//
// Created by Coltin Elson on 4/16/18.
// based on code from Hal O'connell
//

#ifndef ASSIGNMENT5_HASHNODE_H
#define ASSIGNMENT5_HASHNODE_H

#include <iostream>

using namespace std;

class HashNode
{
public:
    HashNode(string value) :value(value), next(nullptr) {}
    string value;
    HashNode *next;
};


#endif //ASSIGNMENT5_HASHNODE_H
