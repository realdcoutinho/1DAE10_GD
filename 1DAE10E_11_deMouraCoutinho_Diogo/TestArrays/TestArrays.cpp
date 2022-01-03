// TestArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "Time.h"

const int g_AmountOfTime{ 4 };
Time* g_pTimer[g_AmountOfTime]{};

void InitializeTime();
void ChangeTime();
void DeleteTimer();
void PrintTime();

int main()
{
    std::cout << "Hello World!\n";
    InitializeTime();
    ChangeTime();
    PrintTime(); 
    DeleteTimer();
}

void InitializeTime()
{

    for (int i{}; i < g_AmountOfTime; ++i) {
 
        g_pTimer[i] = new Time{ unsigned int(rand()) };
    }

}

void ChangeTime()
{
    for (int i{ 0 }; i < g_AmountOfTime; ++i)
    {
        g_pTimer[i]->AddSeconds(abs(rand()));
    }
}

void DeleteTimer()
{
    for (int i{ 0 }; i < g_AmountOfTime; ++i)
    {
        delete g_pTimer[i];
        g_pTimer[i] = nullptr;
    }
}

void PrintTime()
{
    for (int i{ 0 }; i < g_AmountOfTime; ++i)
    {
        g_pTimer[i]->Print();
    }
}