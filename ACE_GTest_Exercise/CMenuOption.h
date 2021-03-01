#pragma once

#include <string>

class CMenuImplementation;

class CMenuOption
{
public:
	CMenuOption(int index, std::string label, CMenuImplementation* menuImplementation);
	~CMenuOption();
public:
	int GetIndex() const;
	std::string GetLabel() const;
	CMenuImplementation* GetImpl() const;
private:
	/// <summary>
	/// Cleans up the memory of any pointers belonging to this class that have been allocated
	/// </summary>
	void CleanUpMemory();
private:
	/// <summary>
	/// The index of this option as it will appear in the menu
	/// </summary>
	int m_Index;

	/// <summary>
	/// The label that will appear next to this option in the menu
	/// </summary>
	std::string m_Label;
	
	/// <summary>
	/// The implementation of this menu
	/// </summary>
	CMenuImplementation* mp_MenuImplementation;
};

