#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>

extern "C" char* analyzeTriangle(int, int, int);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTest
{
	TEST_CLASS(analyzeTriangleTypeFunctionality)
	{
	public:
	
		TEST_METHOD(TriangleTypeTest1)
		{
			// This is testing the analyze Triangle function using 3 points
			// Valid input should output Equilateral triangle (all sides are equal)
			// analyzeTriangle(10, 10, 10);
			char* result;
			result = analyzeTriangle(10, 10, 10);
			Assert::AreEqual("Equilateral triangle", result);
		}

		TEST_METHOD(TriangleTypeTest2)
		{
			// This is testing the analyze Triangle function using 3 points
			// Valid input should output Scalene triangle (with different sides)
			// analyzeTriangle(50, 73, 18);
			char* result;
			result = analyzeTriangle(50, 73, 18);
			Assert::AreEqual("Scalene triangle", result);
		}

		TEST_METHOD(TriangleTypeTest3)
		{
			// This is testing the analyze Triangle function using 3 points
			// Valid input should output Isosceles triangle (atleast 2 sides of equal length)
			// analyzeTriangle(431, 431, 50);
			char* result;
			result = analyzeTriangle(431, 431, 50);
			Assert::AreEqual("Isosceles triangle", result);
		}

		TEST_METHOD(TriangleTypeTest4)
		{
			// This is testing the analyze Triangle function using 3 points
			// Valid input should output Scalene triangle and not an Isosceles traingle eventhough point 2 and 3 are equal since the order of the user input matters
			// analyzeTriangle(312, 89, 289);
			char* result;
			result = analyzeTriangle(312, 89, 89);
			Assert::AreNotEqual("Isosceles triangle", result);
		}

		TEST_METHOD(TriangleTypeTest5)
		{
			// This is testing the analyze Triangle function using 3 points
			// Valid input should output Isosceles triangle (atleast 2 sides of equal length)
			// analyzeTriangle(0, 0, 0);
			char* result;
			result = analyzeTriangle(20, 12, 20);
			Assert::AreEqual("Isosceles triangle", result);
		}

		TEST_METHOD(TriangleTypeTest6)
		{
			// This is testing the analyze Triangle function using 3 points
			// Invalid input (with zeros) should output Not a triangle 
			// analyzeTriangle(0, 0, 0);
			char* result;
			result = analyzeTriangle(0, 0, 0);
			Assert::AreEqual("Not a triangle", result);
		}

		TEST_METHOD(TriangleTypeTest7)
		{
			// This is testing the analyze Triangle function using 3 points
			// Invalid input (with negative number) should output Not a triangle
			// analyzeTriangle(-1, 20, 20);
			char* result;
			result = analyzeTriangle(-1, 20, 20);
			Assert::AreEqual("Not a triangle", result);
		}
	};
}
