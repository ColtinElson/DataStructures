#include <iostream>
#include "SequentialSearch.h"
#include "BinarySearch.h"

using namespace std;

int main()
{
    SequentialSearch sequentialSearch;
    BinarySearch binarySearch;

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
    return 0;
}