#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>

extern "C" double FindArea(double, double, double, double);
extern "C" double FindPerimeter(double, double, double, double);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
	TEST_CLASS(RectangleTests1)
	{
	public:
		
		TEST_METHOD(FindAreaTest1)
		{
			double result = FindArea(4.56, 7.34, 4.56, 7.34);
			Assert::AreEqual(33.4704, result);
		}
		TEST_METHOD(FindAreaTest2)
		{
			double result = FindArea(4.56, 7.34, 6.4, 5.6);
			Assert::AreEqual(-1.0, result);
		}

		TEST_METHOD(FindAreaTest3)
		{
			double result = FindArea(4.5, 12.45, 12.45, 4.5);
			Assert::AreEqual(56.025, result);
		}

		TEST_METHOD(FindAreaTest4)
		{
			double result = FindArea(0, 2.45, 2.45, 0);
			Assert::AreEqual(0.0, result);
		}

	};

	TEST_CLASS(RectangleTests2)
	{
	public:

		TEST_METHOD(FindPerimeterTest1)
		{
			double result = FindPerimeter(45.32, 8.234, 45.32, 8.234);
			Assert::AreEqual(107.108, result);
		}

		TEST_METHOD(FindPerimeterTest2)
		{
			double result = FindPerimeter(1.2, 3.6, 3.6, 1.2);
			Assert::AreEqual(9.6, result);
		}

		TEST_METHOD(FindPerimeterTest3)
		{
			double result = FindPerimeter(3.3, 4.4, 5.5, 6.6);
			Assert::AreEqual(-1.0, result);
		}

		TEST_METHOD(FindPerimeterTest4)
		{
			double result = FindPerimeter(0, 2.45, 2.45, 0);
			Assert::AreEqual(4.9, result);
		}

	};
}
