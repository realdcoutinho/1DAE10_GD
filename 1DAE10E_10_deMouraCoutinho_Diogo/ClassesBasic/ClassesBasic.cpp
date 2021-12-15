// ClassesBasic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Square.h"
#include "Time.h"
#include <iostream>

void DoSquareTests(Square* square);
void TestSquare(Square* pSquare);

void DoTimeTest(Time* pTime);

int main()
{
    std::cout << "Hello World!\n";

    
    Square* pSq3{ new Square{} };
    Square* pSq4{ new Square{} };
    DoSquareTests(pSq3);
    DoSquareTests(pSq4);
    Time* pTime1{ new Time{12, 30, 47} };
    Time* pTime2{ new Time{17, 23} };
    Time* pTime3{ new Time{9875} };

    DoTimeTest(pTime1);
    DoTimeTest(pTime2);
    DoTimeTest(pTime3);


}

void DoSquareTests(Square* square)
{
    float left{ 45 };
    float size{ 25 };
    float bottom{ 40 };

    square->Print();
    square->SetSize(size);
    square->Translate(5, 10);
    square->Print();

    TestSquare(square);

    delete square;
    square = nullptr;
}

void TestSquare(Square* pSquare)
{
    int pointerValue = int(pSquare);
    std::cout << "Test pSquare Function: " << pointerValue << '\n';
    pSquare->Translate(1000, 1000);
    pSquare->Print();
}

void DoTimeTest(Time* pTime)
{
    std::cout << pTime->GetHours() << '\n';
    std::cout << pTime->GetMinutes() << '\n';
    std::cout << pTime->GetSeconds() << '\n';
    pTime->Print();

    pTime->AddHours(1);
    pTime->AddMinutes(12);
    pTime->Print();
    std::cout << pTime->GetSeconds() << '\n';
    std::cout << pTime->GetTotalSeconds() << '\n';

    delete pTime;
    pTime = nullptr;
    std::cout << "The end" << '\n' << '\n';
}