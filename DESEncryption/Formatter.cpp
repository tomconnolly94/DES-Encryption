#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>

#include "Formatter.h"

Formatter::Formatter() {};

std::string Formatter::StringToBinaryArray(std::string input) {

    std::string output;

    for (size_t i = 0;i < input.length(); ++i)
    {
        std::string charRep = CharToBinary(input[i]);

        output += charRep;
    }
    return output;
}

std::string Formatter::CharToBinary(char input) {
    char buffer[33]; //the variable you will store i's new value (binary value) in
    _itoa_s(input, buffer, 2);
    printf("binary: %s\n", buffer);
    buffer[32] = NULL;
    return buffer;
}