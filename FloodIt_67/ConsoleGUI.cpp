#include <iostream>
#include "ConsoleGUI.h"

std::map<Colors, int> colorDecoder
{
    { Colors::Green, 2 },
    { Colors::Aqua, 3 },
    { Colors::Red, 4 },
    { Colors::Purple, 5 },
    { Colors::Yellow, 6 },
    { Colors::White, 15 },
};


//void ConsoleGUI::SetFontSize(SHORT x, SHORT y)
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

void ConsoleGUI::setColor(Colors color)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorCode = colorDecoder[color];
    SetConsoleTextAttribute(out, colorCode);
}

void ConsoleGUI::resetColor()
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(out, 7);
}

void ConsoleGUI::setCursor(unsigned int x, unsigned int y)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cord;
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(out, cord);
}

void ConsoleGUI::drawBlock(unsigned int x, unsigned int y, unsigned int size, Colors color)
{
    setColor(color);
    for (unsigned int i = 0; i < size; i++)
    {
        setCursor(x, y);
        for (unsigned int j = 0; j < 2*size; j++)
        {
            std::cout << char(219);
        }
        y++;
    }
    resetColor();
}
