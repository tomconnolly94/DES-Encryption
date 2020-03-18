#pragma once
#include <string>
#include <vector>

class KeyCalculator {
public:
	static std::string InitalPermutation(std::string keyInput);
	static std::vector<std::string> CalculateRoundKeys(std::string keyInput);
private:
};