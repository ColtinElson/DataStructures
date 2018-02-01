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
    linesFromFile.Add("Just adding in extra lines");
    linesFromFile.Add("More extra lines");
    linesFromFile.Add("Even more extra lines");
    linesFromFile.Add("So many extra lines");
    linesFromFile.Add("Extra lines");
    linesFromFile.Add("Is this enough lines?");
    linesFromFile.Add("Sure is");
    linesFromFile.Add("One more line just in case");

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
                editor.ReadFileIntoList(fileName);

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
                editor.ReadFileIntoList(fileName);


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
                editor.ReadFileIntoList(openFileName);

                saveFile = saveFileName;
                validResponse = true;
            }
        }
            //if they didn't enter edit, reprompt them
        else
        {
            cout << "edit not entered, " << editMessage << endl << endl << ">> ";
        }

    }

    //tell the user the files were read
    cout << "File read. " << endl;
    //set the quit value to false (becomes true if user enters true)
    bool quit = false;
    //set currentline to 1
    int currentLine = 1;

    //initially display list
    editor.DisplayLines(1, linesFromFile.CountNodes(), linesFromFile);

    //while the user hasn't entered quit
    while (!quit)
    {
        //prompt user for command
        cout << endl << "Please input your next command: (type h for available commands) " << endl << endl << ">> ";
        //get user's response
        getline(cin, userResponse);

        //get the first character as a lowercase of their input
        auto firstCharacter = static_cast<char>(tolower(userResponse.front()));

        //if it is h, display all commands
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
            cout << "'C' to view current line" << endl;

            cout << "Please input your next command: (type h for available commands) " << endl << endl << ">> ";
        }

            //if it's l, list based on whats after it
        else if (firstCharacter == 'l')
        {
            //check to see if a space is present
            size_t position = userResponse.find(' ');
            //if there is a space
            if (position != string::npos)
            {
                //check to see if there's another space
                string parameters = userResponse.substr(position+1);
                position = parameters.find(' ');
                //if there is two parameters given
                if (position != string::npos)
                {
                    //get the two parameters
                    string secondParameter = parameters.substr(position+1);
                    string firstParameter = parameters.substr(0, position);
                    //attempt to turn them to int
                    try
                    {
                        //get int params
                        int lineOne = stoi(firstParameter);
                        int lineTwo = stoi(secondParameter);
                        //if the first param is smaller than the second which is less than or equal to the number of nodes in the list
                        if (lineOne < lineTwo && lineTwo <= linesFromFile.CountNodes() && lineOne > 0)
                        {
                            //display all lines in the given range
                            editor.DisplayLines(lineOne, lineTwo, linesFromFile);
                        }
                            //if the params aren't valid, give error message
                        else
                        {
                            cout << "Invalid arguments, please try again" << endl;
                        }
                    }
                        //if you can't turn them to int, display error message
                    catch (invalid_argument)
                    {
                        cout << "Invalid arguments, please try again" << endl;
                    }
                }
                    //if only 1 param entered
                else
                {
                    //try and turn it to int
                    try
                    {
                        int lineOne = stoi(parameters);
                        //if its less than or equal to the number of nodes in list
                        if (lineOne <= linesFromFile.CountNodes() && lineOne > 0)
                        {
                            //display it
                            editor.DisplayLines(lineOne, lineOne, linesFromFile);
                        }
                            //if the param is out of range, display error message
                        else
                        {
                            cout << "Invalid arguments, please try again" << endl;
                        }
                    }
                        //if you can't turn them to int, display error message
                    catch (invalid_argument)
                    {
                        cout << "Invalid arguments, please try again" << endl;
                    }
                }
            }
                //if no params were entered, display all lines
            else
            {
                editor.DisplayLines(1,linesFromFile.CountNodes(), linesFromFile);
            }

        }

            //display all lines if user entered v
        else if (firstCharacter == 'v')
        {
            editor.DisplayLines(1, linesFromFile.CountNodes(), linesFromFile);
        }

            //if it's d, delete based on whats after it
        else if (firstCharacter == 'd')
        {
            //check to see if a space is present
            size_t position = userResponse.find(' ');
            //if there is a space
            if (position != string::npos)
            {
                //check to see if there's another space
                string parameters = userResponse.substr(position+1);
                position = parameters.find(' ');
                //if there is two parameters given
                if (position != string::npos)
                {
                    //get the two parameters
                    string secondParameter = parameters.substr(position+1);
                    string firstParameter = parameters.substr(0, position);
                    //attempt to turn them to int
                    try
                    {
                        //get int params
                        int lineOne = stoi(firstParameter);
                        int lineTwo = stoi(secondParameter);
                        //if the first param is smaller than the second which is less than or equal to the number of nodes in the list
                        if (lineOne < lineTwo && lineTwo <= linesFromFile.CountNodes() && lineOne > 0)
                        {
                            //display all lines in the given range
                            editor.DeleteLines(lineOne, lineTwo, linesFromFile);
                        }
                            //if the params aren't valid, give error message
                        else
                        {
                            cout << "Invalid arguments, please try again" << endl;
                        }
                    }
                        //if you can't turn them to int, display error message
                    catch (invalid_argument)
                    {
                        cout << "Invalid arguments, please try again" << endl;
                    }
                }
                    //if only 1 param entered
                else
                {
                    //try and turn it to int
                    try
                    {
                        int lineOne = stoi(parameters);
                        //if its less than or equal to the number of nodes in list
                        if (lineOne <= linesFromFile.CountNodes() && lineOne > 0)
                        {
                            //display it
                            editor.DeleteLines(lineOne, lineOne, linesFromFile);
                        }
                            //if the param is out of range, display error message
                        else
                        {
                            cout << "Invalid arguments, please try again" << endl;
                        }
                    }
                        //if you can't turn them to int, display error message
                    catch (invalid_argument)
                    {
                        cout << "Invalid arguments, please try again" << endl;
                    }
                }
            }
                //if no params were entered, display all lines
            else
            {
                editor.DeleteLines(currentLine,currentLine, linesFromFile);
            }

        }

            //if it's c, view current line in buffer
        else if (firstCharacter == 'c')
        {
            //call display line on current line
            editor.DisplayLines(currentLine, currentLine, linesFromFile);
        }

            //if user entered g, change current line based on params
        else if (firstCharacter == 'g')
        {
            //check to see if a space is present
            size_t position = userResponse.find(' ');
            //if there is a space
            if (position != string::npos)
            {
                string firstLine = userResponse.substr(position);
                //try and turn it to int
                try
                {
                    int lineOne = stoi(firstLine);
                    //if its less than or equal to the number of nodes in list
                    if (lineOne <= linesFromFile.CountNodes() && lineOne > 0)
                    {
                        //set current line to it
                        currentLine = lineOne;
                    }
                        //if the param is out of range, display error message
                    else
                    {
                        cout << "Invalid arguments, please try again" << endl;
                    }
                }
                    //if you can't turn them to int, display error message
                catch (invalid_argument)
                {
                    cout << "Invalid arguments, please try again" << endl;
                }
            }
                //if no params were entered, set current line to first line
            else
            {
                currentLine = 1;
            }
            //display current line
            editor.DisplayLines(currentLine, currentLine, linesFromFile);

        }

            //if user entered q
        else if (firstCharacter == 'q')
        {
            //quit program
            quit = true;
        }

            //display error message if not a valid command
        else
        {
            cout << "That is not a valid command. " << endl << endl;
        }
    }

    return 0;
}


















