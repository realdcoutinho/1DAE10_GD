// ErrorSolving.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

#include <string>

int main()
{
	// 1. Calculate average result of 3 tests
	int total{};
	std::cout << "The 1st test result? ";
	int testResult{};
	std::cin >> testResult;
	total += testResult;

	std::cout << "The 2nd test result? ";
	std::cin >> testResult;
	total += testResult;

	std::cout << "The 3rd test result? ";
	std::cin >> testResult;
	total += testResult;
	std::cout << "Total: " << total << std::endl;

	float average{ total / 3.0f };
	std::cout << "Average result: " << average << std::endl;

	// 2. Generate 3 random numbers in the range [3,6]
	std::cout << "\nRandom numbers in the range [3, 6]\n";
	int a{ 3 };
	int b{ 3 };
	int randNr = rand() % a + b;
	std::cout << randNr << std::endl;
	randNr = rand() % a + b;
	std::cout << randNr << std::endl;
	randNr = rand() % a + b;
	std::cout << randNr << std::endl;

	// 3. Square root function: sqrt
	float floatNr{};
	std::cout << "Enter a floating point value ";
	std::cin >> floatNr;
	double result{};
	result = sqrt(floatNr);
	std::cout << "Square root of this value is " << result << std::endl;

	int intNr{};
	std::cout << "Enter an integer value ";
	std::cin >> intNr;
	result = sqrt(intNr);
	std::cout << "Square root of this value is " << result << std::endl;


	// 4. Print ASCII value of the entered letter
	std::cout << "Enter a letter ";
	char letter{};
	std::cin >> letter;
	while (!((letter >= 'a' && letter <= 'z') || (letter >= 'A' && letter <= 'Z')))
	{
		std::cout << "You have not provided a character. Please provide a character:  ";
		std::cin.clear(); //
		std::cin.ignore(123, '\n');
		std::cin >> letter;
	}
	int ASCII_leter = int(letter);
	std::cout << "ASCII value of this letter is " << ASCII_leter << std::endl;





	// 5. Print letter of the entered ASCII value
	std::cout << "Enter ASCII value of a letter ";
	int ascii{};
	std::cin >> ascii;
	while (!((ascii >= -127 || ascii <= 126)))
	{
		std::cout << "You have not provided an integer. Please provide an integer:  ";
		std::cin.clear(); //
		std::cin.ignore(123, '\n');
	}
	char intToLetter  = int(ascii);
	std::cout << "Letter " << ascii << " corresponds with this ASCII value" << intToLetter << '\n';

	// 6. Wait until user presses ENTER
	std::cout << "\nPush ENTER to quit";
	std::cin.get();

	return 0;
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
