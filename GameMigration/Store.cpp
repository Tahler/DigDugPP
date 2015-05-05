#include "Store.h"
#include "World.h"
#include "Physics.h"
#include "Fill.h"

using Physics::Point;

int selection = 0;
float storeWidth = WINDOW_WIDTH * .75;
float storeHeight = WINDOW_HEIGHT * .75;
float WidthSixth = storeWidth / 13;
float HeightSixth = storeHeight/6;
bool aDownLastFrame = false;
bool dDownLastFrame = false;
Point p = Point((WINDOW_WIDTH - storeWidth)/2, (WINDOW_HEIGHT - storeHeight)/2);
Point pickPoint = Point(p.x + WidthSixth, p.y + HeightSixth);
Point bagPoint = Point(p.x + WidthSixth*5, p.y + HeightSixth);
Point ladderPoint = Point(p.x + WidthSixth*9, p.y + HeightSixth);

void Store::draw(Core::Graphics& g)
{
	//Menu
	g.SetColor(RGB(0,0,0));
	fillRectangle(g, p, storeWidth, storeHeight);
	g.SetColor(RGB(255,255,255));

	//Boxes
	fillRectangle(g, pickPoint, WidthSixth * 3, HeightSixth * 4);
	fillRectangle(g, bagPoint, WidthSixth * 3, HeightSixth * 4);
	fillRectangle(g, ladderPoint, WidthSixth * 3, HeightSixth * 4);

	//Selection
	g.SetColor(RGB(255,0,0));
	fillRectangle(g, Point(pickPoint.x - 10 + (WidthSixth * 4 * selection), pickPoint.y -10), 10, HeightSixth*4 + 20); 
	fillRectangle(g, Point(pickPoint.x + WidthSixth*3 + (WidthSixth * 4 * selection), pickPoint.y -10), 10, HeightSixth*4 + 20);
	fillRectangle(g, Point(pickPoint.x + (WidthSixth * 4 * selection), pickPoint.y -10), WidthSixth * 3, 10);
	fillRectangle(g, Point(pickPoint.x + (WidthSixth * 4 * selection), pickPoint.y + HeightSixth *4), WidthSixth * 3, 10);

	//Pick content

	//Bag content

	//Ladder content
}

void Store::addLadder(){};

void Store::update()
{
	if (Core::Input::IsPressed(Core::Input::KEY_A))
	{
		if(!aDownLastFrame){
			selection--;
			aDownLastFrame = true;
		}
	} 
	else 
	{
		aDownLastFrame = false;
	}
	
	if (Core::Input::IsPressed(Core::Input::KEY_D))
	{
		if(!dDownLastFrame){
			selection++;
			dDownLastFrame = true;
		}
	} 
	else 
	{
		dDownLastFrame = false;
	}
	
	if (selection > 2) selection = 0;
	if (selection < 0) selection = 2;
}
void Store::upgradeBag(){};
void Store::upgradePick(){};