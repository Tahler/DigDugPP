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
		virtual void draw(Core::Graphics& g) 
		{
			fillSquare(g, a, BLOCK_SIZE);
		}
		void setLocation(Point);
	};

	struct Stone:Block
	{
		//Has gravity
		Stone(Point a) :
			Block(a)
		{}
		virtual void draw(Core::Graphics& g) 
		{
			g.SetColor(RGB(121,122,122));
			fillSquare(g, a, BLOCK_SIZE);
			g.SetColor(RGB(102,102,102));
			fillSquare(g, Point(a.x + BLOCK_FIFTH, a.y + 2 * BLOCK_FIFTH), BLOCK_FIFTH * 2);
			g.SetColor(RGB(110, 110, 100));
			fillSquare(g, Point(a.x + 2* BLOCK_FIFTH, a.y + BLOCK_FIFTH), BLOCK_FIFTH * 2);
		}
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
		virtual void draw(Core::Graphics& g) 
		{
			g.SetColor(RGB(110,83,9));
			fillSquare(g, a, BLOCK_SIZE);
		}
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
		
		virtual void draw(Core::Graphics& g)
		{
			g.SetColor(RGB(121,122,122));
			fillSquare(g, a, BLOCK_SIZE);
			g.SetColor(RGB(245, 151, 29));
			fillSquare(g, Point(a.x + BLOCK_FIFTH, a.y + BLOCK_FIFTH), BLOCK_FIFTH);
			fillSquare(g, Point(a.x + 3 * BLOCK_FIFTH, a.y + 2 * BLOCK_FIFTH), BLOCK_FIFTH);
			fillSquare(g, Point(a.x + BLOCK_FIFTH, a.y +  3* BLOCK_FIFTH), BLOCK_FIFTH);
		}
	};

	struct Iron:OreBlock
	{
	
		Iron(Point a) :
			OreBlock(a)
		{
			value = 2;
		};
		
		virtual void draw(Core::Graphics& g)
		{
			g.SetColor(RGB(121,122,122));
			fillSquare(g, a, BLOCK_SIZE);
			g.SetColor(RGB(199, 174, 141));
			fillRectangle(g, Point(a.x + BLOCK_FIFTH, a.y + BLOCK_FIFTH), 2*BLOCK_FIFTH, BLOCK_FIFTH);
			fillSquare(g, Point(a.x + 3* BLOCK_FIFTH, a.y + 2 * BLOCK_FIFTH), BLOCK_FIFTH);
			fillSquare(g, Point(a.x + 2* BLOCK_FIFTH, a.y + 3 * BLOCK_FIFTH), BLOCK_FIFTH);
		}
	};

	struct Silver:OreBlock
	{
		
		Silver(Point a) :
			OreBlock(a)
		{
			value = 3;
		};
		
		virtual void draw(Core::Graphics& g)
		{
			g.SetColor(RGB(121,122,122));
			fillSquare(g, a, BLOCK_SIZE);
			g.SetColor(RGB(207, 207, 207));
			fillRectangle(g, Point(a.x + BLOCK_FIFTH, a.y + BLOCK_FIFTH), 2*BLOCK_FIFTH, BLOCK_FIFTH);
			fillSquare(g, Point(a.x + 2* BLOCK_FIFTH, a.y + 2 * BLOCK_FIFTH), BLOCK_FIFTH);
			fillSquare(g, Point(a.x + 3* BLOCK_FIFTH, a.y + 3 * BLOCK_FIFTH), BLOCK_FIFTH);
		}
	};

}
#endif