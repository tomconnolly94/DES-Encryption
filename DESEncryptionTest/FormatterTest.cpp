#include "pch.h"
#include "CppUnitTest.h"
#include "../DESEncryption/Formatter.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DESEncryptionTest
{
	TEST_CLASS(FormatterTest)
	{
	public:

		TEST_METHOD(TestExecutePermutation)
		{
			std::string inputText = "a";
			std::string expectedBits = "01100001";

			std::string actualBits = Formatter::AsciiToBinString(inputText);

			Assert::AreEqual(expectedBits, actualBits);
		}

		TEST_METHOD(TestBinStringToAscii)
		{
			std::string inputBits = "0110100001100101011011000110110001101111";
			std::string expectedText = "hello";

			std::string actualText = Formatter::BinStringToAscii(inputBits);

			Assert::AreEqual(expectedText, actualText);
		}

		TEST_METHOD(TestFormatInputForEncryption)
		{
			std::string inputText = "This will be encrypted.";
			std::vector<std::string> expectedBlocks = {
				"0101010001101000011010010111001100100000011101110110100101101100",
				"0110110000100000011000100110010100100000011001010110111001100011",
				"0111001001111001011100000111010001100101011001000010111000000000" 
			};

			std::vector<std::string> actualBlocks = Formatter::FormatInputForEncryption(inputText);

			Assert::AreEqual(expectedBlocks.size(), actualBlocks.size());

			for (int i = 0; i < actualBlocks.size(); ++i) {
				Assert::AreEqual(expectedBlocks[i], actualBlocks[i]);
			}
		}
	};
}
