Sorting Algorithms Analysis
Overview
A C++ project implementing and analyzing sorting algorithms (Bubble, Merge, Quick, and Heap Sort) to optimize performance for large datasets. Includes debugging enhancements to track swap counts and performance metrics, with applications to construction task scheduling. Inspired by Hyphen Solutions' BuildPro for efficient workflow management.
Features

Algorithm Implementation: Developed Bubble, Merge, Quick, and Heap Sort, optimized for 1000+ inputs.
Performance Analysis: Measured runtime and swap counts for sorted and unsorted data, comparing algorithm efficiency.
Debugging: Fixed zero-swap issue for sorted inputs, ensuring accurate metrics with debug outputs.
Task Scheduling Application: Applied sorting to prioritize construction tasks, achieving O(n log n) efficiency.

Technologies

C++: Core implementation using STL for data structures and algorithms.
Data Structures: Arrays and heaps for sorting operations.
Tools: G++ compiler, Visual Studio Code, Git.

Installation

Clone the repository:git clone https://github.com/MicahLarimer/Sorting-Algorithms.git


Navigate to the project directory:cd Sorting-Algorithms


Ensure a C++ compiler (e.g., g++) is installed.

Usage

Compile the code:g++ sorting_algorithms.cpp -o sorting


Run the program:./sorting


Follow prompts to select an algorithm and input size, or modify sorting_algorithms.cpp for custom tests.

Example Output
Running Quick Sort on 1000 elements:
- Time: 0.0023 seconds
- Swaps: 3421
No zero-swap errors detected.

Future Improvements
Add visualization of sorting steps using a GUI framework.
Implement parallel sorting for multi-core processors.
Extend to graph-based scheduling algorithms for task dependencies.
