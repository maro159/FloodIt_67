#pragma once
#include <vector>
#include <map>
#include "Helpers.h"
#include "Block.h"

class Grid
{
private:
	unsigned int _rowSize;
	unsigned int _colSize;
	unsigned int _noOfColors;
	std::vector<std::vector<Block>> _blocks;
	std::map<Colors, unsigned int> _colorCounter;

public:
	Grid(unsigned int xSize, unsigned int ySize, unsigned int noOfColors);
	void Flood(Colors color);

};