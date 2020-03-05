#pragma once
#include <string>
#include <vector>

class KeyCalculator {
public:
	KeyCalculator();
	std::string InitalPermutation(std::string);
	std::vector<std::string> CalculateRoundKeys(std::string);
private:
};