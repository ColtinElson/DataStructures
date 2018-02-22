//
// Created by nscc on 2/21/18.
//

#include <fstream>
#include "MazeSolver.h"


void MazeSolver::SolveMaze(Stack &maze, int numLines)
{
    //get num of columns for matrix
    string firstLine = maze.Peek();
    int numChars = 0;
    for (char current : firstLine) {
        if (current == '+'
                || current == '-'
                || current == '|'
                || current == ' ')
        {
            numChars++;
        }
    }

    //create matrix
    char mazeArray[numLines][numChars];

    //turn stack into matrix
    for (int i = 0; i < numLines; i++)
    {
        string line = maze.Peek();
        for (unsigned j = 0; j < numChars; j++)
        {
            mazeArray[i][j] = line.at(j);
        }
        maze.Pop();
    }

    //turn matrix back into stack
    for (int i = numLines-1; i >= 0; i--)
    {
        string line;
        for (unsigned j = 0; j < numChars; j++)
        {
            line += mazeArray[i][j];
        }
        maze.Push(line);
    }
}

void MazeSolver::SaveStackIntoFile(Stack &maze, string fileName, int numLines)
{
    ofstream out(fileName);

    for (int i = 0; i < numLines; i++)
    {
        out << maze.Peek();
        maze.Pop();
    }
    out.close();
}


