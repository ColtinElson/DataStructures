cmake_minimum_required(VERSION 3.9)
project(Assignment2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Assignment2 main.cpp Stack.cpp Stack.h StackNode.cpp StackNode.h MazeReader.cpp MazeReader.h MazeSolver.cpp MazeSolver.h)