#include "SortingOutput.h"
#include <fstream>

using namespace std;

//output array contents to file
void SortingOutput::saveArrayToFile(int *array, int arraySize, std::string fileName)
{
    //open results folder and make a new file
    ofstream file("/home/nscc/Desktop/PROG2400/DataStructures/Assignment3/Results/" + fileName);

    //read each element to the file, adding ", " between each one
    if (file.is_open())
    {
        for (int i = 0; i < arraySize; i++)
        {
            if (i == arraySize -1)
            {
                file << array[i] << endl;
            }
            else
            {
                file << array[i] << ", ";
            }

        }
        //close the file
        file.close();
    }
}
