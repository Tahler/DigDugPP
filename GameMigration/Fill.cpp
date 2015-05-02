#include "Fill.h"
#include "Core.h"
#include "World.h"

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
	if (width < height) 
	{
		for (int ii = 0; ii < width; ii++)
		{
			g.DrawLine(p.x + ii, p.y, p.x + ii, p.y + height);
		}
	} else 
		{
		for (int ii = 0; ii < height; ii++)
			{
			g.DrawLine(p.x, p.y + ii, p.x + width, p.y + ii);
		}
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
	int unit = width/3;
	for(int ii = 0; ii < width; ii++)
	{
		//g.DrawLine(p.x + width - ii
	}

}

void fillOctagon(Graphics& g, Point p, int width)
{
	//Hexs appear in fourths
	int unit = width / 4;

}

void fillCircle(Graphics& g, Point p, int width)
{
	p.x = p.x - BLOCK_SIZE/2;
	p.y = p.y + BLOCK_SIZE/2;
	int x = width/2;
	int y = 0;
	int radiusError = 1-x;
	while(x >= y)
	{
		g.DrawLine(x + p.x,  y + p.y, -x + p.x,  -y + p.y);
		g.DrawLine(y + p.x,  x + p.y, -y + p.x,  -x + p.y);
		g.DrawLine(-x + p.x,  y + p.y, x + p.x,  -y + p.y);
		g.DrawLine(-y + p.x,  x + p.y, y + p.x,  -x + p.y);
		y++;
		if (radiusError<0)
		 {
			radiusError += 2 * y + 1;
		}
		else
		{
			x--;
			radiusError += 2 * (y - x) + 1;
		}
	}

}