#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>
#include <stdbool.h>

extern "C" double FindArea(double, double, double, double);
extern "C" double FindPerimeter(double, double, double, double);
extern "C" struct POINT { int x, y; };
extern "C" POINT AssignPoints(int x, int y);
extern "C" bool ArePointsDuplicated(POINT, POINT, POINT, POINT);
extern "C" double FindDiagonalOfNonRightTriangle(POINT, POINT);
extern "C" double FindHypotenuseOfRightTriangle(double, double);

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


	TEST_CLASS(AssignPointsFunctionality)
	{
	public:

		TEST_METHOD(ValidateAssignPointsTest1)
		{
			// Initialize points with positive dummy values
			// This is testing to validate if the a point with x, y coordinate are assign to POINT struct and return the correct result
			POINT expectedPoints;
			expectedPoints.x = 5;
			expectedPoints.y = 2;

			POINT actualPoints = AssignPoints(5, 2);

			Assert::AreEqual(expectedPoints.x, actualPoints.x);
			Assert::AreEqual(expectedPoints.y, actualPoints.y);
		};

		TEST_METHOD(ValidateAssignPointsTest2)
		{
			// Initialize points with negative dummy values
			// This is testing to validate if the a point with x, y coordinate are assign to POINT struct and return the correct result
			POINT expectedPoints;
			expectedPoints.x = -2;
			expectedPoints.y = -1;

			POINT actualPoints = AssignPoints(-2, -1);

			Assert::AreEqual(expectedPoints.x, actualPoints.x);
			Assert::AreEqual(expectedPoints.y, actualPoints.y);
		};

		TEST_METHOD(ValidateAssignPointsTest3)
		{
			// Initialize points with negative value on y coordinate and positive value on x coordinate dummy values
			// This is testing to validate if the a point with x, y coordinate are assign to POINT struct and return the correct result
			POINT expectedPoints;
			expectedPoints.x = -23;
			expectedPoints.y = 91;

			POINT actualPoints = AssignPoints(-23, 91);

			Assert::AreEqual(expectedPoints.x, actualPoints.x);
			Assert::AreEqual(expectedPoints.y, actualPoints.y);
		};

		TEST_METHOD(ValidateAssignPointsTest4)
		{
			// Initialize points with positive value on x coordinate and negative value on y coordinate dummy values
			// This is testing to validate if the a point with x, y coordinate are assign to POINT struct and return the correct result
			POINT expectedPoints;
			expectedPoints.x = 12;
			expectedPoints.y = -3;

			POINT actualPoints = AssignPoints(12, -3);

			Assert::AreEqual(expectedPoints.x, actualPoints.x);
			Assert::AreEqual(expectedPoints.y, actualPoints.y);
		}
	};

	TEST_CLASS(FindDiagonalOfNonRightTriangleFunctionality)
	{
	public:

		TEST_METHOD(FindDiagonalOfNonRightTriangleTest1)
		{
			// Initialize pointA and B (x,y coordinate) with dummy values
			// This is testing to validate the function calculate Diagonal of a triangle of a rectangle return the correct result
			POINT pointA, pointB;

			pointA.x = -3;
			pointA.y = 2;

			pointB.x = 4;
			pointB.y = 2;

			double expectedResult = 7.000000;
			double actualResult = FindDiagonalOfNonRightTriangle(pointA, pointB);

			Assert::AreEqual(expectedResult, actualResult);
		};

		TEST_METHOD(FindDiagonalOfNonRightTriangleTest2)
		{
			// Initialize pointC and D (x,y coordinate) with dummy values
			// This is testing to validate the function calculate Diagonal of a triangle of a rectangle return the correct result
			POINT pointC, pointD;

			pointC.x = -3;
			pointC.y = -3;

			pointD.x = 4;
			pointD.y = -3;

			double expectedResult = 7.000000;
			double actualResult = FindDiagonalOfNonRightTriangle(pointC, pointD);

			Assert::AreEqual(expectedResult, actualResult);
		};
	};

	TEST_CLASS(FindHypotenuseOfRightTriangleFunctionality)
	{
	public:

		TEST_METHOD(FindHypotenuseOfRightTriangleTriangleTest1)
		{
			// This is testing to validate the function calculate the hypotenuse of a triangle of a rectangle return the correct result
			// dummy values are passed to the function to calculate the hypotenuse of a triangle

			double expectedResult = 6.7082039324993694;
			double actualResult = FindHypotenuseOfRightTriangle(6.00, 3.00);

			Assert::AreEqual(expectedResult, actualResult);
		};

		TEST_METHOD(FindHypotenuseOfRightTriangleTriangleTest2)
		{
			// This is testing to validate the function calculate the hypotenuse of a triangle of a rectangle return the correct result
			// dummy values are passed to the function to calculate the hypotenuse of a triangle
			double expectedResult = 65.783512372022216;
			double actualResult = FindHypotenuseOfRightTriangle(54.31, 37.12);

			Assert::AreEqual(expectedResult, actualResult);
		};
	};

}
