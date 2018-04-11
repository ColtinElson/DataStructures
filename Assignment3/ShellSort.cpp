#include <ctime>
#include "ShellSort.h"

//start timer, sort, return time
double ShellSort::shellSort(int *array, int length)
{
    double time;
    clock_t start = clock();

    //check elements that are half the array apart, then check 1/4 of the way, etc..
    int inner, outer, increment, temporary;
    for (increment = length/2; increment > 0; increment /=2)
    {
        for (outer = increment; outer < length; outer++)
        {
            temporary = array[outer];
            for (inner = outer; inner >= increment; inner-=increment)
            {
                //if the current is larger than the one (increment) away, swap them
                if(temporary < array[inner-increment])
                {
                    array[inner] = array[inner-increment];
                }
                else
                {
                    break;
                }
            }
            array[inner] = temporary;
        }
    }

    time = ((double)(clock()-start)/CLOCKS_PER_SEC);

    return time;
}
