#pragma once
#include <string>
#include<vector>

class Formatter {
public:
	Formatter();
	std::string AsciiToBinString(std::string);
	std::string BinStringToAscii(std::string);
private:
	std::string CharToBinString(char input);
	char BinStringToChar(std::string input);
};