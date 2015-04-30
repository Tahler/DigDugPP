#ifndef BLOCKS_H
#define BLOCKS_H
	
#include "Physics.h"
#include "Fill.h"

using Physics::Rectangle;
using Physics::Point;

extern const int BLOCK_SIZE;
const int BLOCK_FIFTH = BLOCK_SIZE/5;

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
		void draw(Core::Graphics& g);
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
		void draw(Core::Graphics& g);
	};

	struct OreBlock:BreakableBlock
	{
		//Has value, goes to inv
		int value;
		OreBlock(Point a) :
			BreakableBlock(a)
		{}
	};

	struct Copper:OreBlock
	{
		
		Copper(Point a) :
			OreBlock(a)
		{
			value = 1;
		};
		
		void draw(Core::Graphics& g);
	};

	struct Iron:OreBlock
	{
	
		Iron(Point a) :
			OreBlock(a)
		{
			value = 2;
		};
		
		void draw(Core::Graphics& g);
	};

	struct Silver:OreBlock
	{
		
		Silver(Point a) :
			OreBlock(a)
		{
			value = 3;
		};
		
		void draw(Core::Graphics& g);
	};

}
#endif