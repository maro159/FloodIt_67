#include <iostream>
#include "ConsoleTools.h"


using namespace std;


int main()
{
    ConsoleTools tool;
    //tool.SetFontSize(8, 8);

	for (size_t i = 0; i < 6; i++)
	{
		tool.DrawBlock(i * 20, 0, 10, (Colors)i);
	}

}


