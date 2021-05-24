#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5.1-A/MyException.h"
#include "../Lab_5.1-A/MyException.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest51A
{
	TEST_CLASS(UnitTest51A)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			MyException A("Negative argument");
			string m1 = "Negative argument";
			string m2 = A.What();
			Assert::AreEqual(m1, m2);

		}
	};
}
