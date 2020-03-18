#pragma once
#include <string>
#include <vector>

class Encryptor {
public:
	static std::string Encrypt(std::string input, std::vector<std::string> roundkeys);
private:
	static std::string ExecuteInitialPermutation(std::string input);
	static std::string ExecuteExpansionPermutation(std::string input);
	static std::string SBoxPermutation(std::string input);
	static std::string ExecuteStraightPermutation(std::string input);
	static std::string ExecuteFinalPermutation(std::string input);
};