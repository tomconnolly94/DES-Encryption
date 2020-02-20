#pragma once
#include <string>

class Formatter {
public:
	Formatter();
	std::vector<std::string> StringToHexArray(std::string);
	std::vector<std::string> HexToBinary(std::vector<std::string>);
private:
	std::string IntToHex(int input);
};