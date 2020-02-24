#pragma once
#include <string>

class Formatter {
public:
	Formatter();
	std::vector<std::string> StringToBinaryArray(std::string);
private:
	std::string CharToBinary(char input);
};