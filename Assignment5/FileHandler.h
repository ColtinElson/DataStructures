//
// Created by Coltin Elson on 4/16/18.
//

#ifndef ASSIGNMENT5_FILEHANDLER_H
#define ASSIGNMENT5_FILEHANDLER_H

#include <iostream>

using namespace std;

class FileHandler
{

public:
    void ReadFileIntoArray(string FileName, string* array, int arraySize);
    void ReadFileWordsIntoArray(string FileName, string* array, int arraySize);
};


#endif //ASSIGNMENT5_FILEHANDLER_H
