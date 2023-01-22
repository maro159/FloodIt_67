#include "Grid.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Grid::Grid(unsigned int rowSize, unsigned int colSize, unsigned int noOfColors) : _rowSize(rowSize), _colSize(colSize), _noOfColors(noOfColors)
{
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
			unsigned int randomNumber = rand() % (_noOfColors + 1);
			Colors randomColor = static_cast<Colors>(randomNumber);
			// add block to row
			tmp.push_back(make_shared<Block>(randomColor, this));
			// update color counter
			_colorCounter[randomColor]++;
		}
		// add row to matrix of blocks
		_blocks.push_back(tmp);
	}

	// assign each block its adjacents blocks
	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = 0; col < colSize; col++)
		{
			// block on the right
			if (row + 1 < rowSize) 
			{
				_blocks[row][col]->addAdjacent(_blocks[row + 1][col]);
			}
			// block on the left
			if (row - 1 >= 0) 
			{
				_blocks[row][col]->addAdjacent(_blocks[row - 1][col]);
			}
			// block above
			if (col + 1 < colSize) 
			{
				_blocks[row][col]->addAdjacent(_blocks[row][col + 1]);
			}
			// block below
			if (col - 1 >= 0) {
				_blocks[row][col]->addAdjacent(_blocks[row][col - 1]);
			}
		}
	}

}

unsigned int Grid::getRowSize() const { return _rowSize; }
unsigned int Grid::getColSize() const { return _colSize; }
unsigned int Grid::getNoOfColors() const { return _noOfColors; }
vector<vector<shared_ptr<Block>>> Grid::getBlocks() { return _blocks; }

void Grid::flood(Colors color)
{
	_blocks[0][0]->switchColor(color);
}

void Grid::updateColorCounter(Colors oldColor, Colors newColor)
{
	_colorCounter[oldColor]--;
	_colorCounter[newColor]++;
}

bool Grid::isWin() const
{
	for (const auto& colorCount : _colorCounter)
	{
		if (colorCount.second == _rowSize * _colSize) return true;
	}
	return false;
}


