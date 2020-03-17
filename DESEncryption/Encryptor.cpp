#include <iostream>
#include <sstream>
#include <iomanip>
#include <bitset>
#include <map>

#include "Encryptor.h"
#include "Util.h"
#include "PermutationTable.h"

std::string Encryptor::Encrypt(std::string input, std::vector<std::string> roundKeys) {

	//initial permutation
	input = ExecuteInitialPermutation(input);

	//split data into left and right parts
	std::vector<std::string> splitData = Util::BisectString(input);
	std::string leftPart = splitData[0];
	std::string rightPart = splitData[1];
	std::string origRightPart = "";

	for (int roundIndex = 0; roundIndex < roundKeys.size(); ++roundIndex) {

		origRightPart = rightPart;

		//expansion DBox permutation
		rightPart = ExecuteExpansionPermutation(rightPart);

		//roundKey XOR
		rightPart = Util::XOR(rightPart, roundKeys[roundIndex]);

		//sBox permutation
		rightPart = SBoxPermutation(rightPart);

		//straight dBox permutation
		rightPart = ExecuteStraightPermutation(rightPart);

		rightPart = Util::XOR(rightPart, leftPart);


		if (roundIndex == (roundKeys.size() - 1)) {
			leftPart = rightPart;
			rightPart = origRightPart;
		}
		else {
			leftPart = origRightPart;
		}
	}

	//combine and return
	std::string output = leftPart + rightPart;
	return ExecuteFinalPermutation(output);
}

std::string Encryptor::ExecuteInitialPermutation(std::string input) {
	return Util::ExecutePermutation(input, PermutationTable::InitialPermutationTable);
}

std::string Encryptor::ExecuteExpansionPermutation(std::string input) {
	return Util::ExecutePermutation(input, PermutationTable::ExpansionPermutationTable);
}

std::string Encryptor::ExecuteStraightPermutation(std::string input) {
	return Util::ExecutePermutation(input, PermutationTable::StraightPermutationTable);
}

std::string Encryptor::ExecuteFinalPermutation(std::string input) {
	return Util::ExecutePermutation(input, PermutationTable::FinalPermutationTable);
}

//48 bit input, 32 bit output
std::string Encryptor::SBoxPermutation(std::string input) {

	std::string output = "";

	for (int sBoxIndex = 0; sBoxIndex < 8; ++sBoxIndex) {
		////get sbox co-ordinates
		int yCoord = Util::ConvertBinaryToDecimal(input.substr(0, 1) + input.substr(5, 1));
		int xCoord = Util::ConvertBinaryToDecimal(input.substr(1, 4));

		output += Util::ConvertDecimalToBinary(PermutationTable::SBoxPermutationTable[sBoxIndex][yCoord][xCoord], 4);
		input = input.substr(6);
	}
	return output;
}
