//
// Created by nscc on 3/21/18.
//

#include <ctime>
#include "MergeSort.h"

//start timer, run merge sort, then return time
double MergeSort::mergeSortTimer(int *array, int arraySize, int *temporary)
{
    double time;
    clock_t start = clock();

    mergeSort(array, 0, arraySize, temporary);

    time = ((double)(clock()-start)/CLOCKS_PER_SEC);

    return time;
}

//divide the list in half, sort each half recursively and then merge them back together
void MergeSort::mergeSort(int *array, int first, int last, int *temporary)
{
    if (last - first > 1)
    {
        int middle = (first + last)/2;

        mergeSort(array, first, middle, temporary);
        mergeSort(array, middle, last, temporary);
        merge(array, first, middle, last, temporary);
    }
}

//compares two values, moves them to a temporary array in order of smallest to largest
//brings temporary array back into regular array
void MergeSort::merge(int *array, int first, int middle, int last, int *temporary)
{
    int i = first, j = middle, k;

    for (k = 0; i < middle && j < last; k++)
    {
        if(array[i] <= array[j])
        {
            temporary[k] = array[i++];
        }
        else
        {
            temporary[k] = array[j++];
        }
    }
    for (; i < middle; k++)
    {
        temporary[k] = array[i++];
    }
    for (; j < last; k++)
    {
        temporary[k] = array[j++];
    }
    for (int index = 0; index < last - first; index++)
    {
        array[first + index] = temporary[index];
    }
}


