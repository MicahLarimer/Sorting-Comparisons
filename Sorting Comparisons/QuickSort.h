#include "Swap.h"

template <class ItemType>
void Split(ItemType values[], int first, int last, int& splitPoint, int& swapCount)
{
    ItemType splitVal = values[first];
    int saveFirst = first;
    bool onCorrectSide;

    first++;
    do
    {
        onCorrectSide = true;
        while (onCorrectSide)         // Move first toward last.
            if (values[first] > splitVal)
                onCorrectSide = false;
            else
            {
                first++;
                onCorrectSide = (first <= last);
            }

        onCorrectSide = (first <= last);
        while (onCorrectSide)             // Move last toward first.
            if (values[last] <= splitVal)
                onCorrectSide = false;
            else
            {
                last--;
                onCorrectSide = (first <= last);
            }

        if (first < last)
        {
            Sorting::Swap(values[first], values[last], swapCount);
            first++;
            last--;
        }
    } while (first <= last);

    splitPoint = last;
    Sorting::Swap(values[saveFirst], values[splitPoint], swapCount);
}


template<class ItemType>
void QuickSort(ItemType values[], int first, int last, int& swapCount)
{
    if (first < last)
    {
        int splitPoint;

        Split(values, first, last, splitPoint, swapCount);
        // values[first]..values[splitPoint-1] <= splitVal
        // values[splitPoint] = splitVal
        // values[splitPoint+1]..values[last] > splitVal

        QuickSort(values, first, splitPoint - 1, swapCount);
        QuickSort(values, splitPoint + 1, last, swapCount);
    }
}
#pragma once
