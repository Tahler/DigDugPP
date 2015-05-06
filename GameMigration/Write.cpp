#include "Write.h"

void writeMoney(Core::Graphics& g, Point p, int width, int height, int amount)
{
	g.SetColor(RGB(0,0,0));
	drawZero(g, p, width, height);
}

void drawZero(Core::Graphics& g, Point p, int width, int height)
{
	g.DrawLine(p.x, p.y, p.x + width, p.y);
	g.DrawLine(p.x + width, p.y, p.x + width, p.y + height);
	g.DrawLine(p.x + width, p.y + height, p.x, p.y + height);
	g.DrawLine(p.x, p.y + height, p.x, p.y);
}

void drawOne(Core::Graphics& g, int width)
{

}

void drawTwo(Core::Graphics& g, int width)
{

}

void drawThree(Core::Graphics& g, Point p,  int width, int height)
{
	int half = height/2;
	g.DrawLine(p.x+width, p.y, p.x+width, p.y + height);
	g.DrawLine(p.x+width, p.y, p.x, p.y);
	g.DrawLine(p.x+width, p.y+half, p.x, p.y+half);
	g.DrawLine(p.x+width, p.y+height, p.x, p.y+height);
}

void drawFour(Core::Graphics& g, Point p,  int width, int height)
{
	int half = height/2;
}

void drawFive(Core::Graphics& g, Point p, int width, int height)
{
	int half = height/2;
}

void drawSix(Core::Graphics& g, Point p, int width, int height)
{
	int half = height/2;
}

void drawSeven(Core::Graphics& g, Point p, int width, int height)
{

}

void drawEight(Core::Graphics& g, Point p, int width, int height)
{
	int half = height/2;
}

void drawNine(Core::Graphics& g, Point p, int width, int height)
{
	int half = height/2;
}

void drawDollar(Core::Graphics& g, int width)
{

}