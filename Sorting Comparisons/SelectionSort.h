/*******************************************************************************
* Function Name : SelectionSort.h
* Parameters : None
* Return Value : int
* Purpose :Implements the Selection Sort algorithm
*******************************************************************************/
#include "Swap.h"

template<class ItemType>
int MinIndex(ItemType values[], int startIndex, int endIndex)
// Post: Returns the index of the smallest value in
//       values[startIndex]..values[endIndex].
{
    int indexOfMin = startIndex;
    for (int index = startIndex + 1; index <= endIndex; index++)
        if (values[index] < values[indexOfMin])
            indexOfMin = index;
    return indexOfMin;
}


template<class ItemType>
void SelectionSort(ItemType values[], int numValues, int& swapCount)
// Post: The elements in the array values are sorted by key.
{
    int endIndex = numValues - 1;
    for (int current = 0; current < endIndex; current++)
        Sorting::Swap(values[current], values[MinIndex(values, current, endIndex)], swapCount);
}


#pragma once
