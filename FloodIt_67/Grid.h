#pragma once
#include <vector>
#include <map>
#include "Helpers.h"
#include "Block.h"

class Grid
{
private:
	// number of rows in grid
	unsigned int _rowSize;
	// number of columns in grid
	unsigned int _colSize;
	// number of all colors used
	unsigned int _noOfColors;
	// vector of all Block objects which belong to the Grid
	std::vector<std::vector<Block>> _blocks;
	// map with number of Block objects of each color
	std::map<Colors, unsigned int> _colorCounter;

public:
	Grid(unsigned int rowSize, unsigned int colSize, unsigned int noOfColors);

	// returns number of rows in grid
	unsigned int getRowSize() const;
	// returns number of columns in grid
	unsigned int getColSize() const;
	// returns number of used colors
	unsigned int getNoOfColors() const;
	// change color by flooding from upper-left block
	void flood(Colors color);
	// update counters of coresponding colors
	void updateColorCounter(Colors oldColor, Colors newColor);
	// true if player wins
	bool isWin() const;
	// returns a reference to 2D array of blocks in grid
	std::vector<std::vector<Block>>& getBlocks();
};