#include "BinarySearch.h"

//Smart searches through array one number at a time. Splits in half. If it's in the first half it splits that half, etc.
//If it finds what it's looking for it will return true, otherwise return false
//Since position is passed by ref, the position is just auto given

bool BinarySearch::binarySearch(const int *list, int listSize, const int &target, int &position)
{
    //variables for position (lowest), middle of list and end of list
    position = 0;
    int middle;
    int end = listSize-1;

    //while the position is less than the end (haven't reached end of list
    while (position <= end)
    {
        //get the middle index
        middle = (position+(end))/2;

        //if the target is less than the middle value, recheck left half
        if (target < list[middle])
        {
            end = middle -1;
        }
            //if the target is more, recheck right half
        else if (target > list[middle])
        {
            position = middle + 1;
        }
            //otherwise, the middle is the target so set the position and return true
        else
        {
            position = middle;
            return true;
        }
    }
    //if it can't find the target, return false
    return false;
}
