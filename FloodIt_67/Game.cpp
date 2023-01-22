#include <iostream>
#include <conio.h>
#include "Game.h"

using namespace std;
void Game::consoleClear()
{
    system("cls");
}

int Game::getUserInput(string text, string errorText, int min, int max)
{
    int input;
    bool firstTime = true;
    while (true)
    {
        consoleClear();
        if (!firstTime)
		{
			std::cout << errorText << std::endl; 
			firstTime = true;
		}
        std::cout << text;

		if (std::cin >> input && input >= min && input <= max) { return input; }
        else
        {
            std::cin.clear();
            std::cin.ignore();
        }
    }
}

void Game::Init()
{
	while (true)
	{
		consoleClear();
		cout << "** FloodIt Game **\nM. Pawlowski 2023\n";
		cout << "Press ENTER to start new game" << endl;
		cout << "Press ESC to exit" << endl;

		int key = 0;
		const int ESC = 27;
		const int ENTER = 13;

		// wait for ESC or ENTER
		while (1)
		{
			key = 0;
			key = _getch();
			if (key == ESC || key == ENTER) break;
		}
		if (key == ESC) break;
		else if (key == ENTER)
		{
			string textHeader = "**GAME SETTINGS**\nPress ESC to go back\n\n";
			unsigned int rowSize = getUserInput(textHeader + "Enter number of rows (2-20):\t", "Incorrect input, try again!", 2, 20);
			unsigned int colSize = getUserInput(textHeader + "Enter number of columns (2-20):\t", "Incorrect input, try again!", 2, 20);
			unsigned int noOfColors = getUserInput(textHeader + "Enter number of colors (2-6):\t", "Incorrect input, try again!", 2, 6);

		}

	}
}
