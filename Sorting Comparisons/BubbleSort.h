/*******************************************************************************
* Function Name : BubbleSort.h
* Parameters : None
* Return Value : int
* Purpose :Implements the Bubble Sort algorithm
*******************************************************************************/
#include "Swap.h"

template<class ItemType>
void BubbleUp(ItemType values[], int startIndex, int endIndex, int& swapCount)
// Post: Adjacent pairs that are out of order have been 
//       switched between values[startIndex]..values[endIndex]
//       beginning at values[endIndex].
{
    for (int index = endIndex; index > startIndex; index--)
        if (values[index] < values[index - 1])
            Sorting::Swap(values[index], values[index - 1], swapCount);
}

template<class ItemType>
void BubbleSort(ItemType values[], int numValues, int& swapCount)
// Post: The elements in the array values are sorted by key.
{
    int current = 0;

    while (current < numValues - 1)
    {
        BubbleUp(values, current, numValues - 1, swapCount);
        current++;
    }
}

#pragma once
