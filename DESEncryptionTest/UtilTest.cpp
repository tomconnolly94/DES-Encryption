#include "pch.h"
#include "CppUnitTest.h"
#include "../DESEncryption/Util.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DESEncryptionTest
{
	TEST_CLASS(UtilTest)
	{
	public:

		TEST_METHOD(TestExecutePermutation)
		{
			std::string inputBits = "11000000";
			std::vector<int> permutationTable = { 8, 4, 1, 7, 3, 5, 2, 6 };
			std::string expectedBits = "00100010";

			std::string actualBits = Util::ExecutePermutation(inputBits, permutationTable);

			Assert::AreEqual(expectedBits, actualBits);
		}

		TEST_METHOD(TestExecuteExpansionPermutation)
		{
			std::string inputBits = "11000000";
			std::vector<int> permutationTable = { 8, 4, 1, 7, 3, 5, 2, 6, 1, 4, 7 };
			std::string expectedBits = "00100010100";

			std::string actualBits = Util::ExecutePermutation(inputBits, permutationTable);

			Assert::AreEqual(expectedBits, actualBits);
		}

		TEST_METHOD(TestBitShiftLeft)
		{
			std::string inputBits = "11000000";
			std::string expectedBitsOneShift = "10000001";
			std::string expectedBitsTwoShifts = "00000011";

			std::string actualBitsOneShift = Util::BitShiftLeft(inputBits, 1);
			std::string actualBitsTwoShifts = Util::BitShiftLeft(inputBits, 2);

			Assert::AreEqual(expectedBitsOneShift, actualBitsOneShift);
			Assert::AreEqual(expectedBitsTwoShifts, actualBitsTwoShifts);
		}

		TEST_METHOD(TestBisectString)
		{
			std::string inputString = "This string must be split in half.";

			std::vector<std::string> stringParts = Util::BisectString(inputString);

			Assert::AreEqual(std::string("This string must "), stringParts[0]);
			Assert::AreEqual(inputString, stringParts[0] + stringParts[1]);
		}

		TEST_METHOD(TestXOR)
		{
			std::string inputString1 = "00001111";
			std::string inputString2 = "00110011";
			std::string expectedOutput = "00111100";

			std::string actualOutput = Util::XOR(inputString1, inputString2);

			Assert::AreEqual(expectedOutput, actualOutput);
		}

		TEST_METHOD(TestConvertBinaryToDecimal)
		{
			std::string inputString1 = "011";
			std::string inputString2 = "1011";
			int expectedOutput1 = 3;
			int expectedOutput2 = 11;

			int actualOutput1 = Util::ConvertBinaryToDecimal(inputString1);
			int actualOutput2 = Util::ConvertBinaryToDecimal(inputString2);

			Assert::AreEqual(expectedOutput1, actualOutput1);
			Assert::AreEqual(expectedOutput2, actualOutput2);
		}

		TEST_METHOD(TestConvertDecimalToBinary)
		{
			int inputString1 = 5;
			int inputString2 = 15;
			std::string expectedOutput1 = "101";
			std::string expectedOutput2 = "000101";
			std::string expectedOutput3 = "00001111";

			std::string actualOutput1 = Util::ConvertDecimalToBinary(inputString1, 3);
			std::string actualOutput2 = Util::ConvertDecimalToBinary(inputString1, 6);
			std::string actualOutput3 = Util::ConvertDecimalToBinary(inputString2, 8);

			Assert::AreEqual(expectedOutput1, actualOutput1);
			Assert::AreEqual(expectedOutput2, actualOutput2);
			Assert::AreEqual(expectedOutput3, actualOutput3);
		}
	};
}
