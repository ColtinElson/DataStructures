#include "HashTable.h"

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
    HashNode *node = hashTable[i];

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
                    node = hashTable[i];
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
void HashTable::insert(string value)
{
    //hash the value
    int hashKey = hashFunction(value);

    HashNode *previous = nullptr;
    //make a new node from that key
    HashNode *node = hashTable[hashKey];

    //while the node is not null, loop through until you hit null
    while (node != nullptr)
    {
        previous = node;
        node = node->next;
    }

    //make a new node with the given key and value
    if (node == nullptr)
    {
        node = new HashNode(hashKey, value);
        //if the node doesn't have a previous (not a collision spot), just insert it
        if (previous == nullptr)
        {
            hashTable[hashKey] = node;
        }
            //otherwise, set the previous's next (aka, a new node in that index) to the node
        else
        {
            previous->next = node;
        }
    }
}

//loop through all nodes and node next's printing each value
//also counts the collisions and displays the number
void HashTable::PrintTable()
{
    int index = 0;
    int collisionCount = 0;
    HashNode *node = hashTable[index];
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
                node = hashTable[index];
                cout << endl << "Node #" << index+1 << ": ";
            }
        }
    }
    cout << endl << "Number of collisions: " << collisionCount << endl;
}

