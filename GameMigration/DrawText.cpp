#include <string>
#include "DrawText.h"

using std::string;

void writeMoney(Core::Graphics& g, Point p,int amount)
{
	int height = 30;
	int charWidth = 20;
	drawDollar(g, p, charWidth, height);
	drawNumber(g, p, charWidth, height, amount, true);

}

void drawNumber(Core::Graphics&g, Point p, int charWidth, int height, int num, bool space)
{
	string s1 = std::to_string(num);
	int numChars = s1.length();
	char* s = new char [numChars+1];
	strcpy(s, s1.c_str());
	int ii;
	int mod;
	if (space) ii = 1, mod = 1; else ii = 0, mod = 0;

	for (; ii <= strlen(s); ii++)
	{
		switch (s[ii-mod])
		{
		case 48:
			drawZero(g, Point(p.x + ii*30, p.y), charWidth, height);
			break;
		case 49:
			drawOne(g, Point(p.x + ii*30, p.y), charWidth, height);
			break;
		case 50:
			drawTwo(g, Point(p.x + ii*30, p.y), charWidth, height);
			break;
		case 51:
			drawThree(g, Point(p.x + ii*30, p.y), charWidth, height);
			break;
		case 52:
			drawFour(g, Point(p.x + ii*30, p.y), charWidth, height);
			break;
		case 53:
			drawFive(g, Point(p.x + ii*30, p.y), charWidth, height);
			break;
		case 54:
			drawSix(g, Point(p.x + ii*30, p.y), charWidth, height);
			break;
		case 55:
			drawSeven(g, Point(p.x + ii*30, p.y), charWidth, height);
			break;
		case 56:
			drawEight(g, Point(p.x + ii*30, p.y), charWidth, height);
			break;
		case 57:
			drawNine(g, Point(p.x + ii*30, p.y), charWidth, height);
			break;
		default:
			break;
		}
	}
	delete[] s;
}

void drawAmount(Core::Graphics& g, Point p, int count, int total)
{
	int height = 30;
	int charWidth = 20;
	int numChars = std::to_string(count).length();
	drawNumber(g, p, charWidth, height, count, false);
	p.x += numChars * (charWidth + 10);
	drawSlash(g, p, charWidth, height);
	p.x += 10;
	drawNumber(g, p, charWidth, height, total, true);
}

void drawSlash(Core::Graphics& g, Point p, int width, int height)
{
	//g.DrawLine(p.x + width, p.y + height, p.x, p.y);
	g.DrawLine(p.x + width, p.y, p.x, p.y + height);
}

void drawZero(Core::Graphics& g, Point p, int width, int height)
{
	g.DrawLine(p.x, p.y, p.x + width, p.y);
	g.DrawLine(p.x + width, p.y, p.x + width, p.y + height);
	g.DrawLine(p.x + width, p.y + height, p.x, p.y + height);
	g.DrawLine(p.x, p.y + height, p.x, p.y);
}

void drawOne(Core::Graphics& g, Point p, int width, int height)
{
	int mid = width/2;
	g.DrawLine(p.x + mid, p.y, p.x + mid, p.y + height);
	g.DrawLine(p.x + mid, p.y, p.x + mid - width/2, p.y);
}

void drawTwo(Core::Graphics& g, Point p, int width, int height)
{
	int half = height/2;
	g.DrawLine(p.x, p.y, p.x + width, p.y);
	g.DrawLine(p.x + width, p.y, p.x + width, p.y + half);
	g.DrawLine(p.x + width, p.y + half, p.x, p.y + half);
	g.DrawLine(p.x, p.y + half, p.x, p.y + height);
	g.DrawLine(p.x, p.y + height, p.x + width, p.y + height);

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
	g.DrawLine(p.x, p.y, p.x, p.y + half);
	g.DrawLine(p.x, p.y + half, p.x + width, p.y + half);
	g.DrawLine(p.x + width, p.y, p.x + width, p.y + height);
}

void drawFive(Core::Graphics& g, Point p, int width, int height)
{
	int half = height/2;
	g.DrawLine(p.x, p.y, p.x + width, p.y);
	g.DrawLine(p.x, p.y, p.x, p.y + half);
	g.DrawLine(p.x, p.y + half, p.x + width, p.y + half);
	g.DrawLine(p.x + width, p.y + half, p.x + width, p.y + height);
	g.DrawLine(p.x + width, p.y + height, p.x, p.y + height);
}

void drawSix(Core::Graphics& g, Point p, int width, int height)
{
	int half = height/2;
	g.DrawLine(p.x, p.y, p.x + width, p.y);
	g.DrawLine(p.x, p.y, p.x, p.y + height);
	g.DrawLine(p.x, p.y + height, p.x + width, p.y + height);
	g.DrawLine(p.x, p.y + half, p.x + width, p.y + half);
	g.DrawLine(p.x + width, p.y + half, p.x + width, p.y + height);
}

void drawSeven(Core::Graphics& g, Point p, int width, int height)
{
	g.DrawLine(p.x, p.y, p.x + width, p.y);
	g.DrawLine(p.x + width, p.y, p.x + width, p.y + height);
}

void drawEight(Core::Graphics& g, Point p, int width, int height)
{
	int half = height/2;
	g.DrawLine(p.x, p.y, p.x, p.y + height);
	g.DrawLine(p.x + width, p.y, p.x + width, p.y + height);
	g.DrawLine(p.x, p.y, p.x + width, p.y);
	g.DrawLine(p.x, p.y + half, p.x + width, p.y + half);
	g.DrawLine(p.x, p.y + height, p.x + width, p.y + height);
}

void drawNine(Core::Graphics& g, Point p, int width, int height)
{
	int half = height/2;
	g.DrawLine(p.x, p.y, p.x, p.y + half);
	g.DrawLine(p.x + width, p.y, p.x + width, p.y + height);
	g.DrawLine(p.x, p.y, p.x + width, p.y);
	g.DrawLine(p.x, p.y + half, p.x + width, p.y + half);
}

void drawDollar(Core::Graphics& g, Point p,  int width, int height)
{
	int mid = width/2;
	float unit = height/4;
	g.DrawLine(p.x + mid, p.y, p.x + mid, p.y + height);
	g.DrawLine(p.x, p.y + unit, p.x + width, p.y + unit);
	g.DrawLine(p.x, p.y + unit, p.x, + p.y + unit*2);
	g.DrawLine(p.x, p.y + unit * 2, p.x + width, p.y + unit * 2);
	g.DrawLine(p.x + width, p.y + unit * 2, p.x + width, p.y + unit * 3);
	g.DrawLine(p.x + width, p.y + unit * 3, p.x, p.y + unit*3);
}