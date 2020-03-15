#pragma once
#include <string>
#include <vector>

class Formatter {
public:
	static std::string AsciiToBinString(std::string);
	static std::string BinStringToAscii(std::string);
	static std::vector<std::string> FormatInputForEncryption(std::string input);
private:
	static std::string CharToBinString(char input);
	static char BinStringToChar(std::string input);
};