#pragma once

#include "CMenuImplementation.h"
#include <vector>

class CFibonacciImplementation : public CMenuImplementation
{
public:
	CFibonacciImplementation(int numFibonacciElements);
public:
	// Inherited via CMenuImplementation
	virtual void Run() override;

	void InitialiseFibonacciSequence();
private:
	int LoopForUserInput();
	void OutputSequence();
private:
	/// <summary>
	/// The number of fibonacci elements to count forwards.
	/// </summary>
	int m_NumFibonacciElements;

public:
	/// <summary>
	/// This is the sequence of numbers that currently exist within the sequence
	/// </summary>
	std::vector<int> m_Sequence;
};

