#include "HashTable.h"

int HashTable::hashFunction(string keyString)
{
    int temporary, key;


    key = 0;
    int lengthOfKeyString = keyString.length();

    temporary = ((int)keyString[0])/((int)keyString[lengthOfKeyString-1]);

    for (int i = 0; i < lengthOfKeyString; i++)
    {
        key += (temporary * (int)keyString[i]/((int)keyString[lengthOfKeyString-1]));
    }

    return key % SIZE;
}

bool HashTable::find(string value)
{
    int hashKey = hashFunction(value);
    HashNode *node = hashTable[hashKey];

    while (node != nullptr)
    {
        if (node->key == hashKey)
        {
            value = node->value;
            return true;
        }
        node = node->next;
    }
    return false;
}

void HashTable::insert(string value)
{
    int hashKey = hashFunction(value);

    HashNode *previous = nullptr;
    HashNode *node = hashTable[hashKey];

    while (node != nullptr)
    {
        previous = node;
        node = node->next;
    }

    if (node == nullptr)
    {
        node = new HashNode(hashKey, value);
        if (previous == nullptr)
        {
            hashTable[hashKey] = node;
        }
        else
        {
            previous->next = node;
        }
    }
}

void HashTable::PrintTable()
{
    int index = 0;
    HashNode *node = hashTable[index];
    cout << "Node #" << index+1 << ": ";
    while (node != nullptr)
    {
        cout << node->value;
        if (node->next != nullptr)
        {
            cout << " || ";
            node = node->next;
        }
        else
        {
            index++;
            node = hashTable[index];
            cout << endl << "Node #" << index+1 << ": ";

        }
    }
}

