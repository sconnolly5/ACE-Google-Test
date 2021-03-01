#include <gtest/gtest.h>
#include <Calculator.h>

TEST(CalculatorTest, TwoNums)
{
	ASSERT_EQ(4, Add(2, 2));
}