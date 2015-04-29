#ifndef BLOCKS_H
#define BLOCKS_H
	
#include "Physics.h"

using Physics::Rectangle;
using Physics::Point;

namespace Blocks
{
	struct Block:Rectangle
	{
		//Base block
		Block(Point a, Point b) :
			Rectangle(a, b)
		{}
	};

	struct Stone:Block
	{
		//Has gravity
		Stone(Point a, Point b) :
			Block(a,b)
		{}
	};

	struct BreakableBlock:Block
	{
		//Can break
		int durability;
		BreakableBlock(Point a, Point b) :
			Block(a,b)
		{
			durability = 100;
		}
	};

	struct Earth:BreakableBlock
	{
		//No value, disappears
		Earth(Point a, Point b) :
			BreakableBlock(a, b)
		{}
	};

	struct OreBlock:BreakableBlock
	{
		//Has value, goes to inv
		OreBlock(Point a, Point b) :
			BreakableBlock(a, b)
		{}
	};

}
#endif