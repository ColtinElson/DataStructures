#include <fstream>
#include <sstream>
#include "MazeSolver.h"


void MazeSolver::SolveMaze(Stack &maze)
{
    int numLines = maze.GetStackSize();

    //get num of columns for matrix
    string firstLine = maze.Peek();
    int numChars = 0;
    for (char current : firstLine) {
        //if its a maze square, add 1 to numChars
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

    //initiate path stack
    Stack path;
    //cell will be represented as a string of its coordinates

    //set strings for starting cell and end cell
    string startCell = "1,0";
    string endCell = to_string(numLines-2) + "," + to_string(numChars-1);

    //set starting point as first node
    mazeArray[1][0] = '.';
    path.Push(startCell);

    string currentCell = startCell;
    int testCounter = 0;
    //loop through until reaching the end of the maze
    while (currentCell != endCell)
    {
        string newCell = currentCell;
        int xCoord = 0;
        int yCoord = 0;
        //parse currentCell for coords
        stringstream xValue(currentCell.substr(0,currentCell.find(',')));
        xValue >> xCoord;

        stringstream yValue(currentCell.substr(currentCell.find(',')+1));
        yValue >> yCoord;

        //check available neighbours of the current cell

        //check south and east last to bias towards that direction

        //First check north
        if ((xCoord-1) >= 0 && mazeArray[xCoord-1][yCoord] == ' ')
        {
            mazeArray[xCoord-1][yCoord] = '.';
            newCell = to_string(xCoord-1) + "," + to_string(yCoord);
            path.Push(newCell);
        }

        //next check west
        if ((yCoord-1) >= 0 && mazeArray[xCoord][yCoord-1] == ' ')
        {
            mazeArray[xCoord][yCoord-1] = '.';
            newCell = to_string(xCoord) + "," + to_string(yCoord-1);
            path.Push(newCell);
        }

        //then south
        if ((xCoord+1) < numLines && mazeArray[xCoord+1][yCoord] == ' ')
        {
            mazeArray[xCoord+1][yCoord] = '.';
            newCell = to_string(xCoord+1) + "," + to_string(yCoord);
            path.Push(newCell);
        }

        //Finally check east
        if ((yCoord+1) < numChars && mazeArray[xCoord][yCoord+1] == ' ')
        {
            mazeArray[xCoord][yCoord+1] = '.';
            newCell = to_string(xCoord) + "," + to_string(yCoord+1);
            path.Push(newCell);
            if (newCell == endCell)
            {
                break;
            }
        }

        //if no viable neighbour was found
        if (newCell == currentCell)
        {
            if (path.Peek() != startCell)
            {
                path.Pop();
            }
        }
        currentCell = path.Peek();
    }

    int pathLength = path.GetStackSize();

    //set path spots to # to indicate path through maze
    for (int i = 0; i < pathLength; i++)
    {
        int xCoord = 0;
        int yCoord = 0;
        int yTester = 0;
        string xString = path.Peek().substr(0,path.Peek().find(','));
        string yString = path.Peek().substr(xString.length()+1);

        //parse currentCell for coords
        stringstream xValue(xString);
        xValue >> xCoord;

        stringstream yValue(yString);
        yValue >> yCoord;

        //set values in stack to #
        mazeArray[xCoord][yCoord] = '#';

        //remove valueu from stack
        path.Pop();
    }

    //print maze
    for (int i = 0; i < numLines; i++)
    {
        for (int j = 0; j < numChars; j++)
        {
            //turn visited squares back to whitespace
            if (mazeArray[i][j] == '.')
            {
                mazeArray[i][j] = ' ';
            }
            cout << mazeArray[i][j];
        }
        cout << endl;
    }

    //turn maze back into stack
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

void MazeSolver::SaveStackIntoFile(Stack &maze, string fileName)
{
    ofstream out(fileName);

    int mazeSize = maze.GetStackSize();

    for (int i = 0; i < mazeSize; i++)
    {
        out << maze.Peek() << endl;
        maze.Pop();
    }

    out.close();
}


