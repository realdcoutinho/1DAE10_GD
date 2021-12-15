// IterationsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <math.h>
#include <iomanip>      // std::setprecision
#include <iomanip>      // std::setw


void EvenNumbers() {

    //FOR LOOPS
    int j{ 1 };
    for (int j{ 1 }; j <= 12; ++j)
    {
        int result = j * 2;
        std::cout << "  " << result;
    }

    std::cout << '\n';

    int i{ 1 };
    while ( i <= 12) {
        int result = i * 2;
        ++i;
        std::cout << "  " << result;
    }

    std::cout << '\n';

    int k{ 1 };
    do {
            int result = k * 2;
            ++k;
            std::cout << "  " << result;
    } while (k <= 12);
    
    std::cout << '\n';
    std::cout << '\n';

}

//missing function

void RandomNumbers() {

    int choice{};
    std::cout << "Enter a positive integer value: ";

    while (!(std::cin >> choice && choice > 0)) { // if the input is anything but a int, it will be asked to place a value again

    std::cout << "You have not provided a viable value. Try again: ";
    std::cin.clear();
    std::cin.ignore(123, '\n');

    }




    std::cout << '\n';
    std::cout << "The choice was: " << choice;
    std::cout << '\n';


    int j{1};
    int k = rand();

    for (int k = rand() ; k != choice; ++j) {
        k = rand() ;
        if (k == choice) {
            std::cout << "It took " << j << " number of guesses!";
        }
    }

    std::cout << '\n';
    std::cout << '\n';

}

void Trigonometry() {

    std::cout << "-- Trigonometry --";    
    std::cout << '\n';
    std::cout << std::setw(10) << "Degrees" << std::setw(10) << "Radians" << std::setw(10) << "Cos"<< std::setw(10) << "Sin";
    std::cout << '\n';
    
    int degrees{ 0 };
    float radians{};
    float cosine{};
    float Sin{};
    double pi = 3.14159265359;

    for (int degres{ 0 }; degrees <= 180; degrees += 10) {
        
        radians = (float(degrees) * (pi / 180));
        cosine = cos(radians);
        Sin = sin(radians);
        std::cout << std::setw(10) << std::setprecision(2) << degrees;
        std::cout << std::setw(10) << std::setprecision(2) << std::fixed << radians;
        std::cout << std::setw(10) << std::setprecision(2) << std::fixed << cosine;
        std::cout << std::setw(10) << std::setprecision(2) << std::fixed << Sin;
        std::cout << '\n';
    }

    std::cout << '\n';
    std::cout << '\n';
    std::cout << '\n';
}

void ASCIItable(){

    int letter1{ 97 };

    for (int letter1{ 97 }; letter1 <= 110; ++letter1) {
        std::cout << char(letter1);
        std::cout << std::setw(5) << letter1;
        std::cout << std::setw(5) << char(letter1+12);
        std::cout << std::setw(5) << letter1 +12;
        std::cout << '\n';
    }

    std::cout << '\n';

    /*
    for (int letter2{ 110 }; letter2 <= 122; ++letter2) {
        std::cout << char(letter2);
        std::cout << std::setw(5) << letter2;
        std::cout << '\n';
    }
    std::cout << '\n';
    */
}

int main()
{
    std::cout << "Hello World!\n";

    EvenNumbers();
    //missing function


    RandomNumbers();
    Trigonometry();
    ASCIItable();

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
