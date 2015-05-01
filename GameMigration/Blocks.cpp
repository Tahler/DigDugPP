
#include "Blocks.h"
using namespace Blocks;

// Measured in pixels
const int BLOCK_SIZE = 50;

// Block //
void Block::setLocation(Point& pa)
{
	setPoints(pa, Point(pa.x + BLOCK_SIZE, pa.y + BLOCK_SIZE));
}

//Draw functions for each block
void Sky::draw(Core::Graphics& g)
{
	g.SetColor(RGB(120, 207, 227));
	fillSquare(g, a, BLOCK_SIZE);
}
void Cave::draw(Core::Graphics& g)
{
	g.SetColor(RGB(41, 24, 2));
	fillSquare(g, a, BLOCK_SIZE);
}
void Ladder::draw(Core::Graphics& g)
{
	g.SetColor(RGB(41, 24, 2));
	fillSquare(g, a, BLOCK_SIZE);
	g.SetColor(RGB(204, 151, 6));
	//Rails
	fillRectangle(g, Point(a.x + BLOCK_FIFTH, a.y), BLOCK_FIFTH, BLOCK_SIZE);
	fillRectangle(g, Point(a.x + 3*BLOCK_FIFTH, a.y), BLOCK_FIFTH, BLOCK_SIZE);
	//Rungs
	fillRectangle(g, Point(a.x + 2*BLOCK_FIFTH, a.y + BLOCK_SIXTH), BLOCK_FIFTH, BLOCK_SIXTH);
	fillRectangle(g, Point(a.x + 2*BLOCK_FIFTH, a.y + 3*BLOCK_SIXTH), BLOCK_FIFTH, BLOCK_SIXTH);
	fillRectangle(g, Point(a.x + 2*BLOCK_FIFTH, a.y + 5*BLOCK_SIXTH), BLOCK_FIFTH, BLOCK_SIXTH);
}
void Stone::draw(Core::Graphics &g)
{
	g.SetColor(RGB(121,122,122));
			fillSquare(g, a, BLOCK_SIZE);
			g.SetColor(RGB(102,102,102));
			fillSquare(g, Point(a.x + BLOCK_FIFTH, a.y + 2 * BLOCK_FIFTH), BLOCK_FIFTH * 2);
			g.SetColor(RGB(110, 110, 100));
			fillSquare(g, Point(a.x + 2* BLOCK_FIFTH, a.y + BLOCK_FIFTH), BLOCK_FIFTH * 2);
}
void Earth::draw(Core::Graphics &g)
{
	g.SetColor(RGB(110,83,9));
	fillSquare(g, a, BLOCK_SIZE);
}
void Earth2::draw(Core::Graphics &g)
{
	g.SetColor(RGB(121, 122, 122));
	fillSquare(g, a, BLOCK_SIZE);
}
void Grass::draw(Core::Graphics &g)
{
	g.SetColor(RGB(110,83,9));
	fillSquare(g, a, BLOCK_SIZE);
	g.SetColor(RGB(20, 219, 2));
	fillRectangle(g, a, BLOCK_SIZE, BLOCK_FIFTH);
}
void Iron::draw(Core::Graphics &g)
{
	g.SetColor(RGB(121,122,122));
			fillSquare(g, a, BLOCK_SIZE);
			g.SetColor(RGB(199, 174, 141));
			fillRectangle(g, Point(a.x + BLOCK_FIFTH, a.y + BLOCK_FIFTH), 2*BLOCK_FIFTH, BLOCK_FIFTH);
			fillSquare(g, Point(a.x + 3*BLOCK_FIFTH, a.y + 2*BLOCK_FIFTH), BLOCK_FIFTH);
			fillSquare(g, Point(a.x + 2*BLOCK_FIFTH, a.y + 3 * BLOCK_FIFTH), BLOCK_FIFTH);			
}
void Silver::draw(Core::Graphics &g)
{
	g.SetColor(RGB(121,122,122));
			fillSquare(g, a, BLOCK_SIZE);
			g.SetColor(RGB(207, 207, 207));
			fillRectangle(g, Point(a.x + BLOCK_FIFTH, a.y + BLOCK_FIFTH), 2*BLOCK_FIFTH, BLOCK_FIFTH);
			fillSquare(g, Point(a.x + 2* BLOCK_FIFTH, a.y + 2 * BLOCK_FIFTH), BLOCK_FIFTH);
			fillSquare(g, Point(a.x + 3* BLOCK_FIFTH, a.y + 3 * BLOCK_FIFTH), BLOCK_FIFTH);
}
void Copper::draw(Core::Graphics &g)
{
	g.SetColor(RGB(121,122,122));
			fillSquare(g, a, BLOCK_SIZE);
			g.SetColor(RGB(245, 151, 29));
			fillSquare(g, Point(a.x + BLOCK_FIFTH, a.y + BLOCK_FIFTH), BLOCK_FIFTH);
			fillSquare(g, Point(a.x + 3 * BLOCK_FIFTH, a.y + 2 * BLOCK_FIFTH), BLOCK_FIFTH);
			fillSquare(g, Point(a.x + BLOCK_FIFTH, a.y +  3* BLOCK_FIFTH), BLOCK_FIFTH);
}

int BreakableBlock::takeDamage(int damage)
{
	durability -= damage;
	return durability;
}