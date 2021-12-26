// BasicAlgorithms.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;


int Count(int* pArray, int size, int chosenInt);
void PrintArray(int* pArray, int size);
void TestCount();

int MinElement(int* pArray, int size);
int MaxElement(int* pArray, int size);
void SortArray(int* pArray, int size);
void TestMinMax();

void Swap(int* pArray, int size, int idx1, int idx2);
void TestSwap();

void Shuffle(int* pArray, int size, int idx1, int idx2);
void GetRandom(int* idx1, int* idx2, int size);
void TestShuffle();

void BubbleSort(int* pArray, int size);
void TestBubbleSort();



const int g_ArrayOneSize{10};
int g_arrayOne[g_ArrayOneSize]{ 7, -3, 9, -8, 3, 0, -7, 1, 9, 8 };
const int g_ArrayTwoSize{ 12 };
int g_arrayTwo[g_ArrayTwoSize]{ -4, -1, 2, 0, -3, 0, 2, 0, 0, -5, -1, 1 };





int main()
{
    //TestCount();
    //TestMinMax();
    //TestSwap();
    TestShuffle();
    //TestBubbleSort();
}


int Count(int* pArray, int size, int chosenInt)
{
    PrintArray(pArray, size);

    int equal{};
    for (int i{ 0 }; i < size; ++i) 
    {
        if (pArray[i] == chosenInt) {
            equal += 1;
        }
            
    }
    return equal;
}
void PrintArray(int* pArray, int size) {

    for (int i{ 0 }; i < size; ++i) std::cout << pArray[i] << ' ';
    std::cout << '\n';
}
void TestCount() 
{
    std::cout << "-- Test Count -- " << '\n';
    std::cout << "Provide a value to be compared with the array: ";
    int givenCount{};
    while (!(std::cin >> givenCount)) { // if the input is anything but a int, it will be asked to place a value again

        std::cout << "You have not prvided a viable value. Try again: ";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }
    int nrEqual{ Count(g_arrayOne, g_ArrayOneSize, givenCount) };
    std::cout << givenCount << " occurs " << nrEqual << " in this array!" << '\n';

    givenCount = 0;
    std::cout << '\n';
    std::cout << '\n';
    std::cout << "Provide another value to be compared with the next array: ";
    while (!(std::cin >> givenCount)) { // if the input is anything but a int, it will be asked to place a value again

        std::cout << "You have not prvided a viable value. Try again: ";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }
    nrEqual = Count(g_arrayTwo, g_ArrayTwoSize, givenCount);
    std::cout << givenCount << " occurs " << nrEqual << " in this array!" << '\n';

}


void SortArray(int* pArray, int size) 
{
    PrintArray(pArray, size);
    sort(pArray, pArray + size);
    PrintArray(pArray, size);
}
int MinElement(int* pArray, int size)
{
    int min{ pArray[0] };
    return min;
}
int MaxElement(int* pArray, int size) 
{
    int max{ pArray[size - 1] };
    return max;
}
void TestMinMax()
{
    int arrOne[] = { 7, -3, 9, -8, 3, 0, -7, 1, 9, 8 };
    int n = sizeof(arrOne) / sizeof(arrOne[0]);

    SortArray(arrOne, n);
    int min{ MinElement(arrOne, n) };
    int max{ MaxElement(arrOne, n) };
    
    std::cout << '\n';
    std::cout << "The smallest element of the Array is: " << min << '\n';
    std::cout << "The highest element of the Array is: " << max << '\n';
    std::cout << '\n';

    int arrTwo[] = { 4, -1, 2, 0, -3, 0, 2, 0, 0, -5, -1, 1 };
    n = sizeof(arrTwo) / sizeof(arrTwo[0]);

    SortArray(arrTwo, n);
    min = MinElement(arrTwo, n);
    max = MaxElement(arrTwo, n);

    std::cout << '\n';
    std::cout << "The smallest element of the Array is: " << min << '\n';
    std::cout << "The highest element of the Array is: " << max << '\n';

}


void Swap(int* pArray, int size, int idx1, int idx2)
{
    swap(pArray[idx1], pArray[idx2]);
}
void TestSwap() 
{
    std::cout << "-- Test Swapping Function -- " << '\n';
    int arrOne[] = { 7, -3, 9, -8, 3, 0, -7, 1, 9, 8 };
    int n = sizeof(arrOne) / sizeof(arrOne[0]);

    std::cout << "Before Swapping: " << '\n';
    PrintArray(arrOne, n);

    Swap(arrOne, n, 0, n - 1);

    std::cout << "After Swapping: " << '\n';
    PrintArray(arrOne, n);

    std::cout << '\n';

    int arrTwo[] = { 4, -14, 2, 0, -3, 0, 2, 0, 0, -5, -1, 1 };
    n = sizeof(arrTwo) / sizeof(arrTwo[0]);

    std::cout << "Before Swapping: " << '\n';
    PrintArray(arrTwo, n);

    Swap(arrTwo, n, 1, n - 2);

    std::cout << "After Swapping: " << '\n';
    PrintArray(arrTwo, n);

}


void Shuffle(int* pArray, int size, int idx1, int idx2) {


    GetRandom(&idx1, &idx2, size);
    if (idx1 == idx2) {
        GetRandom(&idx1, &idx2, size);
    }
    Swap(pArray, size, idx1, idx2);

}
void GetRandom(int* idx1, int* idx2, int size)
{
    *idx1 = (std::rand() % (size - 0 + 1));
    *idx2 = (std::rand() % (size - 0 + 1)); 
}
void TestShuffle()
{
    std::cout << "-- Shuffle -- " << '\n';
    int arrOne[] = { 7, -3, 9, -8, 3, 0, -7, 1, 9, 8 };
    int n = sizeof(arrOne) / sizeof(arrOne[0]);
    std::cout << "Before Shuffeling: " << '\n';
    PrintArray(arrOne, n);
    
    int givenShuffle{};
    std::cout << "How many times would you like the array to be shuffled? ";
    while (!(std::cin >> givenShuffle)) { // if the input is anything but a int, it will be asked to place a value again

        std::cout << "You have not prvided a viable value. Try again: ";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }
    for (int c{0}; c < givenShuffle; c++) {
        Shuffle(arrOne, n -1, 3, 4);
    }
    std::cout << "The array was shuffled " << givenShuffle << " times" << '\n';
    std::cout << "After Shuffeling: " << '\n';
    PrintArray(arrOne, n);
}


void BubbleSort(int* pArray, int size)
{
    int i{};
    int j{};

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (pArray[j] > pArray[j + 1])
                swap(pArray[j], pArray[j + 1]);
        }
    }

}
void TestBubbleSort()
{
    std::cout << "-- Bubble Sort -- " << '\n';
    int arrOne[] = { 7, -3, 9, -8, 3, 0, -7, 1, 9, 8 };
    int n = sizeof(arrOne) / sizeof(arrOne[0]);
    std::cout << "Before Shuffeling: " << '\n';
    PrintArray(arrOne, n);



    BubbleSort(arrOne, n);
    cout << "Sorted array: \n";
    PrintArray(arrOne, n);

}