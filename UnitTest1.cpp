#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Monika\source\repos\V1.5\main\main.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			studentas laikinas;
			laikinas.setVardas("Vardas");
			std::string x = "Vardas";
			Assert::AreEqual(laikinas.getVardas(), x);
		}

		TEST_METHOD(TestMethod2) {
			studentas laikinas;
			laikinas.setVardas("Vardas");
			studentas laikinas2;
			laikinas2.setVardas("Naujas");
			laikinas = laikinas2;
			std::string x = "Naujas";
			Assert::AreEqual(laikinas.getVardas(), x);
		}
	};
}
