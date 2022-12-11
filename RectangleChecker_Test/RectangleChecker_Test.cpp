#include "pch.h"
#include "CppUnitTest.h"

extern "C" bool RectangleInputValidation(char*, char*);
extern "C" bool PointsToRectangle(int*, int*);				// this is done to tell intellisense that the functions will be available to them once they compile.
extern "C" double Perimeter(double*);						// also it tells them that the program is written in C
extern "C" double Area(double*, bool);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RectangleCheckerTest
{
	TEST_CLASS(UserInputValidation)
	{							// Testing the UserInputValidation feature
	public:
		
		TEST_METHOD(BothInputsValid)
		{
			// This is testing what will the function return when both inputs are valid
			// isInputValid should be true here
			// RectangleInputValidation("-1", "4")

			bool isInputValid = RectangleInputValidation("-1", "4");

			Assert::AreEqual(true, isInputValid);
		}

		TEST_METHOD(FirstInputInvalid) {

			// This is testing what will the function return when first input is invalid
			// isInputValid should be false here
			// RectangleInputValidation("f", "5")

			bool isInputValid = RectangleInputValidation("f", "5");

			Assert::AreEqual(false, isInputValid);
		}

		TEST_METHOD(SecondInputInvalid) {

			// This is testing what will the function return when second input is invalid
			// isInputValid should be false here
			// RectangleInputValidation("-2", "No")

			bool isInputValid = RectangleInputValidation("-2", "No");

			Assert::AreEqual(false, isInputValid);
		}

		TEST_METHOD(BothInputsInvalid) {

			// This is testing what will the function return when both inputs are invalid
			// isInputValid should be false here
			// RectangleInputValidation("Yes", "f")

			bool isInputValid = RectangleInputValidation("Yes", "f");

			Assert::AreEqual(false, isInputValid);
		}
	};

	TEST_CLASS(RectangleCheck) {
									// Testing the RectangleCheck feature
	public:

		TEST_METHOD(PointsDoNotFormRectangle) {

			// This is testing what will the function return when the points entered by user do not form rectangle
			// isARectangle should be false here
			// PointsToRectangle(arrayOfX, arrayOfY)

			int arrayOfX[5] = { 1,2,3,4 };
			int arrayOfY[5] = { 1,2,3,4 };

			bool isARectangle = PointsToRectangle(arrayOfX, arrayOfY);

			Assert::AreEqual(false, isARectangle);
		}

		TEST_METHOD(PointsThatDoFormRectangle) {

			// This is testing what will the function return when the points entered by user do form rectangle
			// isARectangle should be true here
			// PointsToRectangle(arrayOfX, arrayOfY)

			int arrayOfX[5] = { -3,4,4,-3 };
			int arrayOfY[5] = { 2,2,-3,-3 };

			bool isARectangle = PointsToRectangle(arrayOfX, arrayOfY);
			
			Assert::AreEqual(true, isARectangle);
		}
	};

	TEST_CLASS(PerimeterFunctionalityCheck) {
												// Testing the Perimter feature
	public:

		TEST_METHOD(CheckingPerimeterValueOfRectangle) {

			// This is testing what will the function perimeter return when the points entered by user do form rectangle
			// perimeter varaible should have the value 18.0 here
			// Perimeter(arrayOfLengths)

			double arrayOfLengths[5] = { 4,5,4,5 };

			double perimeter = Perimeter(arrayOfLengths);

			Assert::AreEqual(18.0, perimeter);
		}

		TEST_METHOD(CheckingPerimeterValueOfAFigure) {

			// This is testing what will the function perimeter return when the points entered by user do not form rectangle
			// perimeter varaible should have the value 21.98 here
			// Perimeter(arrayOfLengths)

			double arrayOfLengths[5] = { 5,9.65,1,6.33 };

			double perimeter = Perimeter(arrayOfLengths);

			Assert::AreEqual(21.98, perimeter);
		}
	};

	TEST_CLASS(AreaFunctionalityCheck) {
											// Testing the Area feature
	public:

		TEST_METHOD(AreaIfItIsRectangle) {

			// This is testing what will the function Area return when the points entered by user do form rectangle
			// Area varaible should have the value 22.76 here
			// Area(arrayOfLengths, isARectangle)

			double arrayOfLengths[5] = { 4, 5.69, 4, 5.69 };
			bool isARectangle = true;

			double area = Area(arrayOfLengths, isARectangle);

			Assert::AreEqual(22.76, area);
		}

		TEST_METHOD(AreaIfItIsNotARectangle) {

			// This is testing what will the function Area return when the points entered by user do not form rectangle
			// Area varaible should have the value 0.0 here
			// Area(arrayOfLengths, isARectangle)

			double arrayOfLengths[5] = { 5, 3.3, 6, 2.66 };
			bool isARectangle = false;

			double area = Area(arrayOfLengths, isARectangle);

			Assert::AreEqual(0.0, area);
		}
	};
}
