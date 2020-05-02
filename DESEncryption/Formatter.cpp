#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>

#include "Formatter.h"

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

    for (size_t i = 0;i < input.length(); i+=8)
    {
        char charRep = BinStringToChar(input.substr(i, 8));

        output += charRep;
    }
    return output;
}

char Formatter::BinStringToChar(std::string input) {
    std::bitset<8> temp(input);
    return temp.to_ulong();
}

std::vector<std::string> Formatter::FormatInputForEncryption(std::string input) {

    std::vector<std::string> inputBlocks;

    for (int inputSplittingIndex = 0; inputSplittingIndex < input.size(); inputSplittingIndex += 64) {
        inputBlocks.push_back(input.substr(inputSplittingIndex, 64));
    }

    size_t finalBlockSize = inputBlocks[inputBlocks.size() - 1].size();
    int paddingBitsRequired = 64 - finalBlockSize;

    for (int paddingIndex = 0; paddingIndex < paddingBitsRequired; ++paddingIndex) {
        inputBlocks[inputBlocks.size() - 1] += "0";
    }
    return inputBlocks;
}