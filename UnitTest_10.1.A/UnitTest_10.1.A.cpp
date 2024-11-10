#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_10.1.A/lab_10.1.A.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest101A
{
	TEST_CLASS(UnitTest101A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int n = 1000;
			Assert::AreEqual(4, calc_n(n));
		}
	};
}
