#pragma once

#include <vector>
#include "CMenuOption.h"

class CMenu
{
public:
	CMenu(std::vector<CMenuOption*> menuOptions);
	~CMenu();
public:
	void Run();
private:
	void CleanUpMemory();
private:
	std::vector<CMenuOption*> mp_MenuOptions;
};

