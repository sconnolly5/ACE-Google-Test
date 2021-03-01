#include "CMenuOption.h"
#include "CMenuImplementation.h"

using namespace std;

CMenuOption::CMenuOption(int index, string label, CMenuImplementation* menuImplementation)
{
	this->m_Index = index;
	this->m_Label = label;
	this->mp_MenuImplementation = menuImplementation;
}

CMenuOption::~CMenuOption()
{
	CleanUpMemory();
}

int CMenuOption::GetIndex() const
{
	return m_Index;
}

std::string CMenuOption::GetLabel() const
{
	return m_Label;
}

CMenuImplementation* CMenuOption::GetImpl() const
{
	return mp_MenuImplementation;
}

void CMenuOption::CleanUpMemory()
{
	/*
	* Note this is old C++. As of C++ 11, we should be using smart pointers.
	* I'm not going to use smart pointers in order to simplify what it is I'm trying to demonstrate.
	* We use smart pointers to avoid us having to rely on the programmer to clean up memory. This reliance
	* makes us more susceptible to memory leaks.
	*
	* Smart pointers good, raw pointers bad.
	*/
	if (nullptr != this->mp_MenuImplementation)
	{
		delete this->mp_MenuImplementation;
	}
}
