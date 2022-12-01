#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>
#include <stdbool.h>

extern "C" double FindArea(double, double, double, double);
extern "C" double FindPerimeter(double, double, double, double);
extern "C" struct POINT { int x, y; };
extern "C" bool ArePointsDuplicated(POINT, POINT, POINT, POINT);

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


	TEST_CLASS(ArePointsDuplicatedFunctionality)
	{
	public:

		TEST_METHOD(ValidateDuplicatedPointsTest1)
		{
			// Initialize points with positive dummy values
			// This is testing if more than one point is repeated on the same coordinate
			// All 4 points (x,y) are passed to the ArePointsDuplicated Function, check if a point has duplicated which return either true ,else false
			POINT point1;
			POINT point2;
			POINT point3;
			POINT point4;

			point1.x = 5;
			point1.y = 1;

			point2.x = 3;
			point2.y = 4;

			point3.x = 6;
			point3.y = 5;

			point4.x = 5;
			point4.y = 1;

			Assert::IsTrue(ArePointsDuplicated(point1, point2, point3, point4));
		}

		TEST_METHOD(ValidateDuplicatedPointsTest2)
		{
			// Initialize points with negative dummy values
			// This is testing if more than one point is repeated on the same coordinate
			// All 4 points (x,y) are passed to the ArePointsDuplicated Function, check if a point has duplicated which return either true ,else false
			POINT point1;
			POINT point2;
			POINT point3;
			POINT point4;

			point1.x = -1;
			point1.y = -2;

			point2.x = -2;
			point2.y = -1;

			point3.x = -2;
			point3.y = -1;

			point4.x = -1;
			point4.y = -2;

			Assert::IsTrue(ArePointsDuplicated(point1, point2, point3, point4));
		}

		TEST_METHOD(ValidateDuplicatedPointsTest3)
		{
			// Initialize points with both positive and negative dummy values
			// This is testing if more than one point is repeated on the same coordinate
			// All 4 points (x,y) are passed to the ArePointsDuplicated Function, check if a point has duplicated which return either true ,else false
			POINT point1;
			POINT point2;
			POINT point3;
			POINT point4;

			point1.x = 10;
			point1.y = -4;

			point2.x = -20;
			point2.y = -2;

			point3.x = -4;
			point3.y = 10;

			point4.x = 10;
			point4.y = -4;

			Assert::IsTrue(ArePointsDuplicated(point1, point2, point3, point4));
		};

		TEST_METHOD(ValidateDuplicatedPointsTest4)
		{
			// Initialize points with both positive and negative dummy values
			// This is testing if more than one point is repeated on the same coordinate
			// All 4 points (x,y) are passed to the ArePointsDuplicated Function, check if a point has duplicated which return either true ,else false
			POINT point1;
			POINT point2;
			POINT point3;
			POINT point4;

			point1.x = 100;
			point1.y = -3;

			point2.x = 101;
			point2.y = -2;

			point3.x = -3;
			point3.y = 100;

			point4.x = -2;
			point4.y = 101;

			Assert::IsFalse(ArePointsDuplicated(point1, point2, point3, point4));
		};
	};
}
