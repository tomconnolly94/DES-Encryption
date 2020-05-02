//external includes
#include <bitset>

//internal includes
#include "DESEncryptionUtil.h"

std::string DESEncryptionUtil::ExecutePermutation(std::string input, std::vector<int> permutationTable) {

	std::string output = "";

	for (int index = 0; index < permutationTable.size(); ++index) {
		output += input[(const unsigned __int64)permutationTable[index] - 1];
	}
	return output;
}

std::string DESEncryptionUtil::BitShiftLeft(std::string shiftee, int numShifts) {

	std::string movingBits = shiftee.substr(0, numShifts);
	std::string shifted = shiftee.substr(numShifts, sizeof(shiftee) - numShifts);

	return shifted + movingBits;
}

std::vector<std::string> DESEncryptionUtil::BisectString(std::string input) {

	std::vector<std::string> output;
	size_t halfLength = input.length() / 2;

	output.push_back(input.substr(0, halfLength));
	output.push_back(input.substr(halfLength, halfLength));
	return output;
}

std::string DESEncryptionUtil::XOR(std::string inputA, std::string inputB){
	std::string output = "";
	for (int i = 0; i < inputA.size(); i++) {
		if (inputA[i] == inputB[i]) {
			output += "0";
		}
		else {
			output += "1";
		}
	}
	return output;
}

std::string DESEncryptionUtil::ConcatVector(std::vector<std::string> input) {
	std::string output = "";
	//concat vector
	for (int inputBlockIndex = 0; inputBlockIndex < input.size(); ++inputBlockIndex) {
		output += input[inputBlockIndex];
	}
	return output;
}