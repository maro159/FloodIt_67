#pragma once
#include "ConsoleGUI.h"
#include "Grid.h"
#include "Block.h"

class App
{
private:
	ConsoleGUI _cGUI;
	Grid _grid;

	const std::string title = "** FloodIt Game **\nM. Pawlowski 2023\n";

public:
	void Init();
};

