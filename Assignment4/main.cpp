#include <iostream>
#include <fstream>
#include <sstream>
#include "SequentialSearch.h"
#include "BinarySearch.h"
#include "BinarySearchTree.h"

using namespace std;

int main()
{
    SequentialSearch sequentialSearch;
    BinarySearch binarySearch;
    BinarySearchTree binarySearchTree;

    //initialize sortedArray with given size
    int arraySize = 1000;
    auto * sortedArray = new int[arraySize];

    //load array with values 1 - array size
    for (int i = 0; i < arraySize; i++)
    {
        sortedArray[i] = i+1;
    }

    //Welcome message
    cout << "Welcome to the Searching and Trees Program!" << endl;
    cout << "First, let's compare sequential and binary searching algorithms." << endl << endl;

    //position of seach value
    int position = 0;

    //start the timer
    double time;
    clock_t start = clock();

    //check every number in array sequentially
    for (int i = 0; i < arraySize; i++)
    {
        sequentialSearch.sequentialSearch(sortedArray, arraySize, sortedArray[i], position);
    }

    //get how much time passed
    time = ((double)(clock()-start)/CLOCKS_PER_SEC);

    //display results
    cout << "Time to find every number using sequential searching: " << time << " seconds" << endl;

    //restart timer
    start = clock();

    //check every number in array using binary search
    for (int i = 0; i < arraySize; i++)
    {
        binarySearch.binarySearch(sortedArray, arraySize, sortedArray[i], position);
    }

    //get how much time passed
    time = ((double)(clock()-start)/CLOCKS_PER_SEC);

    //display results
    cout << "Time to find every number using binary searching: " << time << " seconds" << endl << endl;

    cout << "Now for the fun stuff! Auto-balancing Binary Search Trees!" << endl;

    //populate the tree
    binarySearchTree.ReadFromFile(binarySearchTree, "/home/nscc/Desktop/PROG2400/DataStructures/Assignment4/Resources/dictionary.txt");

    cout << "Here is the binary tree: " << endl;

    //print the tree
    cout << binarySearchTree << endl;

    cin.ignore();

    cout << "We will now check the misspelled document to see what words are misspelled." << endl << endl;

    cout << "Misspelled Words: " << endl;

    //open file
    ifstream file;
    file.open("/home/nscc/Desktop/PROG2400/DataStructures/Assignment4/Resources/mispelled.txt");
    //declare string variable
    string line;

    //while there are lines to read
    while (getline(file, line))
    {
        //if they have something in them
        if (!line.empty())
        {
            //get the length of the line
            int length = line.length()-1;
            //parse from end to beginning of line
            for (int i = length; i >= 0; i--)
            {
                //if it's a capital, lowercase it
                line[i] = tolower(line[i]);
                //get it's ascii code
                int ascii = toascii(line[i]);

                //if it's a space, move on
                if (ascii == 32)
                {
                    continue;
                }
                    //if it's not between 97 and 122 (a-z) delete it
                else if (ascii > 122 || ascii < 97)
                {
                    line.erase(i, 1);
                }
            }
            //variables to split string
            string split;
            stringstream stream(line);

            //while there are more words (split by space)
            while(getline(stream, split, ' '))
            {
                //search split word, printing any misspelled words
                binarySearchTree.Search(split, binarySearchTree.root);
            }

        }
    }

    //close the file
    file.close();

    cin.ignore();

    return 0;
}