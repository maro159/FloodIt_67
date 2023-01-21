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
	void switchColor(Colors newColor);
	friend std::ostream& operator<<(std::ostream& os, const Block& rhs);
};

std::ostream& operator<<(std::ostream& os, const Block& rhs);