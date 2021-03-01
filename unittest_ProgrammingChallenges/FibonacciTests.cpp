#include "CFibonacciOption.h"
#include <memory>
#include <gtest/gtest.h>

TEST(FibonacciTests, validNumberGenerated)
{
	auto fibonacci = std::make_unique<CFibonacciImplementation>(1);
	fibonacci->m_Sequence.push_back(1);
	fibonacci->m_Sequence.push_back(2);
	fibonacci->InitialiseFibonacciSequence();
	ASSERT_EQ(3, fibonacci->m_Sequence.back());
}