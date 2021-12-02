#include "pch.h"


#define _USE_MATH_DEFINES
#include <cmath>

//include <math.h>

#include <iostream>
#include <time.h>

// deMouraCoutinho, Diogo - 1DAE10E

void TestOneParFunctions();
void TestTwoParFunctions();

int main( )
{

	// 1. Show my data
	std::cout << "My name is name, firstname" << std::endl;
	std::cout << "I am in group 1DAExx" << std::endl << std::endl;

	// 2. Show my student history
	std::cout << "Name of my high school: " << std::endl;
	std::cout << "In the last year I had ... hours math a week" << std::endl << std::endl;

	TestOneParFunctions();
	TestTwoParFunctions();

	// Wait
	std::cout << "Push ENTER to quit\n";
	std::cin.get( );



	return 0;
}

void TestOneParFunctions()
{
	double PI{ 3.1415926535f };

	double angleTwo{ PI / 4 };
	double angleThree{ 2 * PI / 4 };
	double angleFour{ 3 * PI / 4 };
	double angleFive{ PI };

	double angle{ 0 };
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "  Cos: " << cos(angle) << std::endl;

	angle += PI / 4;
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "  Cos: " << cos(angle) << std::endl;

	angle += PI / 4;
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "  Cos: " << cos(angle) << std::endl;

	angle += PI / 4;
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "  Cos: " << cos(angle) << std::endl;

	angle += PI / 4;
	std::cout << "Angle: " << angle << std::endl;
	std::cout << "  Cos: " << cos(angle) << std::endl;

	std::cout << "Angle: " << angle << std::endl;
	std::cout << "  Cos: " << cos(angle*2) << std::endl;

}

void TestTwoParFunctions() {

	double sideOne = pow(3, 2);
	double sideTwo = pow(4, 2);

	double hypotenuse = sqrt(sideOne + sideTwo);
	std::cout << "hypotenuse: " << hypotenuse << std::endl;

}
