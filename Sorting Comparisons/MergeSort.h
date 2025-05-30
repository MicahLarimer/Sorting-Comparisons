/*******************************************************************************
* Function Name : MergeSort.h
* Parameters : None
* Return Value : int
* Purpose :Implements the Merge Sort algorithm
******************************************************************************/
#include "Swap.h"

const int SIZE = 1000; // Define the size for the temporary array in Merge

template<class ItemType>
void Merge(ItemType values[], int leftFirst, int leftLast, int rightFirst, int rightLast, int& swapCount)
// Post: values[leftFirst]..values[leftLast] and 
//       values[rightFirst]..values[rightLast] have been merged.
//       values[leftFirst]..values[rightLast] is now sorted.
{
    ItemType tempArray[SIZE];
    int index = leftFirst;
    int saveFirst = leftFirst;

    while ((leftFirst <= leftLast) && (rightFirst <= rightLast))
    {
        if (values[leftFirst] < values[rightFirst])
        {
            tempArray[index] = values[leftFirst];
            leftFirst++;
        }
        else
        {
            tempArray[index] = values[rightFirst];
            rightFirst++;
        }
        index++;
    }

    while (leftFirst <= leftLast)
        // Copy remaining items from left half.
    {
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    }

    while (rightFirst <= rightLast)
        // Copy remaining items from right half.
    {
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    }

    for (index = saveFirst; index <= rightLast; index++)
        values[index] = tempArray[index];
}

template<class ItemType>
void MergeSort(ItemType values[], int first, int last, int& swapCount)
// Post: The elements in values are sorted by key.
{
    if (first < last)
    {
        int middle = (first + last) / 2;
        MergeSort(values, first, middle, swapCount);
        MergeSort(values, middle + 1, last, swapCount);
        Merge(values, first, middle, middle + 1, last, swapCount);
    }
}

#pragma once
