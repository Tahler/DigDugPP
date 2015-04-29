#ifndef BLOCKS_H
#define BLOCKS_H
	
#include "Physics.h"

using Physics::Rectangle;
using Physics::Vector;

namespace Blocks
{
	struct Block:Rectangle
	{
		//Base block
		Block(Vector a, Vector b) :
			Rectangle(a, b)
		{}
	};

	struct Stone:Block
	{
		//Has gravity
		Stone(Vector a, Vector b) :
			Block(a,b)
		{}
	};

	struct BreakableBlock:Block
	{
		//Can break
		int durability;
		BreakableBlock(Vector a, Vector b) :
			Block(a,b)
		{
			durability = 100;
		}
	};

	struct Earth:BreakableBlock
	{
		//No value, disappears
		Earth(Vector a, Vector b) :
			BreakableBlock(a, b)
		{}
	};

	struct OreBlock:BreakableBlock
	{
		//Has value, goes to inv
		OreBlock(Vector a, Vector b) :
			BreakableBlock(a, b)
		{}
	};

}
#endif