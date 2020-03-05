#pragma once
#include <string>
#include<vector>

class Formatter {
public:
	Formatter();
	std::string StringToBinaryArray(std::string);
private:
	std::string CharToBinary(char input);
};