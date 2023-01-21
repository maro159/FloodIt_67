#include "Grid.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Grid::Grid(unsigned int rowSize, unsigned int colSize, unsigned int noOfColors) : _rowSize(rowSize), _colSize(colSize), _noOfColors(noOfColors)
{
	// create 2D array of blocks
	for (size_t row = 0; row < rowSize; row++)
	{
		vector<Block> tmp;
		for (size_t col = 0; col < colSize; col++)
		{
			// get random color
			unsigned int randomNumber = rand() % (_noOfColors + 1);
			Colors randomColor = static_cast<Colors>(randomNumber);
			// add block to row
			tmp.emplace_back(Block(randomColor));
		}
		// add row to matrix of blocks
		_blocks.emplace_back(tmp);
	}

	// assign each block its adjacents blocks
	for (size_t row = 0; row < rowSize; row++)
	{
		for (size_t col = 0; col < colSize; col++)
		{
			// block on the right
			if (row + 1 < rowSize) 
			{
				_blocks[row][col].addAdjacent(&_blocks[row + 1][col]);
			}
			// block on the left
			if (row - 1 >= 0) 
			{
				_blocks[row][col].addAdjacent(&_blocks[row - 1][col]);
			}
			// block above
			if (col + 1 < colSize) 
			{
				_blocks[row][col].addAdjacent(&_blocks[row][col + 1]);
			}
			// block below
			if (col - 1 >= 0) {
				_blocks[row][col].addAdjacent(&_blocks[row][col - 1]);
			}
		}
	}

}

void Grid::Flood(Colors color)
{
	_blocks[0][0].switchColor(color);
}
