#include <ctime>
#include <iostream>
#include "QuickSort.h"

//start timer, run quick sort and return time
double QuickSort::quickSortTimer(int *array, int arraySize)
{
    double time;
    clock_t start = clock();

    quickSort(array, 0, arraySize);

    time = ((double)(clock()-start)/CLOCKS_PER_SEC);

    return time;
}

//recursive sorting method
void QuickSort::quickSort(int *array, int left, int right)
{
    //if the left index is less than the right index (more than 1 being sorted)
    if (left < right)
    {
        //get a new pivot point
        int pivot = partition(array, left, right);

        //quicksort left half and right half
        quickSort(array, left, pivot);
        quickSort(array, pivot+1, right);
    }
}

//get first element, then move anything smaller than it to the left, everything bigger than it to the right
int QuickSort::partition(int *array, int left, int right)
{
    int pivot = array[left];
    int i = left +1;

    for (int j = left + 1; j < right; j++)
    {
        //if the next element is smaller than the pivot, swap it with one to the right of the last smallest
        if(array[j] < pivot)
        {
            int temporary = array[i];
            array[i] = array[j];
            array[j] = temporary;
            i++;
        }
    }
    //move pivot to the last spot used
    int temporary = array[left];
    array[left] = array[i-1];
    array[i-1] = temporary;

    return i-1;
}
