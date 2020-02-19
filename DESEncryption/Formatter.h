#pragma once
#include <string>

class Formatter {
public:
	Formatter();
	std::vector<std::string> StringToHexArray(std::string);
private:
	std::string IntToHex(int input);
};