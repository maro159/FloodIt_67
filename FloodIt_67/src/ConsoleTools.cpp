#include <iostream>
#include "ConsoleTools.h"

std::map<Colors, int> colorDecoder
{
    { Green, 2 },
    { Aqua, 3 },
    { Red, 4 },
    { Purple, 5 },
    { Yellow, 6 },
    { White, 15 },
};


//void ConsoleTools::SetFontSize(SHORT x, SHORT y)
//{
//    // Get the console handle
//    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//
//    // Get the current console font information
//    CONSOLE_FONT_INFOEX cfi;
//    cfi.cbSize = sizeof(cfi);
//    GetCurrentConsoleFontEx(hConsole, false, &cfi);
//    // Change the font size to (x,y)
//    cfi.dwFontSize.X = x;
//    cfi.dwFontSize.Y = y;
//    wcscpy_s(cfi.FaceName, L"Terminal");
//
//    // Set the new console font
//    SetCurrentConsoleFontEx(hConsole, false, &cfi);
//
//}

void ConsoleTools::SetColor(Colors color)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorCode = colorDecoder[color];
    SetConsoleTextAttribute(out, colorCode);
}

void ConsoleTools::ResetColor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(out, 7);
}

void ConsoleTools::SetCursor(UINT x, UINT y)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cord;
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(out, cord);
}

void ConsoleTools::DrawBlock(UINT x, UINT y, UINT size, Colors color)
{
    SetColor(color);
    for (UINT i = 0; i < size; i++)
    {
        SetCursor(x, y);
        for (UINT j = 0; j < 2*size; j++)
        {
            std::cout << char(219);
        }
        y++;
    }
    ResetColor();
    
}
