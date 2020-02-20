// DESEncryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<vector>
#include <iostream>
#include <vector>
#include "Formatter.h"

int main()
{
    std::string input = "hello";

    std::cout << input << std::endl;

    Formatter formatter;

    std::vector<std::string> output = formatter.StringToHexArray(input);

    for (std::string str : output) {
        std::cout << str << std::endl;
    }
}