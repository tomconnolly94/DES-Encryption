#include<vector>
#include <iostream>
#include <sstream>
#include <iomanip>  

#include "Formatter.h"

Formatter::Formatter() {};

std::vector<std::string> Formatter::StringToHexArray(std::string input) {

    std::vector<std::string> output;

    for (size_t i = 0;i < input.length(); ++i)
    {
        std::string charRep = IntToHex(input[i]);

        output.push_back(charRep);
    }
    return output;
}

std::string Formatter::IntToHex(int input)
{
    std::stringstream stream;
    stream << "0x"
        << std::setfill('0') << std::setw(sizeof(input) * 2)
        << std::hex << input;
    return stream.str();
}

std::vector<std::string> Formatter::HexToBinary(std::vector<std::string> input) {

    std::vector<std::string> output;

    for (size_t i = 0;i < input.size(); ++i)
    {
        unsigned n;
        input[i] >> n;
        std::bitset<32> b(n);
        // outputs "00000000000000000000000000001010"
        cout << b.to_string() << endl;

        output.push_back(charRep);
    }
    return output;
}