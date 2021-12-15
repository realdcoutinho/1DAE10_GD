// FunctionsBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <chrono>
#include <math.h>
#include <cmath>

void Sum(int a, int b);

void PrintInt(int value, char delimiter=' ');
void PrintChar(char value, char delimiter = ' ');
void PrintFloat(float value, char delimiter = ' ');
void PrintFunctions(char coma, int intValue, char charValue, float floatValue);
void TestPrint();

void Multiply(int a, int b);
void TestMultiply();

void Modulo(int dividend, int divisor);
void TestModulo();

void PrintNumbers(int start, int end);
void TestPrintNumbers();

void CalcElapsedTime(int start, int end);
void TestCalcElapsedTime();

void IsEven(int isEven);
void TestIsEven();

void IsLeapYear(int year);
void TestIsLeapYear();

void GetRand(int startRange, int endRange);
void TestGetIntRand();

void GetRandFloat(float startRange, float endRange);
void TestGetFloatRand();

void GetDistanceFloat(float X1, float Y1, float X2, float Y2);
void TestGetDistanceFloat();

struct Point2f {

    float x, y;
    Point2f(float x, float y) : x(x), y(y) {}

};

void GetDistance(const Point2f& pointOne, const Point2f& pointTwo);
void TestGetDistance();

void PrintMessage(int spaces);
void TestPrintMessage();


int main()
{
    //std::cout << "Hello World!\n";

    //Sum(50, 30);
    //Sum(40, 20);
    //Sum(70, 100);
    
    TestPrint();

    //TestMultiply();
    //TestModulo();
    //TestPrintNumbers();
    //TestCalcElapsedTime();
    //TestIsEven();
    //TestIsLeapYear();
    //TestGetIntRand();
    
    //TestGetFloatRand(); ////////////////////////////////
    
    //TestGetDistanceFloat();

    //TestGetDistance();

    //TestPrintMessage();///////////////////////////////


}

void Sum(int a, int b) 
{
    int result{};
    result = a + b;

    return;

}

void PrintFunctions(char coma, int intValue, char charValue, float floatValue) {
    std::cout << intValue << coma << charValue << coma << floatValue;
}

void PrintInt(int value, char delimiter) 
{ std::cout << value << delimiter; }

void PrintChar(char value, char delimiter) 
{ std::cout << value << delimiter; }

void PrintFloat(float value, char delimiter) 
{ std::cout << value << delimiter; }

void TestPrint() 
{ 
    std::cout << '\n';
    std::cout << "Print Char: ";
    PrintChar('a'); 

    
    std::cout << "Print Int: ";
    PrintInt(20); 


    std::cout << "Print Float: ";
    PrintFloat(20.0f); 


    std::cout << "Print Function: ";
    PrintFunctions(',', 20, 'a', 20.0f);
    std::cout << '\n';

}




void Multiply(int a, int b) {



    int product{};
    product = a * b;

    std::cout << '\n' << product << '\n';
}

void TestMultiply() {
    
    int choice1{};
    int choice2{};

    std::cout << "Intruduce a value for int a: ";
    std::cin >> choice1;
    std::cout << '\n';
    std::cout << "Intruduce a value for int b: ";
    std::cin >> choice2;
    std::cout << '\n';

    Multiply(choice1, choice2);


    std::cout << "Intruduce four more values";
    std::cout << '\n';

    int choice3{};
    int choice4{};
    int choice5{};
    int choice6{};

    std::cout << "Intruduce a value for int: ";
    std::cin >> choice3;
    std::cout << '\n';
    std::cout << "Intruduce a value for int: ";
    std::cin >> choice4;
    std::cout << '\n';
    std::cout << "Intruduce a value for int: ";
    std::cin >> choice5;
    std::cout << '\n';
    std::cout << "Intruduce a value for int: ";
    std::cin >> choice6;
    std::cout << '\n';

    Multiply(choice3 * choice4, choice5 * choice6);
}


void Modulo(int dividend, int divisor) {

    int quotient{};
    int quoDivisor{};
    int mod{};

    quotient = dividend / divisor;

    quoDivisor = quotient * divisor;

    mod = dividend - quoDivisor;

    std::cout << '\n' << dividend << " % " << divisor << " = " << mod << '\n';
    


}

void TestModulo() {

    std::cout << '\n' << '\n';

    int choiceDividend{};
    int choiceDivisor{};

    std::cout << "Intruduce a value for a Dividend: ";
    std::cin >> choiceDividend;
    std::cout << '\n';
    std::cout << "Intruduce a value for a Divisor: ";
    std::cin >> choiceDivisor;
    std::cout << '\n';

    Modulo(choiceDividend, choiceDivisor);

}


void PrintNumbers(int start, int end) {

    std::cout << '\n' << '\n';
    std::cout << "Interval [" << start << ', ' << end << ']' << '\n';

    for (start; start < end; start++) {

        std::cout << ' ' << start;
    }

    std::cout << ' ' << end;

}

void TestPrintNumbers() {

    int choiceStart{};
    int choiceEnd{};

    std::cout << '\n' << '\n';

    std::cout << "Intruduce a value for the start: ";
    std::cin >> choiceStart;
    std::cout << '\n';
    std::cout << "Intruduce a value for the end: ";
    std::cin >> choiceEnd;
    std::cout << '\n';


    PrintNumbers(choiceStart, choiceEnd);
}


void CalcElapsedTime(int start, int end) {



    std::chrono::steady_clock::time_point initialTime{ std::chrono::steady_clock::now() };
    ///////////


    std::cout << '\n' << '\n';
    std::cout << "Interval [" << start << ', ' << end << ']' << '\n';

    for (start; start < end; start++) {

        std::cout << ' ' << start;
    }

    std::cout << ' ' << end;

    ///////////

    std::chrono::steady_clock::time_point finalTime{ std::chrono::steady_clock::now() };


    std::chrono::duration<float, std::milli> elapsedTime{ finalTime - initialTime };

    std::cout << '\n' << '\n';

    std::cout << "This print task took " << elapsedTime.count() << " milliseconds";

}

void TestCalcElapsedTime() {

    int choiceStart{};
    int choiceEnd{};

    std::cout << '\n' << '\n';

    std::cout << "Intruduce a value for the start: ";
    std::cin >> choiceStart;
    std::cout << '\n';
    std::cout << "Intruduce a value for the end: ";
    std::cin >> choiceEnd;
    std::cout << '\n';


    CalcElapsedTime(choiceStart, choiceEnd);
}




void IsEven(int isEven){

    if (isEven % 2 == 0) {
        std::cout << isEven << " is even" << '\n';
    }
    else {
        std::cout << isEven << " is odd" << '\n';
    }
}

void TestIsEven(){

    std::cout << '\n' << "-- Function that checkes weather a number is even -- " << '\n';

    int number1 = rand();
    IsEven(number1);
    int number2 = rand();
    IsEven(number2);
    int number3 = rand();
    IsEven(number3);
    int number4 = rand();
    IsEven(number4);
    int number5 = rand();
    IsEven(number5);

}


void IsLeapYear(int year){

    std::cout << '\n' << '\n';

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                std::cout << '\n' << year << " has 28 days in February" << '\n';
            }
            else {
                std::cout << '\n' << year << " has 29 days in February" << '\n';
            }
        }
        else {
            std::cout << '\n' << year << " has 29 days in February" << '\n';
        }
    }
    else {
        std::cout << '\n' << year << " has 29 days in February" << '\n';
    }
}

void TestIsLeapYear() {

    int yearChoice{};

    std::cout << '\n' << '\n';

    std::cout << "Year? ";
    std::cin >> yearChoice;
    IsLeapYear(yearChoice);


}


void GetRand(int startRange, int endRange) {

    int rand{};

    rand = startRange + (std::rand() % (endRange - startRange + 1));

    std::cout << '\n' << "In [" << startRange << ", " << endRange << "] " << rand << '\n';

}

void TestGetIntRand() {

    std::cout << '\n' << '\n';
    
    std::cout << "-- Function that generates a random number in a given intenger interval --";

    int rand1{ rand() };
    int rand2{ rand() };
    GetRand(rand1, rand2);

    int rand3{ rand() };
    int rand4{ rand() };
    GetRand(rand3, rand4);

    int rand5{ rand() };
    int rand6{ rand() };
    GetRand(rand5, rand6);
}


void GetRandFloat(float startRange, float endRange) {

    float rand{};

    rand = startRange + (std::rand() % int(endRange - startRange + 1));

    std::cout << '\n' << "In [" << startRange << ", " << endRange << "] " << rand << '\n';

}

void TestGetFloatRand() {

    std::cout << '\n' << '\n';

    std::cout << "-- Function that generates a random number in a given float interval --";

    float rand1{ 1.2f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (3.4f - 1.2f))) };
    float rand2{ 1.2f + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (3.4f - 1.2f))) };
    //GetRandFloat(rand1, rand2);

    float rand3{ float(rand()) / (float)RAND_MAX };
    float rand4{ float(rand()) / (float)RAND_MAX };
    GetRandFloat(rand3, rand4);

    float rand5{ float(rand()) / (float)RAND_MAX };
    float rand6{ float(rand()) / (float)RAND_MAX };
    //GetRandFloat(rand5, rand6);

}


void GetDistanceFloat(float X1, float Y1, float X2, float Y2) {

    std::cout << '\n' << '\n';

    float distance{};

    distance = sqrt(((X1 + X2) * (X1 + X2)) + ((Y1 + Y2) * (Y1 + Y2)));


    std::cout << distance;
}

void TestGetDistanceFloat() {

    float X1{ float(rand()) };
    float X2{ float(rand()) };

    float Y1{ float(rand()) };
    float Y2{ float(rand()) };

    std::cout << '\n' << X1;
    std::cout << '\n' << X2;
    std::cout << '\n' << Y1;
    std::cout << '\n' << Y2;

    GetDistanceFloat(X1, Y1, X2, Y2);


}


void GetDistance(const Point2f& pointOne, const Point2f& pointTwo)
{


    
    float distance{ sqrt(((pointOne.x + pointTwo.x) * (pointOne.x + pointTwo.x)) + ((pointOne.y + pointTwo.y) * (pointOne.y + pointTwo.y))) };

    std::cout << distance;
}


void TestGetDistance() {

    Point2f X1Y1(10, 70);
    Point2f X2Y2(50, 100);

    GetDistance(X1Y1, X2Y2);

}

void PrintMessage(int spaces) {

    std::cout << '\n' << '\n';

    std::cout << "-- Function that prints an indented message --" << '\n';

   


}
void TestPrintMessage() {

    int nrSpaces{};
    int indentations{};
    nrSpaces = 4;

    for (indentations; indentations < nrSpaces; indentations) {

        if (indentations == 0) {
            std::cout << "No indentation specified" << '\n';
        }
        else {
            std::cout << indentations << " indentation specified" << '\n';
        }
    }   

    indentations = indentations + 2;
}