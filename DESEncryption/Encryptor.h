#pragma once
#include <string>
#include <vector>

class Encryptor {
public:
	Encryptor();
	std::string Encrypt(std::string input);
private:
	std::string ExecuteInitialPermutation(std::string input);
	std::string ExpansionPermutation(std::string input);
	std::string SBoxPermutation(std::string input);
};