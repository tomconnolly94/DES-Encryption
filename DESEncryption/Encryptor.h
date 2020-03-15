#pragma once
#include <string>
#include <vector>

class Encryptor {
public:
	Encryptor();
	std::string Encrypt(std::string input, std::vector<std::string> roundkeys);
private:
	std::string ExecuteInitialPermutation(std::string input);
	std::string ExecuteExpansionPermutation(std::string input);
	std::string SBoxPermutation(std::string input);
	std::string ExecuteStraightPermutation(std::string input);
	std::string ExecuteFinalPermutation(std::string input);
};