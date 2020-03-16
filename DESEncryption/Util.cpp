#include "Util.h"

std::string Util::ExecutePermutation(std::string keyInput, std::vector<int> permutationTable) {

	std::string outputKey = "";

	for (int index = 0; index < permutationTable.size(); ++index) {
		const unsigned __int64 keyIndex = permutationTable[index];
		char translation = keyInput[keyIndex - 1];
		outputKey += keyInput[(const unsigned __int64)permutationTable[index] - 1];
	}
	return outputKey;
}

std::string Util::BitShiftLeft(std::string shiftee, int numShifts) {

	std::string movingBits = shiftee.substr(0, numShifts);
	std::string shifted = shiftee.substr(numShifts, sizeof(shiftee) - numShifts);

	return shifted + movingBits;
}

std::vector<std::string> Util::HalfVector(std::string input) {

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
	std::string output;
	for (int i = 0; strInput > 0; ++i)
	{
		output += std::to_string(strInput % 2);
		strInput = strInput / 2;
	}

	int paddingBitsRequired = requiredLength - output.size();

	for (int paddingIndex = 0; paddingIndex < paddingBitsRequired; ++paddingIndex) {
		output = "0" + output;
	}

	return output;
}