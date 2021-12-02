// FunctionsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <math.h>

void CalcCosSin(float aCos, float aSin);
void TestCalCosSin();

int main()
{
    std::cout << "Hello World!\n";
    TestCalCosSin();
}

void CalcCosSin(float aCos, float aSin) {

    std::cout << "Angle Cos : " << aCos << '\n';
    std::cout << "Angle Sin : " << aSin << '\n';
}

void TestCalCosSin() {

    for (float loop{ 0 }; loop < 10; loop++) {

        float angle{ float(0 + (std::rand() % (360 - 0 + 1))) };

        std::cout << '\n' << "Degrees: " << angle << '\n';
        angle = (M_PI / 180) * angle;
        std::cout << "Radians: " << angle << '\n';

        float angleCos{ cos(angle) };
        float angleSin{ sin(angle) };

        std::cout << '\n';
        CalcCosSin(angleCos, angleSin);
        std::cout << '\n';
    }
}


//GetRandFloat(rand1, rand2);
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
