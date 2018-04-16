//
// Created by Coltin Elson on 4/16/18.
// based on code from Hal O'connell
//hash find and insert code referenced from:
//https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
//Paul Programming - https://www.youtube.com/watch?v=ZPCc-uhfi0E
//http://www.algolist.net/Data_structures/Hash_table/Simple_example
//

#ifndef ASSIGNMENT5_HASHTABLE_H
#define ASSIGNMENT5_HASHTABLE_H

#include <iostream>
#include "HashNode.h"
#include "LinkedList.h"

using namespace std;

class HashTable
{
private:
    LinkedList **hashTable;
    const int SIZE = 13;
public:
    HashTable()
    {
        hashTable = new LinkedList *[SIZE]();
    }

    bool find(string value);

    void insert(string value);

    int hashFunction(string keyString);

    void PrintTable();

};


#endif //ASSIGNMENT5_HASHTABLE_H
