#include <iostream>
#include "ConsoleGUI.h"
using namespace std;

std::map<Colors, int> colorDecoder
{
    { Colors::Green, 2 },
    { Colors::Aqua, 3 },
    { Colors::Red, 4 },
    { Colors::Purple, 5 },
    { Colors::Yellow, 6 },
    { Colors::White, 15 },
    { Colors::Default, 7 }
};

ConsoleGUI::ConsoleGUI(unsigned int blockSize, unsigned int gridXPos, unsigned int gridYPos) :
    _blockSize(blockSize), _gridXPos(gridXPos), _gridYPos(gridYPos) {}


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

void ConsoleGUI::setCursor(unsigned int x, unsigned int y)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cord{};
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(out, cord);
}

void ConsoleGUI::drawBlock(unsigned int x, unsigned int y, Colors color)
{
    setColor(color);
    for (unsigned int y = 0; y < _blockSize; y++)
    {
        setCursor(x, y);
        for (unsigned int x = 0; x < 2* _blockSize; x++)
        {
            std::cout << char(219);
        }
        y++;    // next row
    }
    setColor(Colors::Default); 
}


void ConsoleGUI::redrawGrid(Grid& grid)
{
    auto rowSize = grid.getRowSize();
    auto colSize = grid.getColSize();

    for (unsigned int row = 0; row < rowSize; row++)
    {
        for (unsigned int col = 0; col < colSize; col++)
        {
            shared_ptr<Block> block = grid.getBlocks()[row][col];
            if (block->isChanged())
            {
                // calculate x coord of block to be drawn (needs to be multiplied by 2 because of console char ratio is 2:1)
                unsigned int blockXPos = _gridXPos + 2 * col * _blockSize;
                // calculate y coord of block to be drawn
                unsigned int blockYPos = _gridYPos + row * _blockSize;
                drawBlock(blockXPos, blockYPos, block->getColor());
            }
        }
    }
}
