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
			// analyzeTriangle(20, 10, 10);
			char* result;
			result = analyzeTriangle(20, 10, 13);
			Assert::AreEqual("Scalene triangle", result);
		}

		TEST_METHOD(TriangleTypeTest3)
		{
			// This is testing the analyze Triangle function using 3 points
			// Valid input should output Isosceles triangle (atleast 2 sides of equal length)
			// analyzeTriangle(20, 20, 13);
			char* result;
			result = analyzeTriangle(20, 20, 13);
			Assert::AreEqual("Isosceles triangle", result);
		}

		TEST_METHOD(TriangleTypeTest4)
		{
			// This is testing the analyze Triangle function using 3 points
			// Valid input should output Isosceles triangle (atleast 2 sides of equal length)
			// analyzeTriangle(20, 12, 20);
			char* result;
			result = analyzeTriangle(20, 12, 20);
			Assert::AreEqual("Isosceles triangle", result);
		}

		TEST_METHOD(TriangleTypeTest5)
		{
			// This is testing the analyze Triangle function using 3 points
			// Invalid input (with zeros) should output Not a triangle 
			// analyzeTriangle(0, 0, 0);
			char* result;
			result = analyzeTriangle(0, 0, 0);
			Assert::AreEqual("Not a triangle", result);
		}

		TEST_METHOD(TriangleTypeTest6)
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
