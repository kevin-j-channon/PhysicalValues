#include "pch.h"
#include "CppUnitTest.h"

#include <Physical/Unit.hpp>
#include <Physical/Units/Length.hpp>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestPhysical
{

using namespace common;
using namespace common::unit;

	TEST_CLASS(Units)
	{
	public:
		
		TEST_METHOD(Value_x_unit_give_quantity)
		{
            const auto len = 1 * metre;

            Assert::AreEqual( 1.0, len.in<Metres>());
		}
	};
}
