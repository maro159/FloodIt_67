#include <iostream>
#include <conio.h>
#include "ConsoleGUI.h"

using namespace std;

map<Colors, int> colorDecoder
{
    { Colors::Green, 2 },
    { Colors::Aqua, 3 },
    { Colors::Red, 4 },
    { Colors::Purple, 5 },
    { Colors::Yellow, 6 },
    { Colors::White, 15 },
    { Colors::Default, 7 }
};


ConsoleGUI::ConsoleGUI(unsigned int blockSize, unsigned int gridXPos, unsigned int gridYPos, unsigned int fontSize) :
    _blockYSize(blockSize), _blockXSize(2 * blockSize), _gridXPos(gridXPos), _gridYPos(gridYPos)  // blockXSize multiplied by 2 because of console char ratio is 2:1
{
    showConsoleCursor(false);
    maximizeWindows();
    setFontSize(fontSize);
}

ConsoleGUI::~ConsoleGUI()
{

    consoleClear();
    setFontSize(16);
    showConsoleCursor(true);
    system("pause");
}

void ConsoleGUI::consoleClear()
{
    system("cls");
}

int ConsoleGUI::getUserInput(string text, string errorText, int min, int max)
{
    int input;
    bool firstTime = true;
    while (true)
    {
        consoleClear();
        if (!firstTime)
        {
            cout << errorText << endl;
            firstTime = true;
        }
        cout << text;

        if (cin >> input && input >= min && input <= max) { return input; }
        else
        {
            cin.clear();
            cin.ignore();
        }
    }
}


void ConsoleGUI::setFontSize(unsigned int size)
{
    // Get the console handle
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // Get the current console font information
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    GetCurrentConsoleFontEx(hConsole, false, &cfi);
    // Change the font size to (x,y)
    //cfi.dwFontSize.X = x;
    cfi.dwFontSize.Y = 36;
    //wcscpy_s(cfi.FaceName, L"Terminal");

    // Set the new console font
    SetCurrentConsoleFontEx(hConsole, false, &cfi);
}

void ConsoleGUI::setColor(Colors color)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    int colorCode = colorDecoder[color];
    SetConsoleTextAttribute(out, colorCode);
}

void ConsoleGUI::maximizeWindows()
{
    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOWMAXIMIZED);
}

void ConsoleGUI::setCursor(unsigned int x, unsigned int y)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cord;
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(out, cord);
}

void ConsoleGUI::showConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void ConsoleGUI::drawBlock(unsigned int x, unsigned int y, Colors color)
{
    setColor(color);
    for (unsigned int i = 0; i < _blockYSize; i++)
    {
        setCursor(x,y+i);
        for (unsigned int x = 0; x < _blockXSize; x++)
        {
            cout << char(219);
        }
    }
    setColor(Colors::Default); 
}

void ConsoleGUI::drawFloodMenu(unsigned int xPos, unsigned int yPos, unsigned int noOfColors, unsigned int selectedColor)
{
    for (size_t i = 0; i < noOfColors; i++)
    {
        Colors color = static_cast<Colors>(i);
        drawBlock(xPos, yPos+ i * _blockYSize, color);
        setCursor(xPos + _blockXSize, yPos + i * _blockYSize + _blockYSize / 2);
        if (i == selectedColor) { cout << "<--"; }
        else { cout << "   "; }
    }
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
                // calculate x coord of block to be drawn
                unsigned int blockXPos = _gridXPos + col * _blockXSize;
                // calculate y coord of block to be drawn
                unsigned int blockYPos = _gridYPos + row * _blockYSize;
                drawBlock(blockXPos, blockYPos, block->getColor());
            }
        }
    }
}


Colors ConsoleGUI::selectFloodColor(Grid& grid)
{
    unsigned int selectedColorNo = (int)grid.getCurrentColor();
    unsigned int noOfColors = grid.getNoOfColors();
    unsigned int xPos = _gridXPos + _blockXSize * (grid.getColSize() + 2); // TODO: some const value instead of 2 maybe
    unsigned int yPos = _gridYPos;
    drawFloodMenu(xPos, yPos, noOfColors, selectedColorNo);
    int key = 0;
    const int UP = 0;
    const int DOWN = 0;
    

    while (true)
    {
        key = _getch();
        if (key && key == Keys::ENTER)
        {
            return static_cast<Colors>(selectedColorNo);
        }
        else if (key && key == 224)
        {
            key = _getch();
            if (key == Keys::UP && selectedColorNo > 0)
            {
                selectedColorNo--;
            }
            else if (key == Keys::DOWN && selectedColorNo + 1 < noOfColors)
            {
                selectedColorNo++;
            }
            drawFloodMenu(xPos, yPos, noOfColors, selectedColorNo);
        }

    }
    return Colors();
}

void ConsoleGUI::printResult(Grid& grid)
{
    bool win = grid.isDone();
    setCursor(_gridXPos, _gridYPos + grid.getRowSize() * _blockYSize + 1);
    if (win) { cout << "YOU WON !!!" << endl;; }
    else { cout << "YOU LOSE !!!" << endl; }
    cout << "*Press ENTER or ESC to continue*" << endl;
}

void ConsoleGUI::printMoveStat(Grid& grid)
{
    setCursor(_gridXPos, _gridYPos + grid.getRowSize() * _blockYSize);
    cout << "MOVES:\t" << grid.getMoves() << " / " << grid.getMaxMoves();
}
