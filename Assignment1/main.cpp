//
// Created by ColtinElson on 1/15/18.
//

#include <iostream>
#include "LinkedList.h"
#include "Editor.h"

using namespace std;
int main()
{
    //Test LinkedList
    LinkedList linesFromFile;
    linesFromFile.Add("Test Lines");
    linesFromFile.Add("This is to check if the editor portion of this assignment works.");
    linesFromFile.Add("If i'm using this, then for some reason I couldn't pass the linkedList");
    linesFromFile.Add("From one function back to main properly");

    //Instance of editor
    Editor editor;
    //LinkedList linesFromFile;
    //save the name of the file to save to
    string saveFile;
    //variable for the users response
    string userResponse;
    //edit message to display to the user since it is displayed mutlitple times
    string editMessage = "please type 'edit' then a file you wish to edit, and the file you would like to save it to";

    //welcome message
    cout << endl << "Welcome to the file editor program!" << endl;
    cout << "To begin, " << editMessage << endl;
    cout << "e.g. edit read.txt save.txt" << endl << endl << ">> ";

    //set initial valid response value to false
    bool validResponse = false;

    //loop through until valid response is given
    while (!validResponse)
    {
        //get user input
        getline(cin, userResponse);

        //if the user typed edit
        if (userResponse.find("edit") != string::npos)
        {
            //check if they entered any parameters
            string result = editor.CheckForFiles(userResponse);
            //if they didn't prompt them for the two files
            if (result == "none") {
                bool fileEntered = false;
                string fileName;

                //loop until they enter a valid file name
                while (!fileEntered) {
                    cout << "Please enter the name for the file to load: " << endl << endl << ">> ";
                    getline(cin, fileName);
                    fileEntered = editor.CheckFile(fileName);
                }
                //read file into list
                //linesFromFile = editor.ReadFileIntoList(fileName);

                //re ask for save file
                fileEntered = false;

                //loop until they enter a valid file name
                while (!fileEntered) {
                    cout << "Please enter the name for the file to save to: " << endl << endl << ">> ";
                    getline(cin, fileName);
                    fileEntered = editor.CheckFile(fileName);
                }

                //save the save file name
                saveFile = fileName;
                //leave loop
                validResponse = true;
            }

                //if they just entered one file, ask for save file
            else if (result == "one")
            {
                size_t position = userResponse.find(' ');
                string fileName = userResponse.substr(position+1);

                //check open file name
                editor.CheckFile(fileName);

                //read file into list
                //linesFromFile = editor.ReadFileIntoList(fileName);


                //loop through until user enters valid save file
                bool fileEntered = false;

                while (!fileEntered) {
                    cout << "Please enter the name for the file to save to: " << endl << endl << ">> ";
                    getline(cin, fileName);
                    fileEntered = editor.CheckFile(fileName);
                }

                //save the save file name
                saveFile = fileName;
                //leave loop
                validResponse = true;
            }
                //otherwise, open the two files
            else
            {
                size_t position = userResponse.find(' ');
                string fileName = userResponse.substr(position+1);
                position = fileName.find(' ');
                string saveFileName = fileName.substr(position+1);
                string openFileName = fileName.substr(0, position);

                //open file names
                editor.CheckFile(openFileName);
                //linesFromFile = editor.ReadFileIntoList(openFileName);

                saveFile = saveFileName;
                validResponse = true;
            }
        }
        else
        {
            cout << "edit not entered, " << editMessage << endl << endl << ">> ";
        }

    }

    //cout << linesFromFile << endl;
    cout << "File read. ";
    bool quit = false;
    int currentLine = 1;

    while (!quit)
    {
        cout << "Please input your next command: (type h for available commands) " << endl << endl << ">> ";
        getline(cin, userResponse);

        auto firstCharacter = static_cast<char>(tolower(userResponse.front()));
        if (firstCharacter == 'h')
        {
            cout << "Available commands: " << endl;
            cout << "'I' to insert a line, follow with a number 'n' to insert after line 'n'" << endl;
            cout << "'D' to delete a line, follow with a number 'n' to delete specific line or " <<
                    "'n m' to delete all lines in given range" << endl;
            cout << "'V' to display all lines" << endl;
            cout << "'G' to go to the first line, follow with a number 'n' to go to specific line" << endl;
            cout << "'L' to list all lines, follow with a number 'n' to list specific line or " <<
                 "'n m' to list all lines in given range" << endl;
            cout << "'S' to substitute the current line, follow with a number 'n' to substitute a specific line" << endl;
            cout << "'E' to save all changes to the save file and then quit program" << endl;
            cout << "'Q' to quit without saving changes" << endl;

            cout << "Please input your next command: (type h for available commands) " << endl << endl << ">> ";
        }
        else if (firstCharacter == 'l')
        {
            size_t position = userResponse.find(' ');
            if (position != string::npos)
            {
                string parameters = userResponse.substr(position+1);
                position = parameters.find(' ');
                if (position != string::npos)
                {
                    string secondParameter = parameters.substr(position+1);
                    string firstParameter = parameters.substr(0, position);
                    try
                    {
                        int lineOne = stoi(firstParameter);
                        int lineTwo = stoi(secondParameter);
                        if (lineOne < lineTwo && lineTwo <= linesFromFile.CountNodes())
                        {
                            editor.DisplayLines(lineOne, lineTwo, linesFromFile);
                        }
                        else
                        {
                            cout << "Invalid arguments, please try again" << endl;
                        }
                    }
                    catch (invalid_argument)
                    {
                        cout << "Invalid arguments, please try again" << endl;
                    }
                }
                else
                {
                    try
                    {
                        int lineOne = stoi(parameters);
                        if (lineOne <= linesFromFile.CountNodes())
                        {
                            editor.DisplayLines(lineOne, lineOne, linesFromFile);
                        }
                        else
                        {
                            cout << "Invalid arguments, please try again" << endl;
                        }
                    }
                    catch (invalid_argument)
                    {
                        cout << "Invalid arguments, please try again" << endl;
                    }
                }
            }
            else
            {
                editor.DisplayLines(1,linesFromFile.CountNodes(), linesFromFile);
            }

        }

        else if (firstCharacter == 'v')
        {
            editor.DisplayLines(1, linesFromFile.CountNodes(), linesFromFile);
        }

        else if (firstCharacter == 'd')
        {
            size_t position = userResponse.find(' ');
            if (position != string::npos)
            {
                string parameters = userResponse.substr(position+1);
                position = parameters.find(' ');
                if (position != string::npos)
                {
                    string secondParameter = parameters.substr(position+1);
                    string firstParameter = parameters.substr(0, position);
                    try
                    {
                        int lineOne = stoi(firstParameter);
                        int lineTwo = stoi(secondParameter);
                        if (lineOne < lineTwo && lineTwo <= linesFromFile.CountNodes())
                        {
                            editor.DeleteLines(lineOne, lineTwo, linesFromFile);
                        }
                        else
                        {
                            cout << "Invalid arguments, please try again" << endl;
                        }
                    }
                    catch (invalid_argument)
                    {
                        cout << "Invalid arguments, please try again" << endl;
                    }
                }
                else
                {
                    try
                    {
                        int lineOne = stoi(parameters);
                        if (lineOne <= linesFromFile.CountNodes())
                        {
                            editor.DeleteLines(lineOne, lineOne, linesFromFile);
                        }
                        else
                        {
                            cout << "Invalid arguments, please try again" << endl;
                        }
                    }
                    catch (invalid_argument)
                    {
                        cout << "Invalid arguments, please try again" << endl;
                    }
                }
            }
            else
            {
                editor.DeleteLines(currentLine,currentLine+1, linesFromFile);
            }

        }

        else if (firstCharacter == 'q')
        {
            quit = true;
        }

        else
        {
            cout << "That is not a valid command. " << endl << endl;
        }
    }

    return 0;
}


















