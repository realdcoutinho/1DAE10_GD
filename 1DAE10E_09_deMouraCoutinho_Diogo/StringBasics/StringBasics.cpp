// StringBasics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Diogo de Moura Coutinho

#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS // important that it is before, must be inlcuded
#include <iostream>
#include <cstring>
#include <string>

void Strings();

int main()
{
    std::string hello{ "Hello my name is Diogo." };
    std::cout << hello << '\n';
    std::cout << "The size of the string is                   : " << hello.size() << " bytes" << '\n';
    std::cout << "The lenght of the string is                 : " << hello.length() << " bytes" << '\n';
    std::cout << "The capacity of the string is               : " << hello.capacity() << " bytes" << '\n';
    std::cout << "First character of the string using [] is   : " << hello[0] << '\n';
    std::cout << "Last character of the string using [] is    : " << hello[hello.size() - 1] << '\n';

    std::cout << "First character of the string using 'at' is : " << hello.at(0) << '\n';
    std::cout << "Last character of the string using 'at' is  : " << hello.at(hello.size() - 1) << '\n';
    std::string str{ "o" };
    //std::size_t found = hello.find(str);

    size_t position{ 0 };
    std::cout << "Occurances of '" << str << "' at: " << std::endl;
    do
    {
        position = hello.find(str, position);
        if (position != std::string::npos)
        {
            std::cout << position << " ";
            position++;
        }
    } while (position != std::string::npos);
    std::cout << std::endl << std::endl;


    position = hello.size();
    std::cout << "Occurances of '" << str << "' at: " << std::endl;
    do
    {
        position = hello.rfind(str, position);
        if (position != std::string::npos)
        {
            std::cout << position << " ";
            position--;
        }
    } while (position != std::string::npos);
    std::cout << std::endl << std::endl;


    std::string choice{};
    std::string ast{ "*" };
    std::cin >> choice;


    position = 0 ;
    std::cout << "Occurances of '" << choice << "' at: " << std::endl;
    do
    {
        position = hello.find(choice, position);
        if (position != std::string::npos)
        {
            str.replace(position, hello.size(), ast);
            if (position < hello.size()) {
                position++;
            }

        }
    } while (position != std::string::npos);
    std::cout << hello << '\n';
    std::cout << std::endl << std::endl;



    
    // {

    //}

    //if (found != std::string::npos)
    //    std::cout << "first 'needle' found at: " << found << '\n';



    /*
        std::cout << '\n';

    for (unsigned int i{}; i < hello.size(); ++i) {
        std::cout << hello[i] << "_";
    }
    std::cout << '\n';
    std::cout << '\n';

    
    char* cstr = new char[hello.length() + 1];
    std::strcpy(cstr, hello.c_str());
    char* p = std::strtok(cstr, " ");
    while (p != 0)
    {
        std::cout << p << "_";
        p = std::strtok(NULL, " ");
    }
    delete[] cstr;
    */
    std::cout << '\n';

}

void Strings()
{

}