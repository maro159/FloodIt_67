#pragma once
#include <windows.h>
#include <map>
#include "Helpers.h"
#include "Grid.h"


class ConsoleGUI
{
private:
    // x dimension of single block in console lines
    unsigned int _blockXSize;
    // y dimension of single block in console lines
    unsigned int _blockYSize;
    // x coord of grid to be drawn
    unsigned int _gridXPos;
    // y coord of grid to be drawn
    unsigned int _gridYPos;
    // change color of console font
    void setColor(Colors color);
    // change position of carriage to specified coordinates
    void setCursor(unsigned int x, unsigned int y);
    // draws block at specified coordinates with size and color defined
    void drawBlock(unsigned int x, unsigned int y, Colors color);
    // draws menu used to choose flood color
    void drawFloodMenu(unsigned int xPos, unsigned int yPos, unsigned int noOfColors, unsigned int chosenColor);
    void maximizeWindows();

public:
    ConsoleGUI(unsigned int blockSize, unsigned int gridXPos, unsigned int gridYPos, unsigned int fontSize);
    ~ConsoleGUI();
    void setFontSize(unsigned int size);
    void consoleClear();
    void showConsoleCursor(bool showFlag);
    // ask user for input, retry if failed to parse int or value outside min-max
    int getUserInput(std::string text, std::string errorText, int min, int max);
    // creates menu for user to select flood color
    Colors selectFloodColor(Grid& grid);
    // draw every block in the grid that has been changed
    void redrawGrid(Grid& grid);
    // tell user if he won or lose
    void printResult(Grid& grid);
    // show moves done/max
    void printMoveStat(Grid& grid);
};