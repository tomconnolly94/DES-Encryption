#pragma once
#include <string>
#include <vector>

class Util {
public:
	static std::string ExecutePermutation(std::string key, std::vector<int> permutationTable);
	static std::string BitShiftLeft(std::string key, int numShifts);
	static std::vector<std::string> HalfVector(std::string input);
	static std::string XOR(std::string inputA, std::string inputB);
	static int ConvertBinaryToDecimal(std::string strInput);
	static std::string ConvertDecimalToBinary(int strInput, int requiredLength);
private:
};