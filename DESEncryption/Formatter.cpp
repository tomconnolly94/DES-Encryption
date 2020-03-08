#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>

#include "Formatter.h"

Formatter::Formatter() {};

std::string Formatter::AsciiToBinString(std::string input) {

    std::string output;

    for (size_t i = 0;i < input.length(); ++i)
    {
        std::string charRep = CharToBinString(input[i]);

        output += charRep;
    }
    return output;
}

std::string Formatter::CharToBinString(char input) {
    std::bitset<8> temp(input);
    return temp.to_string();
}

std::string Formatter::BinStringToAscii(std::string input) {

    std::string output;

    for (size_t i = 0;i < input.length(); ++i)
    {
        std::string charRep = CharToBinString(input[i]);

        output += charRep;
    }
    return output;
}

char Formatter::BinStringToChar(std::string input) {
    std::bitset<8> temp(input);
    return temp.to_ulong();
}
