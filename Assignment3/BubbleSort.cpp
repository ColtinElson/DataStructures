#include <ctime>
#include "BubbleSort.h"

//start timer, sort then return time
double BubbleSort::bubbleSort(int *array, int length)
{
    double time;
    clock_t start = clock();

    int inner, outer;
    //loop through each element
    for (outer = length -1; outer > 0; outer--)
    {
        //start at the beginning of list
        for (inner = 0; inner < outer; inner++)
        {
            //if this value is smaller than the next, swap them
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
