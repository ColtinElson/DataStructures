//
// Created by nscc on 4/16/18.
//

#ifndef ASSIGNMENT5_HASHTABLE_H
#define ASSIGNMENT5_HASHTABLE_H

#include <iostream>
#include "HashNode.h"

using namespace std;

class HashTable
{
private:
    HashNode **hashTable;
    const int SIZE = 13;
public:
    HashTable()
    {
        hashTable = new HashNode *[SIZE]();
    }

    bool find(string value);

    void insert(string value);

    int hashFunction(string keyString);

    void PrintTable();

};


#endif //ASSIGNMENT5_HASHTABLE_H
