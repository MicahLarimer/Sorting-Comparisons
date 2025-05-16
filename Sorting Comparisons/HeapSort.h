/*******************************************************************************
* Function Name : HeapSort.h
* Parameters : None
* Return Value : int
* Purpose : Implements the Heap Sort algorithm
*******************************************************************************/
#include "Swap.h"

template<class ItemType>
void ReheapDown(ItemType elements[], int root, int bottom, int& swapCount)
// Post: Heap property is restored.
{
    int maxChild;
    int rightChild;
    int leftChild;

    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;
    if (leftChild <= bottom)
    {
        if (leftChild == bottom)
            maxChild = leftChild;
        else
        {
            if (elements[leftChild] <= elements[rightChild])
                maxChild = rightChild;
            else
                maxChild = leftChild;
        }
        if (elements[root] < elements[maxChild])
        {
            Sorting::Swap(elements[root], elements[maxChild], swapCount);
            ReheapDown(elements, maxChild, bottom, swapCount);
        }
    }
}

template<class ItemType>
void HeapSort(ItemType values[], int numValues, int& swapCount)
// Pre:  Struct HeapType is available.
// Post: The elements in the array values are sorted by key.
{
    int index;

    // Convert the array of values into a heap.
    for (index = numValues / 2 - 1; index >= 0; index--)
        ReheapDown(values, index, numValues - 1, swapCount);

    // Sort the array.
    for (index = numValues - 1; index >= 1; index--)
    {
        Sorting::Swap(values[0], values[index], swapCount);
        ReheapDown(values, 0, index - 1, swapCount);
    }
}
#pragma once
