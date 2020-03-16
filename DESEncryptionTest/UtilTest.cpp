#include "pch.h"
#include "CppUnitTest.h"
#include "../DESEncryption/Util.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DESEncryptionTest
{
	TEST_CLASS(UtilTest)
	{
	public:

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
	};
}
