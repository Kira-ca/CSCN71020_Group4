#include "pch.h"
#include "CppUnitTest.h"
#include <stdio.h>

//extern "C" char* analyzeTriangle(int, int, int);
extern "C" double* FindAnglesInTriangleAndPrint(double, double, double);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AngleFinderTest
{
	TEST_CLASS(FindAnglesinTriangleFucntionality)
	{
	public:
		//THIS IS TESTING A SCALENE TRIANGLE INPUT
		TEST_METHOD(FindAnglesInScaleneTest1)
		{
			//This test is to examine the the function "FindAnglesInTriangleAndPrint"
			//The test is checking if the function accurately calculates the three angles of a scalene triangle
			
			//FindAnglesInTriangleAndPrint(2, 3, 4)
			//This test is to check if the first angle is correct from the 3 sides are entered

			
			double* angle;
			angle = FindAnglesInTriangleAndPrint(2, 3, 4);
			
			Assert::AreEqual(28.955878354654878, angle[0]);


		}
		TEST_METHOD(FindAnglesInScaleneTest2)
		{
			//This test is to examine the the function "FindAnglesInTriangleAndPrint"
			//The test is checking if the function accurately calculates the three angles of a scalene triangle
			 
			//FindAnglesInTriangleAndPrint(2, 3, 4)
			//This test is to check if the secound angle is correct from the 3 sides are entered


			double* angle;
			angle = FindAnglesInTriangleAndPrint(2, 3, 4);
			Assert::AreEqual(46.568836876128891, angle[1]);
		}
		TEST_METHOD(FindAnglesInScaleneTest3)
		{
			//This test is to examine the the function "FindAnglesInTriangleAndPrint"
			//The test is checking if the function accurately calculates the three angles of a scalene triangle
			 
			//FindAnglesInTriangleAndPrint(2, 3, 4)
			//This test is to check if the third angle is correct from the 3 sides are entered

	
			double* angle;
			angle = FindAnglesInTriangleAndPrint(2, 3, 4);
			Assert::AreEqual(104.47528476921622, angle[2]);


		}



		//THIS IS TESTING AN ISOSCELES TRIANGLE INPUT
		TEST_METHOD(FindAnglesInIsoscelesTest1)
		{
			//This test is to examine the the function "FindAnglesInTriangleAndPrint"
			//The test is checking if the function accurately calculates the three angles of an isosceles triangle

			//FindAnglesInTriangleAndPrint(3, 3, 5)
			//This test is to check if the third angle is correct from the 3 sides are entered

			
			double* angle;
			angle = FindAnglesInTriangleAndPrint(3, 3, 5);
			Assert::AreEqual(33.558299481867621, angle[0]);


		}
		TEST_METHOD(FindAnglesInIsoscelesTest2)
		{
			//This test is to examine the the function "FindAnglesInTriangleAndPrint"
			//The test is checking if the function accurately calculates the three angles of a isosceles triangle

			//FindAnglesInTriangleAndPrint(3, 3, 5)
			//This test is to check if the third angle is correct from the 3 sides are entered

			
			double* angle;
			angle = FindAnglesInTriangleAndPrint(3, 3, 5);
			Assert::AreEqual(33.558299481867621, angle[1]);


		}
		TEST_METHOD(FindAnglesInIsoscelesTest3)
		{
			//This test is to examine the the function "FindAnglesInTriangleAndPrint"
			//The test is checking if the function accurately calculates the three angles of an isosceles triangle

			//FindAnglesInTriangleAndPrint(3, 3, 5)
			//This test is to check if the third angle is correct from the 3 sides are entered

			
			double* angle;
			angle = FindAnglesInTriangleAndPrint(3, 3, 5);
			Assert::AreEqual(112.88340103626477, angle[2]);


		}



		//THIS IS TESTING AN EQUILATERAL TRIANGLE INPUT
		TEST_METHOD(FindAnglesInEquilateralTest1)
		{
			//This test is to examine the the function "FindAnglesInTriangleAndPrint"
			//The test is checking if the function accurately calculates the three angles of an equilateral triangle

			//FindAnglesInTriangleAndPrint(2, 2, 2)
			//This test is to check if the third angle is correct from the 3 sides are entered


			double* angle;
			angle = FindAnglesInTriangleAndPrint(2, 2, 2);
			Assert::AreEqual(60.001769605407482, angle[0]);

		}
		TEST_METHOD(FindAnglesInEquilateralTest2)
		{
			//This test is to examine the the function "FindAnglesInTriangleAndPrint"
			//The test is checking if the function accurately calculates the three angles of an equilateral triangle

			//FindAnglesInTriangleAndPrint(2, 2, 2)
			//This test is to check if the third angle is correct from the 3 sides are entered


			double* angle;
			angle = FindAnglesInTriangleAndPrint(2, 2, 2);
			Assert::AreEqual(60.001769605407482, angle[1]);

		}
		TEST_METHOD(FindAnglesInEquilateralTest3)
		{
			//This test is to examine the the function "FindAnglesInTriangleAndPrint"
			//The test is checking if the function accurately calculates the three angles of an equilateral triangle

			//FindAnglesInTriangleAndPrint(2, 2, 2)
			//This test is to check if the third angle is correct from the 3 sides are entered


			double* angle;
			angle = FindAnglesInTriangleAndPrint(2, 2, 2);
			Assert::AreEqual(59.996460789185043, angle[2]);

		}

	};

}
