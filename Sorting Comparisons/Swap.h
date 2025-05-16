/*******************************************************************************
* Function Name : Swap.h
* Parameters : None
* Return Value : int
* Purpose :provides a template function that swaps elemnts and counts the number of swaps performed
*******************************************************************************/
#pragma once

namespace Sorting {
    template<class ItemType>
    void Swap(ItemType& a, ItemType& b, int& swapCount) {
        ItemType temp = a;
        a = b;
        b = temp;
        swapCount++;
    }
}

using Sorting::Swap; 
