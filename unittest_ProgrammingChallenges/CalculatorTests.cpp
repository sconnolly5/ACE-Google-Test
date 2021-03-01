#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Calculator.h>
#include <memory.h>

using ::testing::_;
using ::testing::AnyNumber;
using ::testing::Gt;
using ::testing::Return;


TEST(CalculatorTest, TwoNums)
{
	auto calc = std::make_unique<CCalculator>();
	ASSERT_EQ(4, calc->Add(2, 2));
}

class MockCalculator : public CCalculator 
{
public:
	MOCK_METHOD2(Add, int(int a, int b));
};

TEST(CalculatorTest, MockAdd)
{
	//auto mockCalc = std::make_unique<MockCalculator>();
	MockCalculator mockCalc;

	EXPECT_CALL(mockCalc, Add(0, 1)).Times(1);

	mockCalc.Run();
}

TEST(CalculatorTest, StubAdd)
{
	MockCalculator mockCalc;
	ON_CALL(mockCalc, Add(_, _)).WillByDefault(Return(-1));
	ASSERT_EQ(-1, mockCalc.Add(0, 2));
}

int ReturnOneHundred()
{
	return 100;
}

TEST(CalculatorTest, InvokingWithoutArguments)
{
	MockCalculator calc;

	EXPECT_CALL(calc, Add(0, 1))
		.WillOnce(ReturnOneHundred)
		.WillOnce([]() { return 75; })
		.WillRepeatedly([]() { return 50; });

	ASSERT_EQ(100, calc.Add(0, 1));
	ASSERT_EQ(75, calc.Add(0, 1));
	ASSERT_EQ(50, calc.Add(0, 1));
}