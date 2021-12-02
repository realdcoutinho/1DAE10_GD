// Variables3Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <bitset>
#include <iostream>


// deMouraCoutinho, Diogo 1DAE10E

int main()
{

	//Sizeof operator------------------------


	int integerSize = 34;
	float floatSize = 12.1231f;
	double doubleSize = 56.67;
	bool boolSize = true;
	char charSize = 'd';

	int integerSize_result = sizeof(integerSize);
	int floatSize_result = sizeof(floatSize);
	int doubleSize_result = sizeof(doubleSize);
	int boolSize_result = sizeof(boolSize);
	int charSize_result = sizeof(charSize);

	std::cout << "The size of " << integerSize << " in bytes is " << integerSize_result << '\n';
	std::cout << "The size of " << floatSize << " in bytes is " << floatSize_result << '\n';
	std::cout << "The size of " << doubleSize << " in bytes is " << doubleSize_result << '\n';
	std::cout << "The size of " << boolSize << " in bytes is " << boolSize_result << '\n';
	std::cout << "The size of " << charSize << " in bytes is " << charSize_result << '\n';


	//Hexadecimal and binary number presentation 

	std::cout << '\n';

	int decimal = 10;
	int hexadecimal = 0xA;
	int binary = 0b00001010;

	std::cout << "The value 10 in decimal is " << decimal << '\n';
	std::cout << "The value 10 in hexadecimal is " << hexadecimal << '\n';
	std::cout << "The value 10 in binary is " << binary << '\n';




	//-----\\
	//Range of – signed vs unsigned types
	//-----\\

	std::cout << '\n';

	//signed variables
	int maximumSign = 2147483647;
	int minimumSign = -2147483648;

	//signed overflow
	int maximumSign_overflow = maximumSign + 1;
	int minimumSign_overflow = minimumSign - 1;

	std::cout << "The value of signed " << maximumSign << " plus 1 is equal to " << maximumSign_overflow << '\n';
	std::cout << "The value of signed " << minimumSign << " minus 1 is equal to " << minimumSign_overflow << '\n';


	//unsigned variables
	unsigned int maximumUnsign = 4294967295;
	unsigned int minumumUnsign = 0;

	//unsigned overflow
	unsigned int maximumUnsigned_overflow = maximumUnsign + 1;
	unsigned int minimumUnsigned_overflow = minumumUnsign - 1;

	std::cout << "The value of unsigned " << maximumUnsign << " plus 1 is equal to " << maximumUnsigned_overflow << '\n';
	std::cout << "The value of unsigned " << minumumUnsign << " minus 1 is equal to " << minimumUnsigned_overflow << '\n';


	//-----\\
	Binary bitwise | and & operator
	//-----\\

	std::cout << '\n';

	int value1 = 0b00000011; // 3
	int value2 = 0b00000101; // 5
	
	int valueAND = value1 & value2;
	int valueOR = value1 | value2;


	std::cout << "The value of " << value1 << " AND " << value2 << " is equal to " << valueAND << '\n'; // YES, the same as the calculator
	std::cout << "The value of " << value1 << " OR " << value2 << " is equal to " << valueOR << '\n'; // YES, the same as the calculator



	//------\\Applied: Bitwise &: is a bit 0 or 1? 

	std::cout << '\n';

	/*
	int userInput = { };

	std::cout << '\n' << "Enter a value for integer: ";
	while (!(std::cin >> userInput))
	{
		std::cout << "You have not provided an integer. Please provide an integer:  ";
		std::cin.clear(); //
		std::cin.ignore(123, '\n');
	}

	std::cout << '\n' << "You selected the integer " << userInput << '\n';

	std::cin.clear();
	std::cin.ignore(); //without this, the consule will run over the next command because it already received user input from the integer

	*/



	//-----\\ Applied: Bitwise |: set a bit in a number

	//continue later

	std::bitset<4> x{ 0b1100 };

	std::cout << x << '\n';
	std::cout << (x >> 1) << '\n'; // shift right by 1, yielding 0110
	std::cout << (x << 1) << '\n'; // shift left by 1, yielding 1000


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
