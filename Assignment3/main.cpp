#include <iostream>
#include <cstdlib>
#include "SortingMethods.h"

using namespace std;

int main() {
    string userInput;
    int arraySize = 0;
    int *array, *unsortedArray;
    SortingMethods sortingMethods;
    //Welcome message
    cout << "Welcome to the Sorting Method Compare Class!" << endl;
    cout << "This class will take generate an array of a random size, sort it using"
            " 6 different sorting methods and compare the time it took to sort using each method " << endl << endl;
    //prompt user for array size
    cout << "To begin, what size array would you like to use? " << endl;

    bool moveOn = false;

    while(!moveOn)
    {
        getline(cin, userInput);
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
    cout << "Your array will be size: " << arraySize << endl;

    unsortedArray = new int[arraySize];
    array = new int[arraySize];

    for (int i = 0; i < arraySize; i++)
    {
        unsortedArray[i] = (rand() % 32767) +1;
        array[i] = unsortedArray[i];
    }
    cout << endl << " Bubble Sorted in " << sortingMethods.bubbleSort(array, arraySize) << " seconds" << endl;


    for (int i = 0; i < arraySize; i++)
    {
        array[i] = unsortedArray[i];
    }
    cout << endl << " Selection Sorted in " << sortingMethods.selectionSort(array, arraySize) << " seconds" << endl;

    return 0;
}