/*******************************************************************************
* Function Name : InsertionSort.h
* Parameters : None
* Return Value : int
* Purpose :Implements the Insertion Sort algorithm
*******************************************************************************/

#include "Swap.h"

template<class ItemType>
void InsertItem(ItemType values[], int startIndex, int endIndex, int& swapCount)
// Post: values[0]..values[endIndex] are now sorted.
{
    bool finished = false;
    int current = endIndex;
    bool moreToSearch = (current != startIndex);

    while (moreToSearch && !finished)
    {
        if (values[current] < values[current - 1])
        {
            Sorting::Swap(values[current], values[current - 1], swapCount);
            current--;
            moreToSearch = (current != startIndex);
        }
        else
            finished = true;
    }
}

template<class ItemType>
void InsertionSort(ItemType values[], int numValues, int& swapCount)
// Post: The elements in the array values are sorted by key.
{
    for (int count = 0; count < numValues; count++)
        InsertItem(values, 0, count, swapCount);
}

#pragma once
