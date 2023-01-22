#pragma once
#include <vector>
#include <ostream>
#include "Helpers.h"


class Grid;

class Block
{
private:
	// pointer to grid which the block belongs to
	Grid *_gridOwner;
	// color of the block
	Colors _color;
	// vector of pointers to Block objects which are adjacent to this
	std::vector<std::shared_ptr<Block>> _adjacents;
	// true if color the block has changed
	bool _changed;


public:
	Block(Colors color, Grid *gridOwner);
	// returns color of Block
	Colors getColor() const;
	// returns true if color of block has changed and needs to be redrawn
	bool isChanged() const;
	// recursively changes color of the block and adjacent ones
	void switchColor(Colors newColor);
	// add block to list of adjacent ones by pointer
	void addAdjacent(std::shared_ptr<Block> block);

};