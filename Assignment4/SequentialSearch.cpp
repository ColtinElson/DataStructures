#include "SequentialSearch.h"

//Searches through array one number at a time. If it finds what it's looking for it will return true, otherwise return false
//since position is passed by ref, the position is just auto given
bool SequentialSearch::sequentialSearch(const int *list, const int listSize, const int &target, int &position)
{
    for (position = 0; position < listSize; position++)
    {
        if (list[position] == target)
        {
            return true;
        }
    }

    return false;
}
