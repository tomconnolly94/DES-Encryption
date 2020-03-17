// DESEncryption.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<vector>
#include <iostream>
#include <vector>

#include "Formatter.h"
#include "KeyCalculator.h"
#include "Encryptor.h"

int main()
{
	//declare objects
	Encryptor encryptor;

	//hardcode decimal key
	std::string key = "qwertyui";
	std::string input = "Hello my name is Tom.";

	//calculate all required keys
	key = Formatter::AsciiToBinString(key);
	key = KeyCalculator::InitalPermutation(key);
	std::vector<std::string> roundKeys = KeyCalculator::CalculateRoundKeys(key);

	//encrypt plaintext and capture output 
	//IMPORTANT: input must be 64 bits long
	std::vector<std::string> inputBlocks = Formatter::FormatInputForEncryption(input);
	std::string output;

	for (int inputBlockIndex = 0; inputBlockIndex < inputBlocks.size(); ++inputBlockIndex) {
		output += encryptor.Encrypt(inputBlocks[inputBlockIndex], roundKeys);
	}

	output = Formatter::BinStringToAscii(output);

	std::cout << "Ciphertext: " << output << std::endl;
}