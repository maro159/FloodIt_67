#pragma once
#include <vector>
#include "Block.h"

class Grid
{
private:
	unsigned int _xPos;
	unsigned int _yPos;
	unsigned int _blockSize;
	unsigned int _xSize;
	unsigned int _ySize;
	std::vector<std::vector<Block>> _blocks;
	std::vector<unsigned int> _colorCounter;


public:

	//Grid(unsigned int xStart, unsigned int yStart, unsigned int blockSize, unsigned int xBlocks, unsigned int yBlocks) :
	//	_xStart(xStart), _yStart(yStart), _blockSize(blockSize), _xBlocks(xBlocks), _yBlocks(yBlocks) {}

};