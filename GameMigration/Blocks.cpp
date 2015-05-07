
#include "Blocks.h"
#include "Fill.h"

using namespace Blocks;
using Physics::Vector;

// Measured in pixels
const int BLOCK_SIZE = 50;

//Draw functions for each block
void Sky::drawAt(Core::Graphics& g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(120, 207, 227));
	fillSquare(g, p, BLOCK_SIZE);
}
void Cave::drawAt(Core::Graphics& g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(41, 24, 2));
	fillSquare(g, p, BLOCK_SIZE);
}
void Ladder::drawAt(Core::Graphics& g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(41, 24, 2));
	fillSquare(g, p, BLOCK_SIZE);
	g.SetColor(RGB(204, 151, 6));
	//Rails
	fillRectangle(g, Point(p.x + BLOCK_FIFTH, p.y), BLOCK_FIFTH, BLOCK_SIZE);
	fillRectangle(g, Point(p.x + 3*BLOCK_FIFTH, p.y), BLOCK_FIFTH, BLOCK_SIZE);
	//Rungs
	fillRectangle(g, Point(p.x + 2*BLOCK_FIFTH, p.y + BLOCK_SIXTH), BLOCK_FIFTH, BLOCK_SIXTH);
	fillRectangle(g, Point(p.x + 2*BLOCK_FIFTH, p.y + 3*BLOCK_SIXTH), BLOCK_FIFTH, BLOCK_SIXTH);
	fillRectangle(g, Point(p.x + 2*BLOCK_FIFTH, p.y + 5*BLOCK_SIXTH), BLOCK_FIFTH, BLOCK_SIXTH);
}

void Dirt::drawAt(Core::Graphics &g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(110,83,9));
	fillSquare(g, p, BLOCK_SIZE);
	drawCracks(g, p, durability);
}

void Grass::drawAt(Core::Graphics &g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(110, 83, 9));
	fillSquare(g, p, BLOCK_SIZE);
	g.SetColor(RGB(20, 219, 2));
	fillRectangle(g, p, BLOCK_SIZE, BLOCK_FIFTH);
	drawCracks(g, p, durability);
}

void Stone::drawAt(Core::Graphics &g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(121, 122, 122));
	fillSquare(g, p, BLOCK_SIZE);
	drawCracks(g, p, durability);
}

void UnbreakableGrass::drawAt(Core::Graphics &g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(110,83,9));
	fillSquare(g, p, BLOCK_SIZE);
	g.SetColor(RGB(20, 219, 2));
	fillRectangle(g, p, BLOCK_SIZE, BLOCK_FIFTH);
}

void Copper::drawAt(Core::Graphics &g, Vector& offset)
{
	g.SetColor(RGB(121,122,122));
	Point p = a - offset;
	fillSquare(g, p, BLOCK_SIZE);
	g.SetColor(RGB(245, 151, 29));
	fillSquare(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH), BLOCK_FIFTH);
	fillSquare(g, Point(p.x + 3 * BLOCK_FIFTH, p.y + 2 * BLOCK_FIFTH), BLOCK_SIXTH);
	fillSquare(g, Point(p.x + BLOCK_FIFTH, p.y +  3* BLOCK_FIFTH), BLOCK_FIFTH);
	drawCracks(g, p, durability);
}

void Iron::drawAt(Core::Graphics &g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(121,122,122));
	fillSquare(g, p, BLOCK_SIZE);
	g.SetColor(RGB(199, 174, 141));
	fillRectangle(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH), 2*BLOCK_FIFTH, BLOCK_FIFTH);
	fillSquare(g, Point(p.x + 3*BLOCK_FIFTH, p.y + 2*BLOCK_FIFTH), BLOCK_FIFTH);
	fillSquare(g, Point(p.x + 2*BLOCK_FIFTH, p.y + 3 * BLOCK_FIFTH), BLOCK_FIFTH);		
	drawCracks(g, p, durability);
}

void Silver::drawAt(Core::Graphics &g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(121,122,122));
	fillSquare(g, p, BLOCK_SIZE);
	g.SetColor(RGB(192, 192, 192));
	fillRectangle(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH), 2*BLOCK_FIFTH, BLOCK_FIFTH);
	fillSquare(g, Point(p.x + 2* BLOCK_FIFTH, p.y + 2 * BLOCK_FIFTH), BLOCK_FIFTH);
	fillSquare(g, Point(p.x + 3* BLOCK_FIFTH, p.y + 3 * BLOCK_FIFTH), BLOCK_SIXTH);
	drawCracks(g, p, durability);
}

void Sapphire::drawAt(Core::Graphics& g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(121,122,122));
	fillSquare(g, p, BLOCK_SIZE);
	g.SetColor(RGB(51, 51, 153));
	fillHexagon(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH), BLOCK_FIFTH); 
	fillHexagon(g, Point(p.x + BLOCK_FIFTH*3, p.y + BLOCK_FIFTH), BLOCK_FIFTH);
	fillHexagon(g, Point(p.x + BLOCK_FIFTH*2, p.y + BLOCK_FIFTH*3), BLOCK_SIXTH);
	drawCracks(g, p, durability);
}

void Ruby::drawAt(Core::Graphics& g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(121,122,122));
	fillSquare(g, p, BLOCK_SIZE);
	g.SetColor(RGB(155, 17, 30));
	fillHexagon(g, Point(p.x + BLOCK_FIFTH*3, p.y + BLOCK_FIFTH), BLOCK_SIXTH); 
	fillHexagon(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH*2), BLOCK_FIFTH);
	fillHexagon(g, Point(p.x + BLOCK_FIFTH*3, p.y + BLOCK_FIFTH*3), BLOCK_FIFTH);
	drawCracks(g, p, durability);
}

void Emerald::drawAt(Core::Graphics& g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(121,122,122));
	fillSquare(g, p, BLOCK_SIZE);
	g.SetColor(RGB(80, 200, 120));
	fillHexagon(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH*3), BLOCK_FIFTH); 
	fillHexagon(g, Point(p.x + BLOCK_FIFTH*2, p.y + BLOCK_FIFTH*2), BLOCK_FIFTH);
	fillHexagon(g, Point(p.x + BLOCK_FIFTH*3, p.y + BLOCK_FIFTH*4), BLOCK_FIFTH);
	drawCracks(g, p, durability);
}

void Gold::drawAt(Core::Graphics &g, Vector& offset)
{
	g.SetColor(RGB(121,122,122));
	Point p = a - offset;
	fillSquare(g, p, BLOCK_SIZE);
	g.SetColor(RGB(212, 175, 55));
	fillRectangle(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH), BLOCK_FIFTH*2, BLOCK_FIFTH);
	fillSquare(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH * 3), BLOCK_FIFTH);
	fillSquare(g, Point(p.x + BLOCK_FIFTH*3, p.y + BLOCK_FIFTH * 3), BLOCK_FIFTH);
	drawCracks(g, p, durability);
}

void Diamond::drawAt(Core::Graphics& g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(121,122,122));
	fillSquare(g, p, BLOCK_SIZE);
	g.SetColor(RGB(185, 242, 255));
	fillHexagon(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH * 3), BLOCK_FIFTH); 
	fillHexagon(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH), BLOCK_FIFTH);
	fillHexagon(g, Point(p.x + BLOCK_FIFTH*2, p.y + BLOCK_FIFTH), BLOCK_FIFTH*2);
	drawCracks(g, p, durability);
}

void StoreLeft::drawAt(Core::Graphics& g, Vector& offset)
{
	Point p = a - offset;
	g.SetColor(RGB(120, 207, 227));
	fillSquare(g, p, BLOCK_SIZE);
	//Counter
	g.SetColor(RGB(181, 101, 29));
	fillRectangle(g, Point(p.x, p.y + BLOCK_FIFTH * 2), BLOCK_SIZE, BLOCK_FIFTH);
	fillRectangle(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH * 3), BLOCK_FIFTH, BLOCK_FIFTH * 2);
	//Gold bar
	g.SetColor(RGB(212, 175, 55));
	fillRectangle(g, Point(p.x + BLOCK_FIFTH, p.y + BLOCK_FIFTH), BLOCK_SIXTH * 2, BLOCK_FIFTH);
	//shirt
	g.SetColor(RGB(159, 0, 197));
	fillRectangle(g, Point(p.x + BLOCK_FIFTH * 3, p.y + BLOCK_FIFTH), BLOCK_FIFTH*2, BLOCK_FIFTH);
	//legs
	g.SetColor(RGB(0xf0, 0xf0, 0xf0));
	fillRectangle(g, Point(p.x + BLOCK_FIFTH*4, p.y + BLOCK_FIFTH*3), BLOCK_FIFTH, BLOCK_FIFTH*2);
	//head
	g.SetColor(RGB(0x53, 0x37, 0x19));
	fillSquare(g, Point(p.x + BLOCK_FIFTH*4, p.y), BLOCK_FIFTH);
}

void StoreRight::drawAt(Core::Graphics& g, Vector& offset)
{

	Point p = a - offset;
	g.SetColor(RGB(120, 207, 227));
	fillSquare(g, p, BLOCK_SIZE);
	//Counnter
	g.SetColor(RGB(181, 101, 29));
	fillRectangle(g, Point(p.x, p.y + BLOCK_FIFTH * 2), BLOCK_SIZE, BLOCK_FIFTH);
	fillRectangle(g, Point(p.x + BLOCK_FIFTH * 3, p.y + BLOCK_FIFTH * 3), BLOCK_FIFTH, BLOCK_FIFTH *2);
	//Emerald
	g.SetColor(RGB(155, 17, 30));
	fillHexagon(g, Point(p.x + BLOCK_FIFTH *2, p.y + BLOCK_FIFTH), BLOCK_FIFTH);
	//shirt
	g.SetColor(RGB(159, 0, 197));
	fillSquare(g, Point(p.x, p.y + BLOCK_FIFTH), BLOCK_FIFTH);
}

void BreakableBlock::drawCracks(Core::Graphics& g, Point &p, int durability)
{
	if (durability < 100)
	{
		//A little damaged
		g.SetColor(RGB(30,30,30));
		g.DrawLine(p.x + 2*BLOCK_FIFTH, p.y + BLOCK_FIFTH, p.x + 2*BLOCK_FIFTH, p.y + 2*BLOCK_FIFTH);
		g.DrawLine(p.x + 2*BLOCK_FIFTH, p.y + 2*BLOCK_FIFTH, p.x + 3*BLOCK_FIFTH, p.y + 2*BLOCK_FIFTH);
		g.DrawLine(p.x + 3*BLOCK_FIFTH, p.y + 2*BLOCK_FIFTH, p.x + 3*BLOCK_FIFTH, p.y + 4*BLOCK_FIFTH);
		if (durability < 50)
		{
			//more damaged
			g.DrawLine(p.x + BLOCK_FIFTH, p.y + 2*BLOCK_FIFTH, p.x + 2 * BLOCK_FIFTH, p.y + 2*BLOCK_FIFTH);
			g.DrawLine(p.x + 2*BLOCK_FIFTH, p.y + 2*BLOCK_FIFTH, p.x + 2*BLOCK_FIFTH, p.y + 3*BLOCK_FIFTH);
			g.DrawLine(p.x + 3*BLOCK_FIFTH, p.y + 3*BLOCK_FIFTH, p.x + 4*BLOCK_FIFTH, p.y + 3*BLOCK_FIFTH);
			if (durability < 25)
			{
				//very damaged
				g.DrawLine(p.x, p.y + 2*BLOCK_FIFTH, p.x + 4*BLOCK_FIFTH, p.y + 2*BLOCK_FIFTH);
				g.DrawLine(p.x + BLOCK_FIFTH, p.y + 3*BLOCK_FIFTH, p.x + 2*BLOCK_FIFTH, p.y + 3*BLOCK_FIFTH);
				g.DrawLine(p.x + 2*BLOCK_FIFTH, p.y, p.x + 2*BLOCK_FIFTH, p.y + 4*BLOCK_FIFTH);
				g.DrawLine(p.x + 3*BLOCK_FIFTH, p.y + BLOCK_FIFTH, p.x + 3*BLOCK_FIFTH, + p.y + 5*BLOCK_FIFTH);
				g.DrawLine(p.x +3*BLOCK_FIFTH, p.y + 3* BLOCK_FIFTH, p.x + 5* BLOCK_FIFTH, p.y + 3*BLOCK_FIFTH);
				g.DrawLine(p.x + 4*BLOCK_FIFTH, p.y + BLOCK_FIFTH, p.x + 4*BLOCK_FIFTH, p.y+ 2*BLOCK_FIFTH);
			}
		}
	}
}

int BreakableBlock::takeDamage(int damage)
{
	durability -= damage;
	return durability;
}