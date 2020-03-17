#pragma once

class DESEncryptionEngine {
public:
	DESEncryptionEngine();
	std::string RunEncryptionEngine(std::string asciiKey, std::string binaryPlainTextBlocks);
private:
};