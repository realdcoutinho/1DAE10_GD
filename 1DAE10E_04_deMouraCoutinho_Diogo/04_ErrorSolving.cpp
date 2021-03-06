#include <iostream>
#include <ctime>
#include <string> 

#pragma region Function declarations

// Function declarations
void DetermineSkill();
void GetColorCodes();
void Wait();

#pragma endregion Function declarations


int main()
{
	std::cout << "== ErrorSolving - deMouraCoutinho, Diogo - 1DAE10E ==\n";
	// rand seed
	srand(unsigned int(time(nullptr)));

	DetermineSkill();
	GetColorCodes();
	Wait();
}

#pragma region Function definitions
// Function definitions
void GetColorCodes()
{
	std::cout << "\n-- GetColorCodes function --\n";

	std::string menu{ "\nMake your choice\n1.Magenta\n2.Yellow\n3.Cyan\n?" };
	bool quit{ false };
	int choice{};
	std::cout << menu;
	std::cin >> choice;
	switch (choice)
	{
	case 1:
		std::cout << "Magenta 0xFF00FF\n";
		break;
	case 2:
		std::cout << "Yellow 0xFFFF00\n";
	case 3:
		std::cout << "Cyan 0x00FFFF\n";
		break;
	default:
		std::cout << "Wrong choice\n";
		break;
	}

	std::cin.ignore();
}


void DetermineSkill()
{
	std::cout << "\n-- DetermineSkill function --\n";

	int years{};
	std::cout << "Your years of experience ? ";
	std::cin >> years;
	std::string level{};
	if (years < 5)
	{
		level = "Junior level";
	}
	if (years < 10)
	{
		level = "Intermediate level";
	}
	else
	{
		level = "Senior level";
	}
	std::cout << level << std::endl;

	std::cin.ignore();
}

void Wait()
{
	std::cout << "Press ENTER to quit";
	std::cin.get();
}