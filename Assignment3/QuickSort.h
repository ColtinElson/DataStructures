//
// Created by nscc on 3/22/18.
//

#ifndef ASSIGNMENT3_QUICKSORT_H
#define ASSIGNMENT3_QUICKSORT_H


class QuickSort
{
public:
    static double quickSortTimer(int *array, int arraySize);

private:
    static void quickSort(int *array, int left, int right);
    static int partition(int *array, int left, int right);
};


#endif //ASSIGNMENT3_QUICKSORT_H
