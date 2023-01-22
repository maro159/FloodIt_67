#include <ostream>
#include "Block.h"
#include "Grid.h"

using namespace std;


Block::Block(Colors color, Grid *gridOwner) : _color(color), _gridOwner(gridOwner), _changed(true) {}

Colors Block::getColor() const { return _color; }
bool Block::isChanged()
{
	return _changed;
	_changed = false;
}

void Block::switchColor(Colors newColor)
{
	if (newColor == _color) return;
	else
	{
		Colors oldColor = _color;
		_color = newColor;
		_changed = true;

		// Update color counters
		_gridOwner->updateColorCounter(oldColor, newColor);

		// Change color of adjacents if they had the same color
		for (auto& blockPtr : _adjacents)
		{
			if (blockPtr->getColor() == oldColor)
			{
				blockPtr->switchColor(newColor);
			}
		}
	}
}



void Block::addAdjacent(shared_ptr<Block> blockPtr)
{
	_adjacents.push_back(blockPtr);
}