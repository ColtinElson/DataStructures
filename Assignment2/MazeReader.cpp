//
// Created by nscc on 2/21/18.
//

#include "MazeReader.h"


void MazeReader::ReadFileIntoArray(Stack& maze, string fileName)
{
    //open file
    ifstream file;
    file.open(fileName);
    //declare string and a temporary stack variables
    string line;
    Stack temp;
    //while there are lines to read
    while (getline(file, line))
    {
        //if they have something in them
        if (!line.empty())
        {
            //add them to stack
            temp.Push(line);
        }
    }

    int numLines = temp.GetStackSize();
    //loop through the temp stack and add each node to the maze stack
    //this reverses the stack
    for (int i = 0; i < numLines; i++)
    {
        maze.Push(temp.Peek());
        temp.Pop();
    }

    //close the file
    file.close();
}

bool MazeReader::CheckFile(string fileName) {

    //open file
    ifstream file;
    file.open(fileName);
    //declare line variable
    string line;

    //try to getline
    while (getline(file, line))
    {
        //if they have something in them, return true
        if (!line.empty())
        {
            return true;
        }
    }
    //otherwise return false if empty
    return false;
}

