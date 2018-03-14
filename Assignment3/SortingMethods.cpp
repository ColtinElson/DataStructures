//
// Created by nscc on 3/14/18.
//

#include <ctime>
#include "SortingMethods.h"

double SortingMethods::bubbleSort(int *array, int length)
{
    double time;
    clock_t start = clock();

    int inner, outer;
    for (outer = length -1; outer > 0; outer--)
    {
        for (inner = 0; inner < outer; inner++)
        {
            if (array[inner] > array[inner + 1])
            {
                int temp = array[inner];
                array[inner] = array[inner + 1];
                array[inner + 1] = temp;
            }
        }
    }

    time = ((double)(clock()-start)/CLOCKS_PER_SEC);

    return time;

}

double SortingMethods::selectionSort(int *array, int length)
{
    double time;
    clock_t start = clock();

    int outer, inner, min;
    for (outer = 0; outer < length-1; outer++)
    {
        min = outer;
        for (inner = outer +1; inner < length; inner++)
        {
            if (array[inner] < array[min])
            {
                min = inner;
            }
        }
        int temp = array[outer];
        array[outer] = array[min];
        array[min] = temp;
    }

    time = ((double)(clock()-start)/CLOCKS_PER_SEC);
    return time;
}
