// DESEncryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<vector>
#include <iostream>
#include <vector>

#include "Formatter.h"
#include "KeyCalculator.h"

int main()
{

	Formatter formatter;
	KeyCalculator keycalculator;

	std::string key = "qwertyui";

	std::cout << key << std::endl;

	key = formatter.StringToBinaryArray(key);

	key = keycalculator.InitalPermutation(key);
	std::vector<std::string> roundKeys = keycalculator.CalculateRoundKeys(key);

	for (int roundKeysIndex = 0; roundKeysIndex < roundKeys.size(); ++roundKeysIndex) {
		std::cout << roundKeys[roundKeysIndex] << std::endl;
		std::cout << sizeof(roundKeys[roundKeysIndex]) << std::endl;
	}
}