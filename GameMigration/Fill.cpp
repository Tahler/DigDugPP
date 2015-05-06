#include "Fill.h"
#include "Core.h"
#include "World.h"

using Core::Graphics;
using Physics::Point;

void fillSquare(Graphics& g, Point p, int width)
{
	//++width;
	for (int ii = 0; ii < width; ++ii) 
	{
		g.DrawLine(p.x + ii, p.y, p.x + ii, p.y + width);
	}
}
void fillRectangle(Graphics& g, Point p, int width, int height)
{
	//++width;
	//++height;
	if (width < height) 
	{
		for (int ii = 0; ii < width; ++ii)
		{
			g.DrawLine(p.x + ii, p.y, p.x + ii, p.y + height);
		}
	} else 
		{
		for (int ii = 0; ii < height; ++ii)
			{
			g.DrawLine(p.x, p.y + ii, p.x + width, p.y + ii);
		}
	}
}
void fillHexagon(Graphics& g, Point p, int width)
{
	float unit = width/3;
	float half = width/2;
	float delta = unit/half;
	for(float ii = 0; ii < half; ii++)
	{
		g.DrawLine(p.x + unit - (delta*ii), p.y + ii, p.x + unit*2 + (delta*ii), p.y + ii);
	}

	for (int ii = half; ii < width; ++ii)
	{
		g.DrawLine(p.x + (delta*(ii-half)), p.y + ii, p.x + unit*3 - (delta*(ii-half)), p.y +ii);
	}

}
