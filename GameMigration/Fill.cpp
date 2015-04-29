#include "Fill.h"
#include "Core.h"

using Core::Graphics;
using Physics::Point;

void fillSquare(Graphics& g, Point p, int width)
{
	for (int ii = 0; ii < width; ii++) 
	{
		g.DrawLine(p.x + ii, p.y, p.x + ii, p.y + width);
	}
}

void fillRectangle(Graphics& g, Point p, int width, int height)
{
	for (int ii = 0; ii < width; ii++)
	{
		g.DrawLine(p.x + ii, p.y, p.x + ii, p.y + height);
	}
}

void fillTriangle(Graphics& g, Point p, int width)
{
	int leftEnd = p.x;
	int rightEnd = p.x + width;
	for (int ii = 0; ii < width; ii++)
	{
		g.DrawLine(leftEnd, p.y + width - ii, rightEnd, p.y + width - ii);
		if (ii % 2 == 0) leftEnd++, rightEnd--;
	}
}

void fillHexagon(Graphics& g, Point p, int width)
{
	

}

void fillOctagon(Graphics& g, Point p, int width)
{
	//Hexs appear in fourths
	int unit = width / 4;

}