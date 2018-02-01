//
// Created by ColtinElson on 1/15/18.
//

#include "Editor.h"

//read file into list
LinkedList Editor::ReadFileIntoList(string fileName)
{
    //open file
    ifstream file;
    file.open(fileName);
    //declare string and LinkedList variables
    string line;
    LinkedList tempFile;

    //while there are lines to read
    while (getline(file, line))
    {
        //if they have something in them
        if (!line.empty())
        {
            //add them to list
            tempFile.Add(line);
        }
    }
    //close the file
    file.close();
    //return the list
    return tempFile;
}

void Editor::SaveListIntoFile(ofstream file, LinkedList &list)
{

}

void Editor::DeleteLines(int firstLine, int lastLine, LinkedList &list)
{
    //convert first and last line to 0 based instead of 1 based
    firstLine -= 1;
    lastLine -= 1;

    //loop from the last line down to the first line
    for (lastLine; lastLine >= firstLine; lastLine--)
    {
        //delete the last line
        list.DeleteNode(lastLine);
    }
}

void Editor::ReplaceLine(int lineNumber, string newLine, LinkedList &list)
{

}

void Editor::AddALine(int lineNumber, string newLine, LinkedList &list)
{

}

void Editor::DisplayLines(int firstLine, int lastLine, LinkedList &list)
{
    //initialize node number as 0
    int nodeNumber = 0;
    //convert to 0 based counting system
    firstLine -= 1;
    //get first node
    Node *currentNode = list.first;

    //loop through until you reach the specified line
    while (currentNode != nullptr && nodeNumber != firstLine)
    {
        //loop through the nodes until you hit the first line
        currentNode = currentNode->next;
        nodeNumber++;
    }

    //loop through the nodes from first line to last line
    for (firstLine; firstLine < lastLine; firstLine++)
    {
        //if its not null
        if (currentNode != nullptr)
        {
            //display the line number plus the line
            cout << firstLine+1 << " - " << currentNode->data << endl;
            //get next node
            currentNode = currentNode->next;
        }
    }
}

//check if you can params have been entered
string Editor::CheckForFiles(string userInput)
{
    //get position of space
    size_t position = userInput.find(' ');
    //if no space is present
    if (position == string::npos)
    {
        return "none";
    }
    else
    {
        //if there is a space, check to see if there's another one
        string fileNames = userInput.substr(position+1);
        position = fileNames.find(' ');
        if (position == string ::npos)
        {
            return "one";
        }
        else
        {
            return "two";
        }
    }
}

bool Editor::CheckFile(string fileName) {

    //create the ifstream
    ifstream inputFile;
    //set up the exceptions
    inputFile.exceptions(ifstream::failbit | ifstream::badbit);

    //try to open the file
    //if it opens, return true otherwise return false;
    try
    {
        inputFile.open(fileName);
        inputFile.close();
        return true;
    }
    catch(ifstream::failure&)
    {
        //if you can't open the file, try to make the file
        //if you can't return false
        try {
            ofstream file;
            file.open(fileName);
            file.close();
            return true;
        }
        catch(ofstream::failure&)
        {
            return false;
        }
    }
}

