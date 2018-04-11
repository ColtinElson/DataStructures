#include <ctime>
#include "SelectionSort.h"

//start timer, sort then return time
double SelectionSort::selectionSort(int *array, int length)
{
    double time;
    clock_t start = clock();

    int outer, inner, min;
    //loop through each value
    for (outer = 0; outer < length-1; outer++)
    {
        min = outer;
        //if the next value is smaller then current smallest, swap then make it the new smallest
        for (inner = outer +1; inner < length; inner++)
        {
            if (array[inner] < array[min])
            {
                min = inner;
            }
        }
        //swap the first with the new smallest
        int temp = array[outer];
        array[outer] = array[min];
        array[min] = temp;
    }

    time = ((double)(clock()-start)/CLOCKS_PER_SEC);
    return time;
}
