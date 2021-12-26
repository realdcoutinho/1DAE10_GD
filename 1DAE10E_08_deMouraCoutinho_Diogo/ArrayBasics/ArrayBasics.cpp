// ArrayBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "structs.h"

void AccessArrays(int* pArray, int size);
void ExceedArray(int* pArray, int size);
void SizeArray();
void Location(int* pArrayInts, Point2f* pArrayPoint2f, int size);
void DefineArrays();
void PrintElements(int* pNumbers, int size);
void PrintElements(int* pNumbers, int startIdx, int endIdx);


void TwoDArrays();
int GetIndex(int rowIndex, int columnIndex, int nrOfColumns);
void Print2DElements(int* pNumbers, int rows, int columns);



/*
void values2D();
int GetIndex(int rowId, int colId, int cols);
*/





int main()
{
    std::cout << "Hello World!\n";
    //DefineArrays();
    TwoDArrays();
}

void AccessArrays(int* pArray, int size) 
{
    std::cout << "-- Accesing elements --" << '\n';
    std::cout << "First Element: " << pArray[0] << '\n';
    std::cout << "Last Element:  " << pArray[size - 1] << '\n';
    std::cout << '\n';
    std::cout << "Iterating over the elements" << '\n';
    for (int i{ 0 }; i < size; ++i) std::cout << pArray[i] << ' ';
    std::cout << '\n';
}

void ExceedArray(int* pArray, int size)
{
    size += 5;
    std::cout << '\n';
    std::cout << "Iterating over the elements" << '\n';
    for (int i{ 0 }; i < size; ++i) std::cout << pArray[i] << ' ';
    std::cout << '\n';

    std::cout << "Iterating over the elements" << '\n';
    for (int i{ 0 }; i < size; ++i) std::cout << pArray[i] + 1 << ' ';
    std::cout << '\n';

}

void SizeArray()
{
    int numbers2Arr[]{ 10, 20, 30, 40, 50 };

    int nrOfBytes = sizeof(numbers2Arr);
    int sizeOneElements = sizeof(numbers2Arr[0]);
    int nrOfElements = nrOfBytes / sizeOneElements;

    std::cout << '\n';
    std::cout << "-- Size of Arrays --" << '\n';
    std::cout << "2nd Array" << '\n';

    std::cout << "nr of bytes:         " << nrOfBytes << '\n';
    std::cout << "size of one element: " << sizeOneElements << '\n';
    std::cout << "size of one element: " << sizeOneElements << '\n';
    std::cout << "nr of elements:      " << nrOfElements << '\n';

    for (int i{ 0 }; i < nrOfElements; ++i) std::cout << numbers2Arr[i] + 1 << ' ';
    std::cout << '\n';
}

void Location(int* pArrayInts, Point2f* pArrayPoint2f, int size)
{
    std::cout << '\n';
    std::cout << "-- The elements occupy consecutive memory location --" << '\n';
    std::cout << "Array of int types" << '\n';

    for (int i{ 0 }; i < size; ++i) std::cout << "Array of element with index " << i << " is " << &pArrayInts[i] << '\n';

    std::cout << '\n';
    std::cout << "Array of Point2f types" << '\n';
    for (int i{ 0 }; i < size; ++i) std::cout << "Array of element with index " << i << " is " << &pArrayPoint2f[i] << '\n';
}

void PrintElements(int* pNumbers, int size)
{
    for (int i{ 0 }; i < size; ++i) std::cout << pNumbers[i] << ' ';
    std::cout << '\n';
}

void PrintElements(int* pNumbers, int startIdx, int endIdx)
{
    for (startIdx; startIdx < endIdx; ++startIdx) std::cout << pNumbers[startIdx] << ' ';
    std::cout << '\n';
}

void DefineArrays()
{
    const int size{ 5 };
    int numbers1Arr[size]{};
    int numbers2Arr[]{ 10, 20, 30, 40, 50 };
    int numbers3Arr[size]{ 5, 10, 15 };
    Point2f pointsArr[size]{};

    AccessArrays(numbers3Arr, size);
    ExceedArray(numbers3Arr, size);
    SizeArray();
    Location(numbers2Arr, pointsArr, size);
    std::cout << '\n';
    std::cout << "-- Passing an array to a function, PrintElements --" << '\n';
    std::cout << "Print all elements" << '\n';
    PrintElements(numbers1Arr, size);
    PrintElements(numbers2Arr, size);
    PrintElements(numbers3Arr, size);
    std::cout << '\n';
    std::cout << "-- Print a range of elements --" << '\n';
    PrintElements(numbers3Arr, 2, size);
    std::cout << '\n';

    //TwoDArrays();
    //values2D();

}





void TwoDArrays()
{
    std::cout << "-- 2D arrays --" << std::endl;
    const int rows{ 3 };
    const int columns{ 4 };
    const int gridArraySize{ rows * columns };
    int gridArray[gridArraySize]{};
    for (int row{ 0 }; row < rows; row++)
    {
        for (int column{ 0 }; column < columns; column++)
        {
            int index{ GetIndex(row, column, columns) };
            gridArray[index] = (row + 1) * 10 + column + 1;
        }

    }

    Print2DElements(gridArray, rows, columns);

}

void Print2DElements(int* pNumbers, int rows, int columns)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            int index{ GetIndex(row, column, columns) };
            std::cout << pNumbers[index] << " ";
        }
        std::cout << std::endl;
    }
}

int GetIndex(int rowIndex, int columnIndex, int nrOfColumns)
{
    return rowIndex * nrOfColumns + columnIndex;
}










// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
