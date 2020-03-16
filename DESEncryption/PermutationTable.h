#pragma once
#include <string>
#include <vector>

class PermutationTable {
public:
	static std::vector<int> InitialPermutationTable;
	static std::vector<int> ExpansionPermutationTable;
	static int SBoxPermutationTable[8][4][16];
	static std::vector<int> StraightPermutationTable;
	static std::vector<int> FinalPermutationTable;
	static std::vector<int> KeyIntialPermutationTable;
	static int KeyShiftTable[16];
	static std::vector<int> KeyCompressionPermutationTable;
};