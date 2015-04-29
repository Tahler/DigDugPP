#ifndef BLOCKS_H
#define BLOCKS_H
	
#include "Physics.h"

using Physics::Rectangle;
using Physics::Point;

extern const int BLOCK_SIZE; 

namespace Blocks
{
	struct Block:Rectangle
	{
		//Base block
		Block() {}
		Block(Point a) :
			Rectangle(a, Point(a.x + BLOCK_SIZE, a.y + BLOCK_SIZE))
		{}
		void setLocation(Point);
	};

	struct Stone:Block
	{
		//Has gravity
		Stone(Point a) :
			Block(a)
		{}
	};

	struct BreakableBlock:Block
	{
		//Can break
		int durability;
		BreakableBlock(Point a) :
			Block(a)
		{
			durability = 100;
		}
	};

	struct Earth:BreakableBlock
	{
		//No value, disappears
		Earth(Point a) :
			BreakableBlock(a)
		{}
	};

	struct OreBlock:BreakableBlock
	{
		//Has value, goes to inv
		OreBlock(Point a) :
			BreakableBlock(a)
		{}
	};

}
#endif