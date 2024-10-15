#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_6.4rec/Lab_6.4rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double arr1[] = { 1.5, -2.0, 3.0, 4.0, -5.0 };
			Assert::AreEqual(18.0, productElement(arr1, 5)); // 1.5 * 3.0 * 4.0 = 18.0

			double arr2[] = { 1.0, -2.0, -3.0 };
			Assert::AreEqual(1., productElement(arr2, 3)); // Немає позитивних елементів

			double arr3[] = { 0.0, 2.0, 0.0, 3.0 };
			Assert::AreEqual(6.0, productElement(arr3, 4)); // 2.0 * 3.0 = 6.0
		}
	};
}
