#include "pch.h"
#include "CFibonacciOption.h"
#include <iostream>

using namespace std;

CFibonacciImplementation::CFibonacciImplementation(int numFibonacciElements)
{
	this->m_NumFibonacciElements = numFibonacciElements;
}

void CFibonacciImplementation::Run()
{
    cout << "Please enter your first number." << endl;
    int firstNum = LoopForUserInput();

    // Get the second number from the user
    cout << "Please enter your second number." << endl;
    int secondNum = LoopForUserInput();

    // Empty the list to ensure nothing can pollute the sequence
    m_Sequence.clear();

    // Add the numbers we have retrieved from the user
    m_Sequence.push_back(firstNum);
    m_Sequence.push_back(secondNum);

    // Update the sequence based on numbers provided
    InitialiseFibonacciSequence();

    // Output the sequence
    OutputSequence();
}

int CFibonacciImplementation::LoopForUserInput()
{
    int result;
    cin >> result;
    return result;
}

/// <summary>
/// Calculates what the numbers of the fibonacci sequence are based on the details provided
/// </summary>
void CFibonacciImplementation::InitialiseFibonacciSequence()
{
    for (int i = 0; i < m_NumFibonacciElements; i++)
    {
        // Add the two previous elements in the list
        int nextNumInSequence = m_Sequence[m_Sequence.size() - 1] + m_Sequence[m_Sequence.size() - 2];

        // Append the newly calculated number to the list
        m_Sequence.push_back(nextNumInSequence);
    }
}

/// <summary>
/// Outputs the Fibonacci sequence variable to the console in a readable format
/// </summary>
void CFibonacciImplementation::OutputSequence()
{
    // Output the Fibonacci sequence based on the 
    for (int i = 0; i < m_Sequence.size(); i++)
    {
        cout << m_Sequence[i];
        if (i != m_Sequence.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}