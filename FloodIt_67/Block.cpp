#include <ostream>
#include "Block.h"
using namespace std;



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


ostream& operator<<(ostream& out, const Block& rhs)
{
	out << "";
	return out;
}