// Variables2Basics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include <iostream>
#include <string>


//

void integerRands();
void floatRands();
void typecastingUser();
void typecastingRand();
void fix();
void ExploreStrings();

int main()
{
    int integer{};


    std::cout << "Hello User! I am here to help determinate if a number is odd or even! \n";
    std::cout << "Please enter an integer: ";
    while (!(std::cin >> integer))
    {
        std::cout << "You have not provided an integer. Please provide an integer:  ";
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
    }

    std::cout << "The remainder is: " << integer % 2 << '\n';

    if ((integer % 2) == 0)
        std::cout << integer << " is evenly divisible by 2" << '\n';
    else
        std::cout << integer << " is not evenly divisible by 2" << '\n';

integerRands();
floatRands();
typecastingUser();
typecastingRand();
fix();
ExploreStrings();

}

void integerRands() {

    int v1 = rand() % ((50 - 0 + 1) - 0); // [0-50]
    int v2 = rand() % ((80 -10 + 1) +10); // [10-80]
    int v3 = rand() % ((20 - (-20) + 1)+ (-20)); // [-20 - 20]
    int v4 = rand() % ((2 - (-2) + 1) + (-2)); // [-2 - 2]

    std::cout << "v1 is: " << v1 << '\n';
    std::cout << "v2 is: " << v2 << '\n';
    std::cout << "v3 is: " << v3 << '\n';
    std::cout << "v4 is: " << v4 << '\n';

}

void floatRands() 
{
    float f1 = 5.00f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (10.00f-5.00f)));
    std::cout << "f1 is: " << f1 << '\n';
    float f2 = (-5.00f) + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (5.00f - (-5.00f))));
    std::cout << "f2 is: " << f2 << '\n';
}

void typecastingUser()
{   

    char charchoice{};


    std::cout << "Type a character to discover its ASCII  value: ";
    std::cin >> charchoice;
    while (!((charchoice >= 'a' && charchoice <= 'z') || (charchoice >= 'A' && charchoice <= 'Z')))
    {
        std::cout << "You have not provided a character. Please provide a character:  ";
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
        std::cin >> charchoice;
    }

    std::cout << "Your character is " << charchoice << " and its ASCII value is: " << int(charchoice) << '\n';

}

void typecastingRand()
{
    int randomchar = rand() % ((127 - (-127) + 1) + (-127));

    std::cout << "Your random char is: " << char(randomchar) << '\n';


    //5.44
    //5.45 
    //5.51

    /*
    float valueOne{};
    float valueTwo{};
    float valueThree{};
    */


    float valueOne = 5.44f;
    float valueTwo = 5.45f;
    float valueThree = 5.51f;

    int roundOne = int(round(valueOne));
    int roundTwo = int(round(valueTwo));
    int roundThree = int(round(valueThree));

    int intOne = int(valueOne);
    int intTwo = int(valueTwo);
    int intThree = int(valueThree);

    std::cout << valueOne << ", rounded: " << roundOne << ", int cast: " << intOne << '\n';
    std::cout << valueTwo << ", rounded: " << roundTwo << ", int cast: " << intTwo << '\n';
    std::cout << valueThree << ", rounded: " << roundThree << ", int cast: " << intThree << '\n';


    //HD RATIO
    //1920 X 1080

    float ratio = 1920.0f / 1080.0f;

    std::cout << "The aspect ratio of Full HD (1920 x 1080) is: " << ratio << '\n';

}

void fix() {

    int i{ 10 };
    int j{ ++i };

    std::cout << "i: " << i << ", j: " << j << std::endl;

    int k{ 10 };
    int l{ k++ };
    std::cout << "k: " << k << ", l: " << l << std::endl;
}

void ExploreStrings() {

    //Declaration and initialization

    std::string text;
    text = "This is a text!";

    std::cout << '\n' << text;

    std::cout << '\n' << "Please intruduce any text but do not add spaces: ";
    std::string userText;

    std::cin >> userText;

    std::cout << '\n' << "The user text is: " << userText << '\n';

    //String concatenation

    std::string textConcatenationOne;
    std::string textConcatenationTwo;

    std::cout << "Please provide the first word: ";
    std::cin >> textConcatenationOne;
    std::cout << '\n' << "Awesome!" << '\n';
    std::cout << "Now provide us with your second word: ";
    std::cin >> textConcatenationTwo;
    std::cout << '\n' << "Great job! Here is your result:" << '\n';
    std::cout << "First Word   : " << textConcatenationOne << '\n';
    std::cout << "Second Word  : " << textConcatenationTwo << '\n';
    std::cout << "Concatenation is : " << textConcatenationOne + textConcatenationTwo << '\n' << '\n';

    //Converting numbers to strings

    std::string numbersLog;
    int enteredNr{};

    std::cout << "We will now try to do concatenations with more than just strings" << '\n';
    std::cout << "To begin we will ask you to enter multiple integers." << '\n';
    std::cout << "Let's start!" << '\n';
    std::cout << "Enter and integer: ";
    while (!(std::cin >> enteredNr))
    {
        std::cout << "You have not provided an integer. Please provide an integer:  ";
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
    }
    numbersLog += std::to_string(enteredNr) + " ";

    std::cout << "Enter a new integer: ";
    while (!(std::cin >> enteredNr))
    {
        std::cout << "You have not provided an integer. Please provide an integer:  ";
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
    }
    numbersLog += std::to_string(enteredNr) + " ";

    std::cout << "Enter the last integer: ";
    while (!(std::cin >> enteredNr))
    {
        std::cout << "You have not provided an integer. Please provide an integer:  ";
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
    }
    numbersLog += std::to_string(enteredNr) + " ";

    std::cout << '\n' << numbersLog << '\n';

    //Converting strings to numbers

    std::string intString;
    std::string floatString{ "3.1415f" };
    

    std::cout << '\n' << "You have a string that hold the value 3.1415." << '\n';
    std::cout << "We will need you to intruduce an integer value to multiply it with the previous one." << '\n';
    std::cout << "Please intruduce an integer: ";
    std::cin >> intString;
    
    
    /*while (!(std::cin >> intString))
    {
        std::cout << "You have not provided an integer. Please provide an integer:  ";
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
    }
    std::cout << "Great choice!" << '\n';
    
    
    */
    int userIntChoice = std::stoi(intString);
    float notUserChoice = std::stof(floatString);

    float finalResult = float(userIntChoice) * notUserChoice;

    std::cout << "The result of the multiplication between " << userIntChoice << " and " << notUserChoice << " is equal to: " << finalResult;
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
