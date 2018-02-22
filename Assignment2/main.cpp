#include <iostream>
#include "Stack.h"
#include "MazeReader.h"
#include "MazeSolver.h"

int main()
{
    //initialize maze stack and mazeFile name
    Stack maze;
    string mazeFile;

    //move on variable to look for valid maze
    bool moveOn = false;

    //welcome message
    cout << "Welcome to the maze solver!" << endl;
    cout << "This program will take a maze you give it and spit out a solution!" << endl << endl;

    //loop through until valid maze is entered
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

    //read maze into stack
    MazeReader::ReadFileIntoStack(maze, mazeFile);

    //print out the maze
    cout << maze << endl;

    //ask user what they want to save maze solution as
    cout << "What would you like to save the solution as?" << endl;

    getline(cin, mazeFile);

    //solve the maze
    MazeSolver::SolveMaze(maze);

    //save solution into file
    MazeSolver::SaveStackIntoFile(maze, mazeFile);

    return 0;
}