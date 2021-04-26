#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_5.1G/Man.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Man m;
			m.Init("name", 20, 'm', 50.5);
			Assert::AreEqual("	Name : name\n	Age : 20\n	Gender : m\n	Weight : 50.5", m.toString().c_str());
		}
	};
}
