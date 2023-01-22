#pragma once
#include <string>
#include "ConsoleGUI.h"
#include "Grid.h"
#include "Block.h"

class Game
{
private:
	ConsoleGUI _cGUI;
	Grid _grid;
	void consoleClear();
	int getUserInput(std::string text, std::string errorText, int min, int max);


public:
	void Init();
	void setConsoleGUI(ConsoleGUI cGUI);
	void setGrid(Grid grid);
};

