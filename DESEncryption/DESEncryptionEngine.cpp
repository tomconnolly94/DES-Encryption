// DESEncryption.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<vector>
#include <iostream>
#include <vector>

#include "DESEncryptionEngine.h"
#include "Formatter.h"
#include "KeyCalculator.h"
#include "Encryptor.h"
#include "Util.h"

DESEncryptionEngine::DESEncryptionEngine(){}

/**
 * Run all operations in a DES En/Decrypting exercise.
 *
 * @param asciiKey Key in ASCII format
 * @param binaryPlainTextBlocks input plaintext as binary string of any length
 * @return output ciphertext text as binary string of x*64 length
 */
std::string DESEncryptionEngine::RunEncryptionEngine(std::string asciiKey, std::string binaryPlainTextBlocks)
{
	//hardcode decimal key
	std::string key = "qwertyui";
	std::string input = "Hello my";

	//calculate all required keys
	key = Formatter::AsciiToBinString(key);
	key = KeyCalculator::InitalPermutation(key);
	std::vector<std::string> roundKeys = KeyCalculator::CalculateRoundKeys(key);

	std::vector<std::string> inputBlocks = Formatter::FormatInputForEncryption(input);
	std::vector<std::string> outputBlocksCipherText;

	//attempt encryption
	for (int inputBlockIndex = 0; inputBlockIndex < inputBlocks.size(); ++inputBlockIndex) {
		outputBlocksCipherText.push_back(Encryptor::Encrypt(inputBlocks[inputBlockIndex], roundKeys));
	}

	return Util::ConcatVector(outputBlocksCipherText);
}