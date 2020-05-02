// DESEncryption.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<vector>
#include <iostream>

#include "DESEncryptionEngine.h"
#include "Formatter.h"
#include "KeyCalculator.h"
#include "Encryptor.h"
#include "DESEncryptionUtil.h"

DESEncryptionEngine::DESEncryptionEngine(){}

/**
 * Run all operations in a DES En/Decrypting exercise.
 *
 * @param asciiKey Key in ASCII format
 * @param binaryPlainTextBlocks input plaintext as binary string of any length
 * @return output ciphertext text as binary string of x*64 length
 */
std::string DESEncryptionEngine::RunEncryptionEngine(std::string asciiKey, std::string binaryPlainTextBlocks, bool encrypting)
{
	//hardcode decimal key
	std::string key = "qwertyui";

	//calculate all required keys
	key = Formatter::AsciiToBinString(key);
	key = KeyCalculator::InitalPermutation(key);
	std::vector<std::string> roundKeys = KeyCalculator::CalculateRoundKeys(key);

	if (!encrypting) {
		std::reverse(roundKeys.begin(), roundKeys.end());
	}

	std::vector<std::string> inputBlocks = Formatter::FormatInputForEncryption(binaryPlainTextBlocks);
	std::vector<std::string> outputBlocksCipherText;

	//attempt encryption
	for (int inputBlockIndex = 0; inputBlockIndex < inputBlocks.size(); ++inputBlockIndex) {
		outputBlocksCipherText.push_back(Encryptor::Encrypt(inputBlocks[inputBlockIndex], roundKeys));
	}

	return DESEncryptionUtil::ConcatVector(outputBlocksCipherText);
}
