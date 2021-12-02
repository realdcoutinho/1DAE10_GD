// FlowControlBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <limits>
#include "structs.h"




void PrintTruthTable()
{
    //Bool varibales
    bool boolTrue   { true };
    bool boolFalse  { false };

    std::cout << "Each value for the bool variables bellow!" << '\n';
    std::cout << "boolTrue value is:  " << std::boolalpha << boolTrue << '\n';
    std::cout << "boolFalse value is: " << std::boolalpha << boolFalse << '\n';
    std::cout << "boolTrue value is:  " << std::noboolalpha << boolTrue << '\n';
    std::cout << "boolFalse value is: " << std::noboolalpha << boolFalse << '\n' << '\n';

    std::cout << "-- Print Truth Table --" << '\n';
    std::cout << "Logical binary AND-operator (&&) " << '\n';
    std::cout << "True && True value is:  " << std::boolalpha << (boolTrue && boolTrue) << '\n';
    std::cout << "True && False value is:  " << std::boolalpha << (boolTrue && boolFalse) << '\n';
    std::cout << "False && True value is:  " << std::boolalpha << (boolFalse && boolTrue) << '\n';
    std::cout << "False && False value is:  " << std::boolalpha << (boolFalse && boolFalse) << '\n' << '\n';

    std::cout << "Logical binary OR-operator (||) " << '\n';
    std::cout << "True || True value is:  " << std::boolalpha << (boolTrue || boolTrue) << '\n';
    std::cout << "True || False value is:  " << std::boolalpha << (boolTrue || boolFalse) << '\n';
    std::cout << "False || True value is:  " << std::boolalpha << (boolFalse || boolTrue) << '\n';
    std::cout << "False || False value is:  " << std::boolalpha << (boolFalse || boolFalse) << '\n' << '\n';

    std::cout << "Logical binary NOT-operator (!) " << '\n';
    std::cout << "!True value is:  " << std::boolalpha << !boolTrue << '\n';
    std::cout << "!False value is: " << std::boolalpha << !boolFalse << '\n' << '\n';

    std::cout << '\n' << '\n';

}

void CompareTwoNumbers() {

    int intRandOne = rand() % 10;
    int intRandTwo = rand() % 10;

    std::cout << "First number is: " << intRandOne << '\n';
    std::cout << "Second number is: " << intRandTwo << '\n' << '\n';

    int largerThan{ intRandOne > intRandTwo };


    switch (largerThan) 
    {
    case (true):
        std::cout << "First number is larger than the second number" << '\n';
        break;

    case (false):
        std::cout << "Second number is larger than the first number" << '\n';
        break;
    }

    std::cout << '\n' << '\n' << '\n';

}

void CalculatePrice() {

    /*
    int lessThan20 = rand() % 19;
    int interval20To49 = rand() % 30 + 19;
    int interval50To100 = rand() % 50 + 50;
    int interval100toInfinity = rand() % std::numeric_limits<int>::max() + 101 << '\n' << '\n';
    */

    int numberPens{rand()};

    if (numberPens < 20) {
        std::cout << "Nr of ballpoints: " << numberPens << '\n';
        std::cout << "Total Price is:   " << numberPens * 4.0f << '\n';
    }
    else if ( 20 <= numberPens && numberPens > 50){
        std::cout << "Nr of ballpoints: " << numberPens << '\n';
        std::cout << "Total Price is:   " << numberPens * 3.5f << '\n';
    }
    else if (50 <= numberPens && numberPens >= 100) {
        std::cout << "Nr of ballpoints: " << numberPens << '\n';
        std::cout << "Total Price is:   " << numberPens * 3.25f << '\n';
    }
    else if (101 < numberPens) {
        std::cout << "Nr of ballpoints: " << numberPens << '\n';
        std::cout << "Total Price is:   " << numberPens * 3.1f << '\n';
    }

    std::cout << '\n' << '\n' << '\n';

}

void ConvertDayNumber() {

    int weekDay{};

    std::cout << "Please intruduce a number between 1 and 7: ";
    std::cin >> weekDay;
    while (!(weekDay >= 1 && weekDay <= 7))
    {
        std::cout << "Please intruduce a number in within the requested interval: ";
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
        std::cin >> weekDay;
    }
    std::cout << "Your number is " << weekDay << '\n';

    /*
    switch (weekDay) {
        case(6):
            std::cout << "You chose Weekend" << '\n';
            break;
        case(7):
            std::cout << "You chose Weekend" << '\n';
            break;
        default:
            std::cout << "You did not chose weekend" << '\n';
            break;
    }
    */

    switch (weekDay){
        case(1):
            std::cout << "You chose Monday" << '\n';
            std::cout << "You chose start of the week" << '\n';

            break;
        case(2):
            std::cout << "You chose Tuesday" << '\n';
            std::cout << "You chose middle of the week" << '\n';
            break;
        case(3):
            std::cout << "You chose Wednesday" << '\n';
            std::cout << "You chose middle of the week" << '\n';
            break;
        case(4):
            std::cout << "You chose Thrusday" << '\n';
            std::cout << "You chose middle of the week" << '\n';
            break;
        case(5):
            std::cout << "You chose Friday" << '\n';
            std::cout << "You chose nearly the weekend" << '\n';
            break;
        case(6):
            std::cout << "You chose Saturday" << '\n';
            std::cout << "You chose the weekend" << '\n';

            break;
        case(7):
            std::cout << "You chose Sunday" << '\n';
            std::cout << "You chose the weekend" << '\n';
            break;
    }

    std::cout << '\n' << '\n' << '\n';
}

void CheckLeapYear() {

    int yearChoice{};

    std::cout << "Please provide a year: ";
    while (!(std::cin >> yearChoice))
    {
        std::cout << "You have not provided valid year. Please provide a valid year:  ";
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
    }

    if ((yearChoice % 4) == 0) {

        if ((yearChoice % 100 == 0)) {

            if ((yearChoice % 400 == 0)) {
                std::cout << "1You have chosen: " << yearChoice << '\n';
                std::cout << "You have chosen a leap year" << '\n';
                std::cout << "February has 29 days in " << yearChoice << '\n';
            }
            else {
                std::cout << "2You have chosen: " << yearChoice << '\n';
                std::cout << "You have not chosen a leap year" << '\n';
                std::cout << "February has 28 days in " << yearChoice << '\n';
            }

        }
        else {
            std::cout << "3You have chosen: " << yearChoice << '\n';
            std::cout << "You have chosen a leap year" << '\n';
            std::cout << "February has 29 days in " << yearChoice << '\n';
        }
    }
    else {
        std::cout << "4You have chosen: " << yearChoice << '\n';
        std::cout << "You have not chosen a leap year" << '\n';
        std::cout << "February has 28 days in " << yearChoice << '\n';
    }

    std::cout << '\n' << '\n' << '\n';

}

void ConvertSeconds() {

    int seconds{};
    int finalDays{};

    int hoursInSeconds{};
    int finalHours{};

    int minutesInSeconds{};
    int finalMinutes{};

    int lastSeconds{};


    std::cout << "--Convert seconds into days, hours, minutes and remaing seconds--" << '\n';
    std::cout << "Please enter your value for seconds: ";
    while (!(std::cin >> seconds)) {
        {
            std::cout << "You have not provided valid number of seconds. Please provide a valid answer:  ";
            std::cin.clear(); //
            std::cin.ignore(123, '\n');
        }
    }

    if (seconds >= 86400) {

        finalDays = int(seconds / 86400);
        std::cout << finalDays << " Days" << '\n';

        hoursInSeconds = seconds - finalDays * 86400;
        finalHours = int(hoursInSeconds / 1200);
        std::cout << finalHours << " Hours" << '\n';

        minutesInSeconds = hoursInSeconds - finalHours * 1200;
        finalMinutes = int(minutesInSeconds / 60);
        std::cout << finalMinutes << " minutes" << '\n';

        lastSeconds = minutesInSeconds - finalMinutes * 60;
        std::cout << lastSeconds << " seconds" << '\n';


    }
    else if (seconds < 86400) {

        finalDays = int(seconds / 86400);
        std::cout << finalDays << " Days" << '\n';

        hoursInSeconds = seconds - finalDays * 86400;
        finalHours = int(hoursInSeconds / 1200);
        std::cout << finalHours << " Hours" << '\n';

        minutesInSeconds = hoursInSeconds - finalHours * 1200;
        finalMinutes = int(minutesInSeconds / 60);
        std::cout << finalMinutes << " minutes" << '\n';

        lastSeconds = minutesInSeconds - finalMinutes * 60;
        std::cout << lastSeconds << " seconds" << '\n';
    }
    std::cout << '\n' << '\n' << '\n';
}

void ActorState() {

    enum class ActorState
    {
      running,
      flying,
      falling
    };
    ActorState State{ ActorState::flying };

    std::cout << "--Define and use ActorState--" << '\n';


    switch(State)
    {
    case ActorState::running:
        std::cout << "Running" << '\n';
        break;
    case ActorState::flying:
        std::cout << "Flying" << '\n';
        break;
    case ActorState::falling:
        std::cout << "Falling" << '\n';
        break;
    default:
        std::cout << "Crouching" << '\n';
    }

    std::cout << '\n' << '\n' << '\n';
}

void UsePoint2f() {

    Point2f p1;
    Point2f p2 {};
    Point2f p3 { 26.0F, 25.0F };

    std::cout << "-- Define and use Point2f -- " << '\n';
    std::cout << "Values after evaluation" << '\n';
    std::cout << "p2: [" << p2.x << ", " << p2.y << "]" << '\n';
    std::cout << "p3: [" << p3.x << ", " << p3.y << "]" << '\n';

    p1.x = 20;
    p1.y = 30;

    Point2f{ 30,40 };
    p3.x++;
    p3.y--;

    std::cout << "Values after changing members" << '\n';
    std::cout << "p1: [" << p1.x << ", " << p1.y << "]" << '\n';
    std::cout << "p2: [" << p2.x << ", " << p2.y << "]" << '\n';
    std::cout << "p3: [" << p3.x << ", " << p3.y << "]" << '\n';


}

int main()
{
    std::cout << "Hello World!\n";

    /*
    PrintTruthTable();
    CompareTwoNumbers();
    CalculatePrice();
    ConvertDayNumber();
    CheckLeapYear();
    ConvertSeconds();
    ActorState();
    */
    UsePoint2f();

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
