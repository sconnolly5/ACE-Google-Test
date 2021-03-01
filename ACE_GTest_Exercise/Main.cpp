#include <iostream>
#include <vector>
#include "CMenu.h"
#include "CMenuOption.h"
#include "CFibonacciOption.h";
#include "Main.h"

using namespace std;

int main()
{
	CMenuOption* fibonacciMenuOption = new CMenuOption(1, "Fibonacci Sequence", new CFibonacciImplementation(10));
	vector<CMenuOption*> options { fibonacciMenuOption };
	
	CMenu* menu = new CMenu(options);
	menu->Run();
	delete menu;
	return 0;
}