// DESEncryption.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<vector>
#include <iostream>
#include <vector>

#include "Formatter.h"
#include "KeyCalculator.h"
#include "Encryptor.h"


std::string concatVector(std::vector<std::string> input) {
	std::string output = "";
	//concat vector
	for (int inputBlockIndex = 0; inputBlockIndex < input.size(); ++inputBlockIndex) {
		output += input[inputBlockIndex];
	}
	return output;
}

int main()
{
	//declare objects
	Encryptor encryptor;

	//hardcode decimal key
	std::string key = "qwertyui";
	std::string input = "Hello my";

	//calculate all required keys
	key = Formatter::AsciiToBinString(key);
	key = KeyCalculator::InitalPermutation(key);
	std::vector<std::string> roundKeys = KeyCalculator::CalculateRoundKeys(key);

	//encrypt plaintext and capture output 
	//IMPORTANT: input must be 64 bits long
	std::vector<std::string> inputBlocks = Formatter::FormatInputForEncryption(input);
	std::vector<std::string> outputBlocksCipherText, outputBlocksPlainText;

	//attempt encryption
	for (int inputBlockIndex = 0; inputBlockIndex < inputBlocks.size(); ++inputBlockIndex) {
		outputBlocksCipherText.push_back(encryptor.Encrypt(inputBlocks[inputBlockIndex], roundKeys));
	}

	std::string ciphertext = concatVector(outputBlocksCipherText);
	ciphertext = Formatter::BinStringToAscii(ciphertext);
	std::cout << "Ciphertext: " << ciphertext << std::endl;

	std::reverse(roundKeys.begin(), roundKeys.end());

	//attempt decryption
	for (int inputBlockIndex = 0; inputBlockIndex < outputBlocksCipherText.size(); ++inputBlockIndex) {
		outputBlocksPlainText.push_back(encryptor.Encrypt(outputBlocksCipherText[inputBlockIndex], roundKeys));
	}

	std::string output = concatVector(outputBlocksPlainText);
	output = Formatter::BinStringToAscii(output);
	std::cout << "Plaintext: " << output << std::endl;
}
