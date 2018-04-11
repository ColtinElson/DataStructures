//
// Created by nscc on 3/21/18.
//

#ifndef ASSIGNMENT3_MERGESORT_H
#define ASSIGNMENT3_MERGESORT_H


class MergeSort
{
public:
    static double mergeSortTimer(int *array, int arraySize, int *temporary);

private:
    static void merge(int *array, int first, int middle, int last, int *temporary);
    static void mergeSort(int *array, int first, int last, int *temporary);
};


#endif //ASSIGNMENT3_MERGESORT_H
