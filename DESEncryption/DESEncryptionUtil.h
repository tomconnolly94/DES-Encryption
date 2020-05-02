#pragma once

#include <string>
#include <vector>

#include "../CppCommonTProj/CppCommonTProj/Util.h"

class DESEncryptionUtil : public Util {
public:
	static std::string ExecutePermutation(std::string key, std::vector<int> permutationTable);
	static std::string BitShiftLeft(std::string key, int numShifts);
	static std::vector<std::string> BisectString(std::string input);
	static std::string XOR(std::string inputA, std::string inputB);
	static std::string ConcatVector(std::vector<std::string> input);
};