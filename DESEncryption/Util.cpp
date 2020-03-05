#include "Util.h"

std::string Util::ExecutePermutation(std::string keyInput, std::vector<int> permutationTable) {

	std::string outputKey = "";

	for (int index = 0; index < permutationTable.size(); ++index) {
		char translation = keyInput[(const unsigned __int64)permutationTable[index] - 1];
		outputKey += keyInput[(const unsigned __int64)permutationTable[index] - 1];
	}
	return outputKey;
}

std::string Util::BitShiftLeft(std::string shiftee, int numShifts) {

	std::string movingBits = shiftee.substr(0, numShifts);
	std::string shifted = shiftee.substr(numShifts, sizeof(shiftee) - numShifts);

	return shifted + movingBits;
}