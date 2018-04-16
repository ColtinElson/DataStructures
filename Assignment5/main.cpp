//
// Created by Coltin Elson on 4/16/18.
// based on code from Hal O'connell
//

#include <iostream>
#include "HashTable.h"
#include "FileHandler.h"

using namespace std;

int main()
{
    //initialize dictionary and spellchecker arrays
    int dictionarySize = 64;
    auto * dictionaryArray = new string[dictionarySize];

    int documentSize = 82;
    auto * checkerArray = new string[documentSize];

    //initialize instance of hashtable and file handler
    HashTable hashTable;
    FileHandler fileHandler;
    //welcome message
    cout << "Welcome to the hashing program!" << endl;
    cout << "This program will use a hash table as a spell checker" << endl;

    //read dictionary into array
    fileHandler.ReadFileIntoArray("/home/nscc/Desktop/PROG2400/DataStructures/Assignment5/Resources/dictionary.txt", dictionaryArray, dictionarySize);

    //insert array values into hashtable
    for (int i = 0; i < dictionarySize; i++)
    {
        hashTable.insert(dictionaryArray[i]);
    }

    cout << "Hash Table has been made: " << endl << endl;
    //print table + collision number
    hashTable.PrintTable();

    //wait for user to hit next
    cin.ignore();

    //display next message
    cout << endl << "We will now check the misspelled document to see what words are misspelled." << endl << endl;

    cout << "Misspelled Words: " << endl;

    //read misspelled word document into array
    fileHandler.ReadFileWordsIntoArray("/home/nscc/Desktop/PROG2400/DataStructures/Assignment5/Resources/mispelled.txt", checkerArray, documentSize);

    //start the timer
    double time;
    clock_t start = clock();

    //check through array to see if the word is in the hash table
    //prints off each word that isn't in hash table
    for (int i = 0; i < documentSize; i++)
    {
        hashTable.find(checkerArray[i]);
    }

    //get how much time passed
    time = ((double)(clock()-start)/CLOCKS_PER_SEC);

    //display to user
    cout << "It took " << time << " seconds to find all the misspelled words." << endl;

    return 0;
}

