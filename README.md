# Non-Comparison Sorting Algorithms

## Overview:

This project implements several non-comparison based sorting algorithms in C++. The following algorithms are included:

* Counting Sort (Stable and Non-Stable)
* LSD Radix Sort
* Bucket Sort
* Pigeonhole Sort

The project also includes multiple experimental cases to evaluate the performance of these algorithms under different input conditions, such as random data, sorted and reverse sorted data, small range, and large range datasets.

## Prerequisites:

* C++ compiler supporting C++11 or later (e.g. g++, MSVC)
* Visual Studio Code or any C++ IDE (optional)
* CMake (optional if building with a CMake project)

## Project Structure:

/NonComparisonSorting

* algorithms.cpp
* README.md

## How to Compile and Run:

### Using Visual Studio Code:

1. Open the project folder in Visual Studio Code.
2. Ensure the C++ extension is installed.
3. Open main.cpp.
4. Open the terminal inside VS Code.
5. Compile the code using the following command:

g++ -std=c++11 main.cpp -o sorting

6. Run the compiled program:

./sorting        (Linux or macOS)
sorting.exe      (Windows)

Using Command Line:

1. Navigate to the directory containing main.cpp.
2. Compile using your C++ compiler:

g++ -std=c++11 main.cpp -o sorting

3. Execute the program:

./sorting        (Linux or macOS)
sorting.exe      (Windows)

## Program Output:

The program performs the following for each dataset:

* Runs all five sorting algorithms.
* Measures and displays execution time in milliseconds.
* Outputs results for the following dataset cases:

  1. Random values (moderate range)
  2. Already sorted values
  3. Reverse sorted values
  4. Small range values
  5. Large range values

The output will display a summary table with the execution times of each algorithm for all test cases.

## Notes:

* Ensure sufficient system memory when testing large range datasets, as Counting Sort and Pigeonhole Sort may require large auxiliary arrays.
* The program can be modified to change the size of datasets or the range of values in the experiments.
* Stability is preserved in stable Counting Sort and LSD Radix Sort, while non-stable Counting Sort may reorder equal elements.

Authors:

* Ali Ahsan, Hamza Memon
* Course: CS250 - Data Structures and Algorithms, BSDS-2
