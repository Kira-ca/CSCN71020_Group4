#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>

//including the necessary external functions and structures
extern "C" struct POINT { int x, y; };
extern "C" double FindArea(double, double, double, double);
extern "C" double FindPerimeter(double, double, double, double);
extern "C" void FixPointOrder(POINT*);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleTests
{
	TEST_CLASS(RectangleTests1)
	{
	public:
		
		TEST_METHOD(FindAreaTest1)
		{
			//testing proper values
			double result = FindArea(4.56, 7.34, 4.56, 7.34);
			Assert::AreEqual(33.4704, result);
		}
		TEST_METHOD(FindAreaTest2)
		{
			//testing improper values
			double result = FindArea(4.56, 7.34, 6.4, 5.6);
			Assert::AreEqual(-1.0, result);
		}

		TEST_METHOD(FindAreaTest3)
		{
			//testing proper values in different order
			double result = FindArea(4.5, 12.45, 12.45, 4.5);
			Assert::AreEqual(56.025, result);
		}

		TEST_METHOD(FindAreaTest4)
		{
			//testing boundary values inside boundary as a check happens before this
			double result = FindArea(1, 2.45, 2.45, 1);
			Assert::AreEqual(2.45, result);
		}

	};

	TEST_CLASS(RectangleTests2)
	{
	public:

		TEST_METHOD(FindPerimeterTest1)
		{
			//testing proper values
			double result = FindPerimeter(45.32, 8.234, 45.32, 8.234);
			Assert::AreEqual(107.108, result);
		}

		TEST_METHOD(FindPerimeterTest2)
		{
			//testing proper values in different order
			double result = FindPerimeter(1.2, 3.6, 3.6, 1.2);
			Assert::AreEqual(9.6, result);
		}

		TEST_METHOD(FindPerimeterTest3)
		{
			//testing improper values
			double result = FindPerimeter(3.3, 4.4, 5.5, 6.6);
			Assert::AreEqual(-1.0, result);
		}
		
		TEST_METHOD(FindPerimeterTest4)
		{
			//testing boundary values inside boundary as a check happens before this
			double result = FindPerimeter(1, 2.45, 2.45, 1);
			Assert::AreEqual(6.9, result);
		}

	};

	TEST_CLASS(RectangleTests3)
	{
		TEST_METHOD(FixPointOrderTest1)
		{
			//testing random values
			POINT point1 = { 1,1 };
			POINT point2 = { 2,4 };
			POINT point3 = { 2,1 };
			POINT point4 = { 1,4 };

			POINT actual[4] = { point1, point2, point3, point4 };
			FixPointOrder(actual);

			POINT expected[4] = { {1,1}, {2,1}, {2,4}, {1,4} };
			Assert::AreEqual(expected[0].x, actual[0].x);
			Assert::AreEqual(expected[1].x, actual[1].x);
			Assert::AreEqual(expected[2].x, actual[2].x);
			Assert::AreEqual(expected[3].x, actual[3].x);

			Assert::AreEqual(expected[0].y, actual[0].y);
			Assert::AreEqual(expected[1].y, actual[1].y);
			Assert::AreEqual(expected[2].y, actual[2].y);
			Assert::AreEqual(expected[3].y, actual[3].y);
		}

		TEST_METHOD(FixPointOrderTest2)
		{
			//testing random values
			POINT point1 = { 5,-1 };
			POINT point2 = { 5,2 };
			POINT point3 = { 3,-1 };
			POINT point4 = { 3,2 };

			POINT actual[4] = { point1, point2, point3, point4 };
			FixPointOrder(actual);

			POINT expected[4] = { {3,-1}, {5,-1}, {5,2}, {3,2} };
			Assert::AreEqual(expected[0].x, actual[0].x);
			Assert::AreEqual(expected[1].x, actual[1].x);
			Assert::AreEqual(expected[2].x, actual[2].x);
			Assert::AreEqual(expected[3].x, actual[3].x);

			Assert::AreEqual(expected[0].y, actual[0].y);
			Assert::AreEqual(expected[1].y, actual[1].y);
			Assert::AreEqual(expected[2].y, actual[2].y);
			Assert::AreEqual(expected[3].y, actual[3].y);
		}

		TEST_METHOD(FixPointOrderTest3)
		{
			//testing random values
			POINT point1 = { -10,13 };
			POINT point2 = { 15,-4 };
			POINT point3 = { -10,-4};
			POINT point4 = { 15,13 };

			POINT actual[4] = { point1, point2, point3, point4 };
			FixPointOrder(actual);

			POINT expected[4] = { {-10,-4}, {-10,13}, {15,13}, {15,-4} };
			Assert::AreEqual(expected[0].x, actual[0].x);
			Assert::AreEqual(expected[1].x, actual[1].x);
			Assert::AreEqual(expected[2].x, actual[2].x);
			Assert::AreEqual(expected[3].x, actual[3].x);

			Assert::AreEqual(expected[0].y, actual[0].y);
			Assert::AreEqual(expected[1].y, actual[1].y);
			Assert::AreEqual(expected[2].y, actual[2].y);
			Assert::AreEqual(expected[3].y, actual[3].y);
		}
		TEST_METHOD(FixPointOrderTest4)
		{
			//testing random values
			POINT point1 = { 7,7 };
			POINT point2 = { 0,7 };
			POINT point3 = { 7,0 };
			POINT point4 = { 0,0 };

			POINT actual[4] = { point1, point2, point3, point4 };
			FixPointOrder(actual);

			POINT expected[4] = { {0,0}, {0,7}, {7,7}, {7,0} };
			Assert::AreEqual(expected[0].x, actual[0].x);
			Assert::AreEqual(expected[1].x, actual[1].x);
			Assert::AreEqual(expected[2].x, actual[2].x);
			Assert::AreEqual(expected[3].x, actual[3].x);

			Assert::AreEqual(expected[0].y, actual[0].y);
			Assert::AreEqual(expected[1].y, actual[1].y);
			Assert::AreEqual(expected[2].y, actual[2].y);
			Assert::AreEqual(expected[3].y, actual[3].y);
		}
	};
}
