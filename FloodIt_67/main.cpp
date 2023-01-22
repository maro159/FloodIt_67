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
	//srand(time(NULL));
	//unsigned int rowSize = 0;
	//unsigned int colSize = 0;
	//unsigned int noOfColors = 0;

	//cout << "FloodIt Game" << endl;
	//cout << "maro159 2023" << endl;
	//cout << "\n\n**GAME SETTINGS**" << endl;
	//cout << "Enter number of rows (2-20):\t";
	//cin >> rowSize;
	//cout << "Enter number of columns (2-20):\t";
	//cin >> colSize;
	//cout << "Enter number of colors (2-6):\t";
	//cin >> noOfColors;
    unsigned char key, key2;
    while (true)
    {
		key = cin.get();
		key2 = getch();
		cout << "cin\t" << key << endl;
		system("pause");
		cout << "getch\t" << key2 << endl;
    }

   

}


