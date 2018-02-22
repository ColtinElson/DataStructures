#ifndef ASSIGNMENT2_MAZESOLVER_H
#define ASSIGNMENT2_MAZESOLVER_H

#include "Stack.h"

class MazeSolver {

public:
    static void SolveMaze(Stack &maze);

    static void SaveStackIntoFile(Stack &maze, string fileName);

};


#endif //ASSIGNMENT2_MAZESOLVER_H
