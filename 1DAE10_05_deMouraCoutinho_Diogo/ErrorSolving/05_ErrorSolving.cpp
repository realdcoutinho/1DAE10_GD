// Name, firstname
// 1DAExx

// Include directives
#include "pch.h"
#include <iostream>
#include <ctime>
#include <string> 

#pragma region Function declarations
// Function declarations
void ShowMultiplyTable( );
void GuessNumber( );
void GetNumber( );

void Wait( );
#pragma endregion Function declarations

int main( )
{
	std::cout << "== ErrorSolving - deMouraCoutinho, Diogo - 1DAE10E ==\n";
	// rand seed
	srand( unsigned int( time( nullptr ) ) );

	ShowMultiplyTable( );
	GuessNumber( );
	GetNumber( );
	Wait( );
}

#pragma region Function definitions
// Function definitions



void ShowMultiplyTable( )
{
	std::cout << "\n-- ShowMultiplyTable function --\n";

	int x{ 5 };
	int y{ 0 };
	int result{};
	std::cout << "Multiply " << x << " table\n";
	for ( int y{ 0 }; y <= 10; ++y )
	{
		result = x * y;
		std::cout << x << " x " << y << " = " << result << std::endl;
	}

}

void GuessNumber( )
{
	std::cout << "\n-- GuessNumber function --\n";

	int randNr{ rand( ) % 10 + 1 };
	int guess{};
	int trials{ 1 };


	std::cout << randNr;

	std::cout << "Number in [0, 10] ? ";
	while (!(std::cin >> guess && guess >= 0 && guess <= 10)) { // if the input is anything but a int, it will be asked to place a value again

		std::cout << "You have not provided an int in the given interval." << '\n';
		std::cout << "Provide a new value: ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
		trials++;

		std::cout << randNr;
	}


	while (!(guess == randNr)) {
		std::cout << "You have not guess the number right." << '\n';
		std::cout << "try again: " << '\n';
		std::cin.clear();
		std::cin.ignore(123, '\n');
		trials++;

		std::cout << randNr;
	}

	std::cout << "You entered the right number "<< randNr << " after " << trials << " guesses!\n";
	std::cin.ignore( );
}


void GetNumber( )
{
	std::cout << "\n-- GetNumber function --\n";

	const int min{ 5 };
	const int max{ 10 };
	int nr{};
	std::string questionMsg{ "Enter a number in the interval [" +
		std::to_string( min ) + ", " + std::to_string( max ) + "] " };
	std::string errorMsg{ "Sorry, but this is not a correct number\n" };
	bool wrongInput{ false };
	do
	{
		if ( wrongInput = true )
		{
			std::cout << errorMsg;
		}
		std::cout << questionMsg;
		std::cin >> nr;

		wrongInput = true;
	}
	while ( nr < min || nr > max );
	std::cout << "You entered the number " << nr << '\n';

	std::cin.ignore( );
}

void Wait( )
{
	std::cout << "Press ENTER to quit";
	std::cin.get( );
}
#pragma endregion Function definitions
