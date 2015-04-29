
#include "Blocks.h"
using namespace Blocks;

// Block //
void Block::setLocation(Point pa)
{
	setPoints(pa, Point(pa.x + BLOCK_SIZE, pa.y + BLOCK_SIZE));
}