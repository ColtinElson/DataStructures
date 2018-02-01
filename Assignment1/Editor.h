//
// Created by ColtinElson on 1/15/18.
//

#ifndef ASSIGNMENT1_EDITOR_H
#define ASSIGNMENT1_EDITOR_H
#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

class Editor {

public:
    LinkedList ReadFileIntoList(string fileName);

    void SaveListIntoFile(ofstream file, LinkedList &list);

    void DeleteLines(int firstLine, int lastLine, LinkedList &list);

    void ReplaceLine(int lineNumber, string newLine, LinkedList &list);

    void AddALine(int lineNumber, string newLine, LinkedList &list);

    void DisplayLines(int firstLine, int lastLine, LinkedList &list);

    string CheckForFiles(string userInput);

    bool CheckFile(string fileName);
};


#endif //ASSIGNMENT1_EDITOR_H
