/*******************************************************************************
* Program Name:Sorting Comparison
* Created Date: 5/10/25
* Created By:Micah Larimer
* Purpose: Compare the relative performance of different sorting algorithms on the same data set and  compare the relative performance of the same algorithm on two different data sets.
* Acknowledgements:Kris Holt-Father in Law(Software Engineer)
*******************************************************************************/
/*******************************************************************************
* Function Name : main()
* Parameters : None
* Return Value : int
* Purpose :the driver of the program that test all the sorting algorithms
*******************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "MergeSort.h"
#include "QuickSort.h"
#include "HeapSort.h"
#include "Swap.h"

using namespace std;

const int MAX_SIZE = 1000;

// Function to read integers from a file
void readFile(const string& filename, int arr[], int& size) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);
    }
    
    string line;
    size = 0;
    
    // Skip comments and empty lines
    while (getline(file, line)) {
        // Skip lines starting with // or empty lines
        if (line.empty() || line.substr(0, 2) == "//") {
            continue;
        }
        // Try to convert the line to an integer
        try {
            arr[size] = stoi(line);
            size++;
            if (size >= MAX_SIZE) break;
        } catch (...) {
            // Skip lines that aren't valid integers
            continue;
        }
    }
    file.close();
}

// Function to print array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Function to test a sorting algorithm
void testSort(const string& sortName, void (*sortFunc)(int[], int, int&), int arr[], int size) {
    cout << "\nTesting " << sortName << ":" << endl;
    cout << "Original array: ";
    printArray(arr, size);

    // Create a copy for sorting
    int sortedArr[MAX_SIZE];
    for (int i = 0; i < size; i++) {
        sortedArr[i] = arr[i];
    }

    // Perform the sort
    int swapCount = 0;
    sortFunc(sortedArr, size, swapCount);

    cout << "Sorted array: ";
    printArray(sortedArr, size);
    cout << "Number of swaps: " << swapCount << endl;
    cout << "-------------------" << endl;
}

int main() {
    int arr100[MAX_SIZE], arr1000[MAX_SIZE];
    int size100 = 0, size1000 = 0;

    // Read input files
    readFile("input100.txt", arr100, size100);
    readFile("input1000.txt", arr1000, size1000);

    // Test with input100.txt
    cout << "Results for input100.txt:" << endl;
    testSort("BubbleSort", BubbleSort, arr100, size100);
    testSort("SelectionSort", SelectionSort, arr100, size100);
    testSort("InsertionSort", InsertionSort, arr100, size100);
    testSort("MergeSort", [](int arr[], int size, int& swapCount) { MergeSort(arr, 0, size - 1, swapCount); }, arr100, size100);
    testSort("QuickSort", [](int arr[], int size, int& swapCount) { QuickSort(arr, 0, size - 1, swapCount); }, arr100, size100);
    testSort("HeapSort", HeapSort, arr100, size100);

    // Test with input1000.txt
    cout << "\nResults for input1000.txt:" << endl;
    testSort("BubbleSort", BubbleSort, arr1000, size1000);
    testSort("SelectionSort", SelectionSort, arr1000, size1000);
    testSort("InsertionSort", InsertionSort, arr1000, size1000);
    testSort("MergeSort", [](int arr[], int size, int& swapCount) { MergeSort(arr, 0, size - 1, swapCount); }, arr1000, size1000);
    testSort("QuickSort", [](int arr[], int size, int& swapCount) { QuickSort(arr, 0, size - 1, swapCount); }, arr1000, size1000);
    testSort("HeapSort", HeapSort, arr1000, size1000);

    return 0;
}
