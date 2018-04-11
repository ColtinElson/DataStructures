//
// Created by nscc on 3/21/18.
//

#include <ctime>
#include "InsertionSort.h"

//start timer, sort then return time
double InsertionSort::insertionSort(int *array, int length)
{
    double time;
    clock_t start = clock();

    int outer, inner, temporary;

    //loop through all values
    for (outer = 1; outer < length; outer++)
    {
        inner = outer;
        //while the one before is smaller than the current
        while (inner > 0 && array[inner-1] > array[inner])
        {
            //swap current with one before and then repeat for one before
            temporary = array[inner];
            array[inner] = array[inner-1];
            array[inner-1] = temporary;
            inner--;
        }
    }

    time = ((double)(clock()-start)/CLOCKS_PER_SEC);

    return time;
}
