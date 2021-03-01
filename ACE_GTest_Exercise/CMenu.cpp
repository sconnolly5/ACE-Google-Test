#include "CMenu.h"
#include "CMenuImplementation.h"
#include <iostream>

using namespace std;

CMenu::CMenu(vector<CMenuOption*> menuOptions)
{
	mp_MenuOptions = menuOptions;
}

CMenu::~CMenu()
{
	CleanUpMemory();
}

void CMenu::CleanUpMemory()
{
	for (auto menuOption : mp_MenuOptions)
	{
		delete menuOption;
	}
}

void CMenu::Run()
{
	cout << "Please select a choice from the menu below. " << endl;
	for (auto option : mp_MenuOptions)
	{
		cout << option->GetIndex() << ") " << option->GetLabel() << endl;
	}
	int choice = 0;
	cin >> choice;

	bool foundOption = false;

	// Choose the menu option the user selected
	for (auto option : mp_MenuOptions)
	{
		if (option->GetIndex() == choice)
		{
			auto impl = option->GetImpl();
			impl->Run();
			foundOption = true;
		}
	}

	// Validate that a menu option was run
	if (!foundOption)
	{
		cout << "No valid option selected. Please try again." << endl;
		Run();
	}
}
