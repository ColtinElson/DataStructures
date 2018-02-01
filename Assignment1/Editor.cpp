//
// Created by ColtinElson on 1/15/18.
//

#include "Editor.h"

LinkedList Editor::ReadFileIntoList(string fileName)
{
    ifstream file;
    file.open(fileName);
    string line;
    LinkedList tempFile;

    while (getline(file, line))
    {
        if (!line.empty() && line.length()>0)
        {
            tempFile.Add(line);
        }
    }
    file.close();
    return tempFile;
}

void Editor::SaveListIntoFile(ofstream file, LinkedList &list)
{

}

void Editor::DeleteLines(int firstLine, int lastLine, LinkedList &list)
{
    firstLine -= 1;
    lastLine -= 1;

    for (lastLine; lastLine >= firstLine; lastLine--)
    {
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
    int nodeNumber = 0;
    firstLine -= 1;
    Node *currentNode = list.first;

    while (currentNode != nullptr && nodeNumber != firstLine)
    {
        currentNode = currentNode->next;
        nodeNumber++;
    }

    for (firstLine; firstLine < lastLine; firstLine++)
    {
        if (currentNode != nullptr)
        {
            cout << firstLine+1 << " - " << currentNode->data << endl;
            currentNode = currentNode->next;
        }
    }
}

string Editor::CheckForFiles(string userInput)
{
    size_t position = userInput.find(' ');
    if (position == string::npos)
    {
        return "none";
    }
    else
    {
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

