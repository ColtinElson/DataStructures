#include <iostream>
#include <cstdlib>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "ShellSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "SortingOutput.h"

void resetArray(int *array, int arraySize);

using namespace std;

int main() {
    //initialize variables
    bool writeToFile = false;
    string userInput;
    int arraySize = 0;
    int *array, *temporaryArray;

    //Welcome message
    cout << "Welcome to the Sorting Method Compare Class!" << endl;
    cout << "This class will take generate an array of a random size, sort it using"
            " 6 different sorting methods and compare the time it took to sort using each method " << endl << endl;
    //prompt user for array size
    cout << "To begin, what size array would you like to use? " << endl;

    //loop until user inputs a number or a number with w
    bool moveOn = false;

    while(!moveOn)
    {
        getline(cin, userInput);

        if (userInput == "1000 w")
        {
            arraySize = 1000;
            writeToFile = true;
            moveOn = true;
        }
        else
        {
            //try to parse a number
            try
            {
                arraySize = stoi(userInput);
                moveOn = true;
            }
            catch(invalid_argument)
            {
                cout << "You need to input a valid number! Please try again: " << endl;
                moveOn = false;
            }
        }
    }
    //initialize arrays
    array = new int[arraySize];
    temporaryArray = new int[arraySize];

    //for each sorting method, reset the array to unsorted, sort and display the time and then save to a file if needed

    resetArray(array, arraySize);

    cout << endl << "Bubble Sorted in " <<BubbleSort::bubbleSort(array, arraySize) << " seconds" << endl;

    if(writeToFile)
    {
        SortingOutput::saveArrayToFile(array, arraySize, "BubbleSort.txt");
    }

    resetArray(array, arraySize);

    cout << "Selection Sorted in " << SelectionSort::selectionSort(array, arraySize) << " seconds" << endl;

    if(writeToFile)
    {
        SortingOutput::saveArrayToFile(array, arraySize, "SelectionSort.txt");
    }

    resetArray(array, arraySize);

    cout << "Insertion Sorted in " << InsertionSort::insertionSort(array, arraySize) << " seconds" << endl;

    if(writeToFile)
    {
        SortingOutput::saveArrayToFile(array, arraySize, "InsertionSort.txt");
    }

    resetArray(array, arraySize);

    cout << "Shell Sorted in " << ShellSort::shellSort(array, arraySize) << " seconds" << endl;

    if(writeToFile)
    {
        SortingOutput::saveArrayToFile(array, arraySize, "ShellSort.txt");
    }

    resetArray(array, arraySize);

    cout << "Merge Sorted in " << MergeSort::mergeSortTimer(array, arraySize,temporaryArray) << " seconds" << endl;

    if(writeToFile)
    {
        SortingOutput::saveArrayToFile(array, arraySize, "MergeSort.txt");
    }

    resetArray(array, arraySize);

    cout << "Quick Sorted in " << QuickSort::quickSortTimer(array, arraySize) << " seconds" << endl;

    if(writeToFile)
    {
        SortingOutput::saveArrayToFile(array, arraySize, "QuickSort.txt");
    }

    return 0;
}

void resetArray(int *array, int arraySize)
{
    //gets random numbers based on array size
    //rand will always get the same numbers
    for (int i = 0; i < arraySize; i++)
    {
        array[i] = (rand() % 32767) +1;
    }
}