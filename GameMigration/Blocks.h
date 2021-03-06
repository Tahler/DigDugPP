#ifndef BLOCKS_H
#define BLOCKS_H
	
#include "Physics.h"

using Physics::Rectangle;
using Physics::Point;
using Physics::Vector;

extern const int BLOCK_SIZE;
const int BLOCK_FIFTH = BLOCK_SIZE/5;
const int BLOCK_SIXTH = (BLOCK_SIZE/6);
const int BLOCK_HALF = (BLOCK_SIZE/2);

namespace Blocks
{
	struct Block:Rectangle
	{
		//Base block
		bool isTraversable;

		Block() {}
		Block(Point a, bool isTraversable) : // block is based on grid coordinates
			Rectangle(Point(a.x * BLOCK_SIZE, a.y * BLOCK_SIZE), Point(a.x * BLOCK_SIZE + BLOCK_SIZE, a.y * BLOCK_SIZE + BLOCK_SIZE)), // point in rectangle is pixel coordinates
			isTraversable(isTraversable)
		{}
		virtual ~Block() {}
	};
	struct StoreLeft:Block
	{
		StoreLeft(Point a) :
			Block(a, false)
		{}
		void drawAt(Core::Graphics&, Vector&);
	};
	struct StoreRight:Block
	{
		StoreRight(Point a) :
			Block(a, false)
		{}
		void drawAt(Core::Graphics&, Vector&);
	};
	struct Sky:Block
	{
		Sky(Point a) : 
			Block(a, true)
		{}
		void drawAt(Core::Graphics&, Vector&);
	};
	struct UnbreakableGrass:Block
	{
		UnbreakableGrass(Point a) : 
			Block(a, false)
		{}
		void drawAt(Core::Graphics&, Vector&);
	};
	struct Cave:Block
	{
		Cave(Point a) :
			Block(a, true)
		{}
		void drawAt(Core::Graphics&, Vector&);
	};
	
	struct Ladder:Block
	{
		Ladder(Point a) : 
			Block(a, true)
		{}
		void drawAt(Core::Graphics&, Vector&);
	};

	struct BreakableBlock:Block
	{
		//Can break
		int durability;
		int hardness;
		BreakableBlock(Point a) :
			Block(a, false)
		{
			durability = 100;
			hardness = 1;
		}
		int takeDamage(int damage);
		void drawCracks(Core::Graphics&, Vector& p, int durability);
	};

	struct Dirt:BreakableBlock
	{
		//No value, disappears
		Dirt(Point a) :
			BreakableBlock(a)
		{}

		void drawAt(Core::Graphics&, Vector&);
	};

	struct Stone:BreakableBlock
	{
		//No value, disappears
		Stone(Point a) :
			BreakableBlock(a)
		{}

		void drawAt(Core::Graphics&, Vector&);
	};

	struct Grass:BreakableBlock
	{
		//No value, disappears
		Grass(Point a) :
			BreakableBlock(a)
		{}
		void drawAt(Core::Graphics&, Vector&);
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
		
		void drawAt(Core::Graphics&, Vector&);
	};

	struct Iron:OreBlock
	{
		Iron(Point a) :
			OreBlock(a)
		{
			value = 2;
		};
		
		void drawAt(Core::Graphics&, Vector&);
	};

	struct Silver:OreBlock
	{
		Silver(Point a) :
			OreBlock(a)
		{
			value = 3;
			hardness = 2;
		};

		void drawAt(Core::Graphics&, Vector&);
	};

	struct Sapphire:OreBlock
	{
		Sapphire(Point a) :
			OreBlock(a)
		{
			value = 4;
			hardness = 3;
		}

		void drawAt(Core::Graphics&, Vector&);
	};
	
	struct Ruby:OreBlock
	{
		Ruby(Point a) :
			OreBlock(a)
		{
			value = 5;
			hardness = 3;
		}

		void drawAt(Core::Graphics&, Vector&);
	};

	struct Emerald:OreBlock
	{
		Emerald(Point a) :
			OreBlock(a)
		{
			value = 6;
			hardness = 4;
		}

		void drawAt(Core::Graphics&, Vector&);
	};

	struct Gold:OreBlock
	{
		Gold(Point a) :
			OreBlock(a)
		{
			value = 7;
			hardness = 4;
		}

		void drawAt(Core::Graphics&, Vector&);
	};

	struct Diamond:OreBlock
	{
		Diamond(Point a) :
			OreBlock(a)
		{
			value = 8;
			hardness = 5;
		}

		void drawAt(Core::Graphics&, Vector&);
	};
}
#endif