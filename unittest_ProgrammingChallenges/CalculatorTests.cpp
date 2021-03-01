#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Calculator.h>

TEST(CalculatorTest, TwoNums)
{
	auto calc = std::make_unique<CCalculator>();
	ASSERT_EQ(4, calc->Add(2, 2));
}

