#include "Util.h"
#include <bitset>

std::string Util::ExecutePermutation(std::string input, std::vector<int> permutationTable) {

	std::string output = "";

	for (int index = 0; index < permutationTable.size(); ++index) {
		output += input[(const unsigned __int64)permutationTable[index] - 1];
	}
	return output;
}

std::string Util::BitShiftLeft(std::string shiftee, int numShifts) {

	std::string movingBits = shiftee.substr(0, numShifts);
	std::string shifted = shiftee.substr(numShifts, sizeof(shiftee) - numShifts);

	return shifted + movingBits;
}

std::vector<std::string> Util::BisectString(std::string input) {

	std::vector<std::string> output;
	size_t halfLength = input.length() / 2;

	output.push_back(input.substr(0, halfLength));
	output.push_back(input.substr(halfLength, halfLength));
	return output;
}

std::string Util::XOR(std::string inputA, std::string inputB){
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

int Util::ConvertBinaryToDecimal(std::string strInput)
{
	long long input = std::stoll(strInput);

	int decimalNumber = 0, i = 0, remainder;
	while (input != 0)
	{
		remainder = input % 10;
		input /= 10;
		decimalNumber += remainder * pow(2, i);
		++i;
	}
	return decimalNumber;
}

std::string Util::ConvertDecimalToBinary(int strInput, int requiredLength)
{
	const int initialBitNum = 8;
	int bitsToCull = initialBitNum - requiredLength;

	std::string output = std::bitset<initialBitNum>(int(strInput)).to_string();
	output = output.substr(bitsToCull);

	return output;
}


std::string Util::ConcatVector(std::vector<std::string> input) {
	std::string output = "";
	//concat vector
	for (int inputBlockIndex = 0; inputBlockIndex < input.size(); ++inputBlockIndex) {
		output += input[inputBlockIndex];
	}
	return output;
}