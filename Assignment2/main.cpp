#include <iostream>
#include "Stack.h"
#include "MazeReader.h"
#include "MazeSolver.h"

void printError(myerror_code err)
// Generic error print routine
{
    switch (err) {
        case overflow: {
            cout << "Error encountered: stack overflow" << endl;
        }
        case underflow: {
            cout << "Error encountered: stack underflow" << endl;
        }
        default: {
            cout << "Error encountered: other" << endl;
        }
    }

}

int main()
{
    Stack maze;
    string mazeFile;
    bool moveOn = false;

    cout << "Welcome to the maze solver!" << endl;
    cout << "This program will take a maze you give it and spit out a solution!" << endl << endl;

    while (!moveOn)
    {
        cout << "To begin, what maze would you like to solve?" << endl;
        getline(cin, mazeFile);

        moveOn = MazeReader::CheckFile(mazeFile);

        if (!moveOn)
        {
            cout << "Sorry, that's not a valid file. Please try again." << endl << endl;
        }
    }

    MazeReader::ReadFileIntoArray(maze, mazeFile);

    cout << maze << endl;

    cout << "What would you like to save the solution as?" << endl;

    getline(cin, mazeFile);

    MazeSolver::SolveMaze(maze);

    MazeSolver::SaveStackIntoFile(maze, mazeFile);
    return 0;
}