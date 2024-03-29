#include "Grid.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

Grid::Grid(unsigned int rowSize, unsigned int colSize, unsigned int noOfColors) : _rowSize(rowSize), _colSize(colSize), _noOfColors(noOfColors), _moves(0)
{
	_maxMoves = static_cast<int>(floor(26 * (rowSize + colSize) * noOfColors / ((14 + 14) * 6))); // TODO: calculate max moves

	// create counters for all colors
	for (size_t i = 0; i < noOfColors; i++)
	{
		Colors color = static_cast<Colors>(i);
		_colorCounter[color] = 0;
	}


	// create 2D array of blocks
	for (size_t row = 0; row < rowSize; row++)
	{
		vector<shared_ptr<Block>> tmp;
		for (size_t col = 0; col < colSize; col++)
		{
			// get random color
			unsigned int randomNumber = rand() % (_noOfColors);
			Colors randomColor = static_cast<Colors>(randomNumber);
			// add block to row
			tmp.push_back(make_shared<Block>(randomColor, this));
			// update color counter
			_colorCounter[randomColor]++;
		}
		// add row to matrix of blocks
		_blocks.push_back(tmp);
	}

	// set color of upper left block as current grid color
	_currentColor = _blocks[0][0]->getColor();

	// assign each block its adjacents blocks
	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = 0; col < colSize; col++)
		{
			// block below
			if (row + 1 < rowSize) 
			{
				_blocks[row][col]->addAdjacent(_blocks[row + 1][col]);
			}
			// block above
			if (row > 0) 
			{
				_blocks[row][col]->addAdjacent(_blocks[row - 1][col]);
			}
			// block on the right
			if (col + 1 < colSize) 
			{
				_blocks[row][col]->addAdjacent(_blocks[row][col + 1]);
			}
			// block on the left
			if (col > 0) {
				_blocks[row][col]->addAdjacent(_blocks[row][col - 1]);
			}
		}
	}

}

unsigned int Grid::getMoves() const { return _moves; }
unsigned int Grid::getMaxMoves() const { return _maxMoves; }
Colors Grid::getCurrentColor() const { return _currentColor; }
unsigned int Grid::getRowSize() const { return _rowSize; }
unsigned int Grid::getColSize() const { return _colSize; }
unsigned int Grid::getNoOfColors() const { return _noOfColors; }
vector<vector<shared_ptr<Block>>> Grid::getBlocks() { return _blocks; }

void Grid::flood(Colors color)
{
	if (color != _currentColor)
	{
		_blocks[0][0]->switchColor(color);
		_currentColor = color;
		_moves++;
	}
}

void Grid::updateColorCounter(Colors oldColor, Colors newColor)
{
	_colorCounter[oldColor]--;
	_colorCounter[newColor]++;
}

bool Grid::isOneColor() const
{
	for (const auto& colorCount : _colorCounter)
	{
		if (colorCount.second == _rowSize * _colSize) return true;
	}
	return false;
}




