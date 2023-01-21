#pragma once
#include "Helpers.h"
#include <vector>
#include <ostream>

class Block
{
private:
	Colors _color;
	std::vector<Block*> _adjacents;
	bool _changed;

public:
	Block(Colors color);
	void switchColor(Colors newColor);
	void addAdjacent(Block* block);
};