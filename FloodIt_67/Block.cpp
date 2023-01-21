#include <ostream>
#include "Block.h"
using namespace std;


Block::Block(Colors color) : _color(color), _changed(true) {}

void Block::switchColor(Colors newColor)
{
	if (newColor == _color) return;
	else
	{
		Colors oldColor = _color;
		_color = newColor;
		_changed = true;

		// TODO: Update color counters

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


ostream& operator<<(ostream& out, const Block& rhs)
{
	out << "";
	return out;
}