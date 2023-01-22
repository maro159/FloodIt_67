#include <ostream>
#include "Block.h"


using namespace std;


Block::Block(Colors color, Grid *gridOwner) : _color(color), _gridOwner(gridOwner), _changed(true) {}

Colors Block::getColor() const { return _color; }
bool Block::isChanged() const { return _changed; }

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

		// Change color of adjacents
		for (Block* blockPtr : _adjacents)
		{
			blockPtr->switchColor(newColor);
		}
	}
}

void Block::addAdjacent(Block* blockPtr)
{
	_adjacents.push_back(blockPtr);
}