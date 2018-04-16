#include "FileHandler.h"
#include <fstream>

void FileHandler::ReadFileIntoArray(string FileName, string *array, int arraySize)
{
    //open file
    ifstream file;
    file.open(FileName);
    //declare string variable
    string line;
    int i = 0;
    //while there are lines to read
    while (getline(file, line))
    {
        //if they have something in them
        if (!line.empty())
        {
            //add them to the searchTree
            array[i] = line;
            i++;
        }
    }

    //close the file
    file.close();
}
