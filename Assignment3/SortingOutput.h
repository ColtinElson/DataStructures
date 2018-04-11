#ifndef ASSIGNMENT3_SORTINGOUTPUT_H
#define ASSIGNMENT3_SORTINGOUTPUT_H
#include <iostream>
#include <experimental/filesystem>

class SortingOutput
{
public:
    static void saveArrayToFile(int *array, int arraySize, std::string fileName);
};


#endif //ASSIGNMENT3_SORTINGOUTPUT_H
