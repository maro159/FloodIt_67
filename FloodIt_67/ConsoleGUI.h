#pragma once
#include <windows.h>
#include <map>
#include "Helpers.h"
#include "Grid.h"


class ConsoleGUI
{
private:
    // dimension of single block in console lines
    unsigned int _blockSize;
    // x coord of grid to be drawn
    unsigned int _gridXPos;
    // y coord of grid to be drawn
    unsigned int _gridYPos;
    // changes color of console font
    void setColor(Colors color);
    // change position of carriage to specified coordinates
    void setCursor(unsigned int x, unsigned int y);
    // draws block at specified coordinates with size and color defined
    void drawBlock(unsigned int x, unsigned int y, Colors color);

public:
    ConsoleGUI(unsigned int blockSize, unsigned int gridXPos, unsigned int gridYPos);

    // draw every block in the grid that has been changed
    void redrawGrid(Grid& grid);
    
};