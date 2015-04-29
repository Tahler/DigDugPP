
#include "Blocks.h"
using namespace Blocks;

// Block //
Block::Block()
{

}
void Block::setLocation(Point pa)
{
	setPoints(pa, Point(pa.x + BLOCK_WIDTH, pa.y + BLOCK_WIDTH));
}