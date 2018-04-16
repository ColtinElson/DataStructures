//
// Created by Coltin Elson on 4/16/18.
// based on code from Hal O'connell
//

#include "FileHandler.h"
#include <fstream>
#include <sstream>

void FileHandler::ReadFileIntoArray(string FileName, string *array, int arraySize)
{
    //open file
    ifstream file;
    file.open(FileName);
    //declare string variable
    string line;
    int i = 0;
    //while there are lines to read
    while (getline(file, line))
    {
        //if they have something in them
        if (!line.empty())
        {
            //add them to the searchTree
            array[i] = line;
            i++;
        }
    }

    //close the file
    file.close();
}

void FileHandler::ReadFileWordsIntoArray(string FileName, string *array, int arraySize)
{
    //open file
    ifstream file;
    file.open(FileName);
    //declare string variable
    string line;

    //while there are lines to read
    while (getline(file, line))
    {
        //if they have something in them
        if (!line.empty())
        {
            //get the length of the line
            int length = line.length()-1;
            //parse from end to beginning of line
            for (int i = length; i >= 0; i--)
            {
                //if it's a capital, lowercase it
                line[i] = tolower(line[i]);
                //get it's ascii code
                int ascii = toascii(line[i]);

                //if it's a space, move on
                if (ascii == 32)
                {
                    continue;
                }
                    //if it's not between 97 and 122 (a-z) delete it
                else if (ascii > 122 || ascii < 97)
                {
                    line.erase(i, 1);
                }
            }
            //variables to split string
            string split;
            stringstream stream(line);

            int i = 0;

            //while there are more words (split by space)
            while(getline(stream, split, ' '))
            {
                array[i] = split;
                i++;
            }

        }
    }

    //close the file
    file.close();
}
