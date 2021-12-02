// Variables.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>

int main()
{
    int intVar{};
    char charVar{};
    float floatVar{};
    double doubleVar{};
    bool boolVar{};

    int intVar1{ 42 };
    char charVar1{ 'a' };
    float floatVar1{ 4.2f };
    double doubleVar1{ 5.6666f };
    bool boolVar1{ true };

    intVar1 = 50;
    charVar1 = 'b';
    floatVar1 = 1.9999999999f;
    doubleVar1 = 0.888888f;
    boolVar1 = false;


    std::cout << '\n' << "Your current integer value is:    " << '(' << intVar1 << ')';
    std::cout << '\n' << "Your current char value is :      " << '(' << charVar1 << ')';
    std::cout << '\n' << "Your current boolean value is:    " << '(' << boolVar1 << ')';
    std::cout << '\n' << "Your current float value is:      " << '(' << floatVar1 << ')';
    std::cout << '\n' << "Your current double value is:     " << '(' << doubleVar1 << ')' << '\n';

    int intVar0 = 50;
    char charVar0 = 'b';
    float floatVar0;
    double doubleVar0 = 0.888888f;
    bool boolVar0 = false;
    char dot{ '.' };










    std::cout << '\n' << "Enter a new value for integer: ";
    while (!(std::cin >> intVar0))
    {
        std::cout << "You have not provided an integer. Please provide an integer:  ";
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
    }

    std::cout << '\n' << "You selected the integer " << intVar0 << ". That is a good choice!" << '\n';

    std::cin.clear();
    std::cin.ignore(); //without this, the consule will run over the next command because it already received user input from the integer
    std::cout << "Press ENTER to continue...";
    std::cin.get();




    std::cout << '\n' << "Enter ONLY ONE new value for character: ";
    std::cin >> charVar0;
    while (!((charVar0 >= 'a' && charVar0 <= 'z') || (charVar0 >= 'A' && charVar0 <= 'Z')))
    {
        std::cout << "You have not provided a character. Please provide a character:  ";
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
        std::cin >> charVar0;
    }

    std::cout << '\n' << "You selected the character " << charVar0 << ". That is a good choice!" << '\n';

    std::cin.clear();
    std::cin.ignore();
    std::cout << "Press ENTER to continue...";
    std::cin.get();





    std::cout << '\n' << "Enter a new value for a float: ";
    while (!(std::cin >> floatVar0))
    {
        std::cout << '\n' << "You have not provided an float. Please provide an float:  ";
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
        std::cin >> floatVar0;
        //float(floatVar0);
    }

    std::cout << '\n' << "You selected the float " << (float(floatVar0)) << ". That is a good choice!" << '\n';

    std::cin.clear();
    std::cin.ignore();
    std::cout << "Press ENTER to continue...";
    std::cin.get();

    std::cout << '\n' << "Here are you new values!";
    std::cout << '\n' << "Your current integer value is:    " << '(' << intVar0 << ')';
    std::cout << '\n' << "Your current char value is :      " << '(' << charVar0 << ')';
    std::cout << '\n' << "Your current boolean value is:    " << '(' << boolVar0 << ')';
    std::cout << '\n' << "Your current float value is:      " << '(' << floatVar0 << ')';
    std::cout << '\n' << "Your current double value is:     " << '(' << doubleVar0 << ')' << '\n';

    std::cout << '\n' << "Now we will build expressions using a combination of operatorsand different types of operands." << '\n' << "We will begin by using Integers";

    std::cout << '\n' << "Press ENTER to continue..." << '\n';
    std::cin.get();
    std::cout << '\n' << "Lets Start with Subtraction and Addition. Which one would you like to start with for Your integer?" << '\n';
    std::cout << "Type S for subtraction or A for addition: ";


    //Variables for Subtraction and Addition
    char ChoiceOperation{};
    int choiceAddition{};
    int resultAddition{};
    int choiceSubtraction{ 50 };
    int resultSubtraction{};

    //Variables for Multiplication and Division
    char choiceOperation_02{};
    float choiceMultiplication{};
    float resultMultiplication{};
    float choiceDivision{};
    float resultDivision{};


    std::cin >> ChoiceOperation;

    while (!(ChoiceOperation == 'a' || ChoiceOperation == 'A' || ChoiceOperation == 's' || ChoiceOperation == 'S'))
    {
        std::cout << "You have not provided one of the available options. Please chose another answer:  ";
        std::cin.clear(); //
        std::cin.ignore(10000, '\n');
        std::cin >> ChoiceOperation;
    }

    std::cout << '\n' << "Thanks for your choice!";
    std::cin.ignore(50000, '\n');

    if (ChoiceOperation == 'a' || ChoiceOperation == 'A') {

        std::cout << '\n' << "You have chosen Addition";
        std::cout << '\n' << "Now write an integer to do the operation: ";

        while (!(std::cin >> choiceAddition)) {
            std::cout << "You have not provided an integer. Please provide an integer:  ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        resultAddition = intVar0 + choiceAddition;

        std::cout << '\n' << "The sum of " << intVar0 << " + " << choiceAddition << " is equal to " << resultAddition;

    }

    else if (ChoiceOperation == 's' || ChoiceOperation == 'S') {
        std::cout << '\n' << "You have chosen Subtraction";
        std::cout << '\n' << "Now write an integer to do the operation: ";

        while (!(std::cin >> choiceSubtraction)) {
            std::cout << "You have not provided an integer. Please provide an integer:  ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        resultSubtraction = intVar0 - choiceSubtraction;


        std::cout << '\n' << "The Subtraction of " << intVar0 << " - " << choiceSubtraction << " is equal to " << resultSubtraction;
    }

    std::cin.clear();
    std::cin.ignore();
    std::cout << '\n' << "Press ENTER to continue...";
    std::cin.get();


    std::cout << '\n' << "Congratulationsn on finishing your first expressions";
    std::cout << '\n' << "We will now move on to multiplication and division using the two results obtained earlier";
    std::cout << '\n' << "Type M for multiplication or D for division: ";
    std::cin >> choiceOperation_02;

    while (!(choiceOperation_02 == 'm' || choiceOperation_02 == 'M' || choiceOperation_02 == 'd' || choiceOperation_02 == 'D')) {
        std::cout << "You have not provided one of the available options. Please chose another answer:  ";
        std::cin.clear();
        std::cin.ignore(123, '\n');
    }

    std::cout << '\n' << "Thanks for your choice!";
    std::cin.ignore(50000, '\n');

    if (choiceOperation_02 == 'm' || choiceOperation_02 == 'M') {

        if (ChoiceOperation == 'a' || ChoiceOperation == 'A') {
            std::cout << '\n' << "You have chosen Multiplication";
            std::cout << '\n' << "You will now pick a float value to multiple to the result obtained from your previous Addition";
            std::cout << '\n' << "Write down a float value: ";

            while (!(std::cin >> choiceMultiplication)) {
                std::cout << "You have not provided an float. Please provide an float:  ";
                std::cin.clear();
                std::cin.ignore(123, '\n');
            }



            resultMultiplication = choiceMultiplication * resultAddition;

            std::cout << '\n' << "The Multiplication of " << resultAddition << " times " << choiceMultiplication << " is equal to " << resultMultiplication;
        }
        else if (ChoiceOperation == 's' || ChoiceOperation == 'S') {
            std::cout << '\n' << "You have chosen Multiplication";
            std::cout << '\n' << "You will now pick a float value to multiple to the result obtained from your previous Subtraction";
            std::cout << '\n' << "Write down a float value: ";

            while (!(std::cin >> choiceMultiplication)) {
                std::cout << "You have not provided an float. Please provide an float:  ";
                std::cin.clear();
                std::cin.ignore(123, '\n');
            }

            resultMultiplication = choiceMultiplication * resultSubtraction;

            std::cout << '\n' << "The Multiplication of " << resultSubtraction << " times " << choiceMultiplication << " is equal to " << resultMultiplication;



        }
        else if (choiceOperation_02 == 'd' || choiceOperation_02 == 'D') {

            if (ChoiceOperation == 'a' || ChoiceOperation == 'A') {
                std::cout << '\n' << "You have chosen Division";
                std::cout << '\n' << "You will now pick a float value to divide to the result obtained from your previous addition";
                std::cout << '\n' << "Write down a float value: ";

                while (!(std::cin >> choiceMultiplication)) {
                    std::cout << "You have not provided an float. Please provide an float:  ";
                    std::cin.clear();
                    std::cin.ignore(123, '\n');
                }



                resultMultiplication = choiceMultiplication / resultAddition;

                std::cout << '\n' << "The Division of " << resultAddition << " by " << choiceMultiplication << " is equal to " << resultMultiplication;
            }
            else if (ChoiceOperation == 's' || ChoiceOperation == 'S') {
                std::cout << '\n' << "You have chosen Division";
                std::cout << '\n' << "You will now pick a float value to divine to the result obtained from your previous Subtraction";
                std::cout << '\n' << "Write down a float value: ";

                while (!(std::cin >> choiceDivision)) {
                    std::cout << "You have not provided an float. Please provide an float:  ";
                    std::cin.clear();
                    std::cin.ignore(123, '\n');
                }

                resultDivision = choiceDivision / resultSubtraction;

                std::cout << '\n' << "The Division of " << resultSubtraction << " by " << choiceDivision << " is equal to " << resultDivision;
            }
        }
    }
    std::cout << '\n' << "Congratulations for having completed all the exercises!";

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
