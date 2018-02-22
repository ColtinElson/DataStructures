//
// Created by nscc on 2/21/18.
//

#ifndef ASSIGNMENT2_MAZEREADER_H
#define ASSIGNMENT2_MAZEREADER_H
#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;

class MazeReader
{
public:
    static void ReadFileIntoArray(Stack& maze, string fileName);

    static bool CheckFile(string fileName);


};


#endif //ASSIGNMENT2_MAZEREADER_H
