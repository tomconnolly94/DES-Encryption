#include "pch.h"
#include "CppUnitTest.h"
#include "../DESEncryption/DESEncryptionUtil.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DESEncryptionTest
{
	TEST_CLASS(DESEncryptionUtilTest)
	{
	public:

		TEST_METHOD(TestExecutePermutation)
		{
			std::string inputBits = "11000000";
			std::vector<int> permutationTable = { 8, 4, 1, 7, 3, 5, 2, 6 };
			std::string expectedBits = "00100010";

			std::string actualBits = DESEncryptionUtil::ExecutePermutation(inputBits, permutationTable);

			Assert::AreEqual(expectedBits, actualBits);
		}

		TEST_METHOD(TestExecuteExpansionPermutation)
		{
			std::string inputBits = "11000000";
			std::vector<int> permutationTable = { 8, 4, 1, 7, 3, 5, 2, 6, 1, 4, 7 };
			std::string expectedBits = "00100010100";

			std::string actualBits = DESEncryptionUtil::ExecutePermutation(inputBits, permutationTable);

			Assert::AreEqual(expectedBits, actualBits);
		}

		TEST_METHOD(TestBitShiftLeft)
		{
			std::string inputBits = "11000000";
			std::string expectedBitsOneShift = "10000001";
			std::string expectedBitsTwoShifts = "00000011";

			std::string actualBitsOneShift = DESEncryptionUtil::BitShiftLeft(inputBits, 1);
			std::string actualBitsTwoShifts = DESEncryptionUtil::BitShiftLeft(inputBits, 2);

			Assert::AreEqual(expectedBitsOneShift, actualBitsOneShift);
			Assert::AreEqual(expectedBitsTwoShifts, actualBitsTwoShifts);
		}

		TEST_METHOD(TestBisectString)
		{
			std::string inputString = "This string must be split in half.";

			std::vector<std::string> stringParts = DESEncryptionUtil::BisectString(inputString);

			Assert::AreEqual(std::string("This string must "), stringParts[0]);
			Assert::AreEqual(inputString, stringParts[0] + stringParts[1]);
		}

		TEST_METHOD(TestXOR)
		{
			std::string inputString1 = "00001111";
			std::string inputString2 = "00110011";
			std::string expectedOutput = "00111100";

			std::string actualOutput = DESEncryptionUtil::XOR(inputString1, inputString2);

			Assert::AreEqual(expectedOutput, actualOutput);
		}
	};
}
