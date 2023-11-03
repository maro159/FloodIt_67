#include <iostream>
#include <cstdlib>
#include <ctime>

#include <conio.h>

#include "ConsoleGUI.h"
#include "Grid.h"
#include "Block.h"

using namespace std;

int main()
{
	srand(time(NULL)); // get new seed for rand
	const unsigned int fontSize = 36;
	const unsigned int blockSize = 1;
	const unsigned int gridXPos = 0;
	const unsigned int gridYPos = 0;

	ConsoleGUI cGUI(blockSize, gridXPos, gridYPos, fontSize);

	// main loop
	while (true)
	{
		cGUI.consoleClear();
		cout << "** FloodIt Game **\nmaro159 2023\n";
		cout << "Press ENTER to start new game" << endl;
		cout << "Press ESC to exit" << endl;

		int key = 0;

		// wait for ESC or ENTER
		while (true)
		{
			key = 0;
			key = _getch();
			if (key == Keys::ESC || key == Keys::ENTER) break;
		}
		if (key == Keys::ESC) break;
		else if (key == Keys::ENTER)
		{
			cGUI.showConsoleCursor(true);
			string textHeader = "**GAME SETTINGS**\nPress ESC to go back\n\n";
			unsigned int rowSize = cGUI.getUserInput(textHeader + "Enter number of rows (2-20):\t", "Incorrect input, try again!", 2, 20);
			unsigned int colSize = cGUI.getUserInput(textHeader + "Enter number of columns (2-20):\t", "Incorrect input, try again!", 2, 20);
			unsigned int noOfColors = cGUI.getUserInput(textHeader + "Enter number of colors (3-6):\t", "Incorrect input, try again!", 3, 6);
			Grid grid(rowSize, colSize, noOfColors);
			cGUI.showConsoleCursor(false);
			cGUI.consoleClear();
			cGUI.redrawGrid(grid);
			cGUI.printMoveStat(grid);
			while (grid.getMoves() < grid.getMaxMoves() && !grid.isOneColor())
			{
				Colors newColor = cGUI.selectFloodColor(grid);
				if (newColor == Colors::None) break; // detect if user entered ESC
				grid.flood(newColor);
				cGUI.redrawGrid(grid);
				cGUI.printMoveStat(grid);
			}
			cGUI.printResult(grid);
			
			int key = 0;
			// wait for ESC or ENTER
			while (true)
			{
				key = 0;
				key = _getch();
				if (key == Keys::ESC || key == Keys::ENTER) break;
			}
		}
	}
	
}


