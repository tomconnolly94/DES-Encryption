#pragma once
#include <string>
#include <vector>

//data types
struct VectorHalves {
	std::string leftPart;
	std::string rightPart;
};

class Util {
public:
	static std::string ExecutePermutation(std::string key, std::vector<int> permutationTable);
	static std::string BitShiftLeft(std::string key, int numShifts);
	static std::vector<std::string> HalfVector(std::string input);
private:
};