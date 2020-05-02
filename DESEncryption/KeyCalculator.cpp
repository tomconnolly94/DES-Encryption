#include "KeyCalculator.h"
#include "DESEncryptionUtil.h"
#include "PermutationTable.h"

std::string KeyCalculator::InitalPermutation(std::string keyInput) {
	return DESEncryptionUtil::ExecutePermutation(keyInput, PermutationTable::KeyIntialPermutationTable);
}

std::vector<std::string> KeyCalculator::CalculateRoundKeys(std::string keyInput) {
	
	std::vector<std::string> splitKey = DESEncryptionUtil::BisectString(keyInput);
	std::string leftKey = splitKey[0];
	std::string rightKey = splitKey[1];

	std::vector<std::string> outputKeys = {};

	//16 rounds of encryption so 16 keys are required
	for (int roundIndex = 0; roundIndex < 16; ++roundIndex) {
		leftKey = DESEncryptionUtil::BitShiftLeft(leftKey, PermutationTable::KeyShiftTable[roundIndex]);
		rightKey = DESEncryptionUtil::BitShiftLeft(rightKey, PermutationTable::KeyShiftTable[roundIndex]);

		std::string key = leftKey + rightKey;

		//perform compression permutation
		key = DESEncryptionUtil::ExecutePermutation(key, PermutationTable::KeyCompressionPermutationTable);

		outputKeys.push_back(key);

	}
	return outputKeys;
}



