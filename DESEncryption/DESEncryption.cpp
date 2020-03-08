// DESEncryption.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<vector>
#include <iostream>
#include <vector>

#include "Formatter.h"
#include "KeyCalculator.h"
#include "Encryptor.h"

int main()
{
	//declare objects
	Formatter formatter;
	KeyCalculator keycalculator;
	Encryptor encryptor;

	//hardcode decimal key
	std::string key = "qwertyui";
	std::string input = "Hello my name is Tom.";

	//calculate all required keys
	key = formatter.AsciiToBinString(key);
	key = keycalculator.InitalPermutation(key);
	std::vector<std::string> roundKeys = keycalculator.CalculateRoundKeys(key);

	//encrypt plaintext and capture output
	std::string output = encryptor.Encrypt(input);
}