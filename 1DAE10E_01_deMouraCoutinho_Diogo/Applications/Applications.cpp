// Applications.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
    //Variables for Menu
    int InitialOption{};

    //Variables for Option 1 Distance
    float InitialDistance_in_KM{};
    float Distance_meters{};
    float Distance_centimeters{};

    //Variables for Option 2 Colors


    //Variables for Option 3 Angles
    float InitialRadians{};
    float InitialDegrees{};
    float FinalRadians{};
    float FinalDegrees{};

    //Variables for Option 4 Rotation
    float oneRotation{ 360 };
    float secondsRotation{};
    float degress_secondRotation{};


    //Variables for Option 5 Speed
    float initialTime{};
    float initialSpeed{};
    float metersSpeed{};

    //Variables for Option 6 Gravity
    float distanceElapse{};
    float secondsFalling{};
    float gravityFalling{9.8};
    float velocityFalling{};

    //Variables for Option 7 Radius of a Circle
    float circleRadius{};
    float circleArea{};
    float circleCircumference{};

    //Variables for Option 8 Height and Width of a Rectangle 
    float rectWidth{};
    float rectHeigth{};
    float rectArea{};
    float rectPerimeter{};

    //Variables for Option 9 Height and Base of Rectangle
    float triBase{};
    float triHeight{};
    float triArea{};

    //Menu
    std::cout << "Hello There!\n";
    std::cout << "My name is Matt and I am here to help you convert over multiple values" << '\n';
    std::cout << "Press ENTER to begin..." << '\n';
    std::cin.get(); //Receives input from the ENTER
    std::cout << '\n' << "Colors:                                            (1)";
    std::cout << '\n' << "Distances:                                         (2)";
    std::cout << '\n' << "Angles:                                            (3)";
    std::cout << '\n' << "Object Rotation:                                   (4)";
    std::cout << '\n' << "Speed(km):                                         (5)";
    std::cout << '\n' << "Gravity speed:                                     (6)";
    std::cout << '\n' << "Radius of Circle to Area and Circumference:        (7)";
    std::cout << '\n' << "Height & Witdh of Rect to Area and perimeter:      (8)";
    std::cout << '\n' << "Base & Heigh of Triangle to Area:                  (9)";
    std::cout << '\n' << '\n' << "Choose one of the options above: ";

    std::cin >> InitialOption; //

    while (!(InitialOption >= 1 && InitialOption <= 9)) //Makes sure it receives input only from the options above and nothing else // If the input is different it will repeat this command until it is viable input
    {
        
        std::cout << '\n' << "Choose one of the following options: ";
        std::cout << '\n' << "Distances:                                         (1)";
        std::cout << '\n' << "Colors:                                            (2)";
        std::cout << '\n' << "Angles:                                            (3)";
        std::cout << '\n' << "Object Rotation:                                   (4)";
        std::cout << '\n' << "Speed(km):                                         (5)";
        std::cout << '\n' << "Gravity speed:                                     (6)";
        std::cout << '\n' << "Radius of Circle to Area and Circumference:        (7)";
        std::cout << '\n' << "Height & Witdh of Rect to Area and perimeter:      (8)";
        std::cout << '\n' << "Base & Heigh of Triangle to Area:                  (9)" ;
        std::cout << '\n' << "You have not provided a viable option. Please provide one of the options above:  "; 
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
        std::cin >> InitialOption; // receives another input in the case the user did not write an int between 1 and 9
    }

    std::cout << '\n';

    //Converting Distances----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    if (InitialOption == 1)
    {
        std::cout << '\n' << "You will be converting distance from Kilometers to Meters and to Centimeters" << '\n';
        std::cout << "Please type the distance you would like to convert: ";
        while (!(std::cin >> InitialDistance_in_KM)) { // if the input is anything but a int, it will be asked to place a value again

            std::cout << "You have not prvided a viable value. Try again: ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }
        
        Distance_meters = InitialDistance_in_KM * 1000;
        Distance_centimeters = InitialDistance_in_KM * 1000000;



        std::cout << '\n' << "You picked " << InitialDistance_in_KM;
        std::cout << '\n' << InitialDistance_in_KM << " is equal to: ";
        std::cout << '\n' << Distance_meters << " meters!";
        std::cout << '\n' << Distance_centimeters << " centimeters!";

    }


    //Converting colors----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if (InitialOption == 2) {
        std::cout << "Unfortunatly this option is not yet available";
        std::cout << '\n' << "Please pick any of the other options" << '\n';
        std::cin.clear(); //
        std::cin.ignore(123, '\n');
        std::wcout << '\n';
        main();
    }


    //Converting Angles----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if (InitialOption == 3) {
        std::cout << "Bellow type the value for radians you want to conver to degrees: ";
        while (!(std::cin >> InitialRadians)){

            std::cout << "You have not prvided a viable value. Try again: ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
       }

        std::cout << '\n' << "Bellow type the value for degrees you want to conver to radians: ";
        while (!(std::cin >> InitialDegrees)) {

            std::cout << "You have not provided a viable value. Try again: ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        FinalRadians = InitialDegrees * (3.14/ 180);
        FinalDegrees = InitialRadians * (180 / 3.14);

        std::cout << '\n' << InitialRadians << " Radians is equal to " << FinalDegrees << "Degrees";
        std::cout << '\n' << InitialDegrees << " Degrees is equal to " << FinalRadians << "Radians";

    }

    //Converting Object Rotations----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if (InitialOption == 4) {
        std::cout << "Object Rotation";
        std::cout << '\n' << "How long to complete 1 rotation: ";

            while (!(std::cin >> secondsRotation)) {
                std::cout << "You have not provided a viable value. Try again: ";
                std::cin.clear();
                std::cin.ignore(123, '\n');
        }

        degress_secondRotation = oneRotation / secondsRotation;

        std::cout << '\n' << "The said item rotates " << degress_secondRotation << " degrees per second";
    }

    //Figuring Distance by speed and time----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if (InitialOption == 5) {
        
        std::cout << "Here you will intruduce the speed in KM" << '\n' << "Then we convert distance in meters done after theelapsed time aso intruduced by you" << '\n';
        std::cout << '\n' << "Intruduce your time in seconds: ";
        while (!(std::cin >> initialTime)) {

            std::cout << "You have not prvided a viable value. Try again: ";
            std::cin.clear();
            std::cin.ignore(123, '\n');

        }

        std::cout << '\n' << "Intruduce your speed in Km: ";
        while (!(std::cin >> initialSpeed)) {

            std::cout << "You have not prvided a viable value. Try again: ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        metersSpeed = initialSpeed * 1000; 

        distanceElapse = metersSpeed * initialTime;

        std::cout << '\n' << "At " << initialSpeed << "km/h for " << initialTime << " seconds, the distance traveled was " << distanceElapse << "meters";
    }

    //Option 6 Gravity----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if (InitialOption == 6) {
        std::cout << "Consider an object in free fall accelerating downwards at a rate of 9.8 m/s";
        std::cout << '\n' << "Enter the number of seconds the object is falling: ";
            while (!(std::cin >> secondsFalling)) {

                std::cout << "You have not prvided a viable value. Try again: ";
                std::cin.clear();
                std::cin.ignore(123, '\n');

            }

            velocityFalling = gravityFalling * secondsFalling;

            std::cout << '\n' << "You entered: " << secondsFalling << " seconds";
            std::cout << '\n' << "The velocity is " << velocityFalling << "m/s";
    }

    //Option 7 Radius ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if (InitialOption == 7) {
        std::cout << "Intruduce a value for radius and it will be calculated the Area and Circumference of that Circle";
        std::cout << '\n' << "Enter the value for Radius: ";
        while (!(std::cin >> circleRadius)) {
            
            std::cout << '\n' << "You have not prvided a viable value. Try again: ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        circleCircumference = circleRadius * 2 * 3.14;
        circleArea = 3.14 * (circleRadius * circleRadius);

        std::cout << '\n' << "You have picked radius: " << circleRadius;
        std::cout << '\n' << "The Area of your circle is: " << circleArea;
        std::cout << '\n' << "The Circumference of your circle is: " << circleCircumference;
    }
   
    // Option 8 Width and Height of Rect ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if (InitialOption == 8) {
        std::cout << "Intruduce a value for Hieght and Width and it will calculate the Area and Perimeter of that Rectangle";
        std::cout << '\n' << "Enter the value for Width: ";
        
        while (!(std::cin >> rectWidth)) {
            std::cout << '\n' << "You have not prvided a viable value. Try again: ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        std::cout << '\n' << "Enter the value for Height: ";

        while (!(std::cin >> rectHeigth)) {
            std::cout << '\n' << "You have not prvided a viable value. Try again: ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        std::cout << '\n' << '\n' << "Your Width: " << rectWidth;
        std::cout << '\n' << "Your Height: " << rectHeigth;

        rectPerimeter = (rectHeigth * 2) + (rectWidth * 2);
        rectArea = rectWidth * rectHeigth;

        std::cout << '\n' << "Your Perimeter is: " << rectPerimeter;
        std::cout << '\n' << "Your Area is: " << rectArea;
    }

    //Option 9 Base and Height of Triangle to calculare Area----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    else if (InitialOption == 9) {
        std::cout << "Intruduce the value for the Base and Height of a Triangle and the Area will be calculated";
        std::cout << '\n' << "Enter the value for Base: ";

        while (!(std::cin >> triBase)) {
            std::cout << '\n' << "You have not prvided a viable value. Try again: ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        std::cout << '\n' << "Enter the value for Height: ";
        while (!(std::cin >> triHeight)) {
            std::cout << '\n' << "You have not prvided a viable value. Try again: ";
            std::cin.clear();
            std::cin.ignore(123, '\n');
        }

        std::cout << '\n' << "Your Base: " << triBase;
        std::cout << '\n' << "Your Height: " << triHeight;

        triArea = (triBase * triHeight) / 2;

        std::cout << '\n' << "Your Triangle Area is: " << triArea;
    }
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
