//
// Created by nscc on 4/16/18.
//

#ifndef ASSIGNMENT5_HASHTABLE_H
#define ASSIGNMENT5_HASHTABLE_H

#include <iostream>
#include "HashNode.h"

#define SIZE 13;

using namespace std;

class HashTable
{
private:
    HashNode **hashTable;
public:
    HashTable()
    {
        hashTable = new HashNode *[13]();
    }

    bool find(string value);

    void insert(string value);

    int hashFunction(string keyString);

    void PrintTable();

};


#endif //ASSIGNMENT5_HASHTABLE_H
