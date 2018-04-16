//
// Created by Coltin Elson on 4/16/18.
// based on code from Hal O'connell
//

#include "HashTable.h"
#include "LinkedList.h"

//converts string value into int key for hash table
int HashTable::hashFunction(string keyString)
{
    //initialize key
    int key;

    //get length of string
    int lengthOfKeyString = keyString.length();

    //key start value is ascii for first character over ascii of last
    key = ((int)keyString[0])/((int)keyString[lengthOfKeyString-1]);

    //loop through all characters of string
    for (int i = 0; i < lengthOfKeyString; i++)
    {
        //add ascii of first * ascii of last to key
        key += (int)keyString[i]*((int)keyString[lengthOfKeyString-1]);
    }

    //return the modulus of key / size
    return key % SIZE;
}

//tries to find a value in the hashtable
bool HashTable::find(string value)
{
    //start at first node
    int i = 0;
    LinkedList *list = hashTable[i];
    HashNode *node = list->first;

    //loop through until end of hashtable has been found
    while (i < SIZE)
    {
        //if the node value is value, return true
        if (node->value == value)
        {
            return true;
        }
            //otherwise
        else
        {
            //if the node has a next (aka a collision occured there), check the next in that node
            if (node->next != nullptr)
            {
                node = node->next;
            }
                //if no collision, move to next item in table if not at end
            else
            {
                i++;
                if (i < SIZE)
                {
                    list = hashTable[i];
                    node = list->first;
                }
            }
        }
    }
    //if you reached the end of the table, print out the value
    if(value.length() > 1)
    {
        cout << "- " << value << endl;
    }
    return false;
}

//insert a value into table, checking for collisions
//each hash table entry is a linked list i.e. (hashTable[i] is a linked list)
void HashTable::insert(string value)
{
    //hash the value
    int hashKey = hashFunction(value);

    //make a new list from that key
    LinkedList *list = hashTable[hashKey];

    //if list is empty, initialize it
    if (list == nullptr)
    {
        hashTable[hashKey] = new LinkedList();
    }

    //add value to the linked list
    hashTable[hashKey]->Add(value);
}

//loop through all nodes and node next's printing each value
//also counts the collisions and displays the number
void HashTable::PrintTable()
{
    int index = 0;
    int collisionCount = 0;
    LinkedList *list = hashTable[index];
    HashNode *node = list->first;
    cout << "Node #" << index+1 << ": ";
    while (index < SIZE)
    {
        cout << node->value;
        if (node->next != nullptr)
        {
            cout << " || ";
            node = node->next;
            collisionCount++;
        }
        else
        {
            index++;
            if (index < SIZE)
            {
                list = hashTable[index];
                node = list->first;
                cout << endl << "Node #" << index+1 << ": ";
            }
        }
    }
    cout << endl << "Number of collisions: " << collisionCount << endl;
}

