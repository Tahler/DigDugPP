#include "Store.h"
#include "World.h"
#include "Physics.h"
#include "Fill.h"
#include <string>
#include "DrawText.h"
#include "Inventory.h"

using Physics::Point;

int selection = 0;
int padding = 10;
float storeWidth = WINDOW_WIDTH * .75;
float storeHeight = WINDOW_HEIGHT * .75;
float WidthSixth = storeWidth / 13;
float HeightSixth = storeHeight/6.5;
float boxHeight = HeightSixth * 4;
float boxLength = WidthSixth * 3;
float boxUnit = boxLength / 15;
float barLength = boxLength * .75;
bool aDownLastFrame = false;
bool dDownLastFrame = false;
Point p = Point((WINDOW_WIDTH - storeWidth)/2, (WINDOW_HEIGHT - storeHeight)/2);
Point pickPoint = Point(p.x + WidthSixth, p.y + HeightSixth);
Point bagPoint = Point(p.x + WidthSixth*5, p.y + HeightSixth);
Point ladderPoint = Point(p.x + WidthSixth*9, p.y + HeightSixth);

Physics::Rectangle pickBar = Physics::Rectangle(Point(pickPoint.x, pickPoint.y + boxHeight + padding * 2), Point(pickPoint.x + boxLength, pickPoint.y + boxHeight + padding * 2 + boxUnit*3));
Physics::Rectangle bagBar = Physics::Rectangle(Point(bagPoint.x, bagPoint.y + boxHeight + padding * 2), Point(bagPoint.x + boxLength, bagPoint.y + boxHeight + padding * 2  + boxUnit*3));

void Store::draw(Core::Graphics& g)
{
	//Menu
	g.SetColor(RGB(152, 118, 84));
	fillRectangle(g, p, storeWidth, storeHeight);
	
	//Boxes
	g.SetColor(RGB(210,180,140));
	fillRectangle(g, pickPoint, boxLength, boxHeight);
	fillRectangle(g, bagPoint, boxLength, boxHeight);
	fillRectangle(g, ladderPoint, boxLength, boxHeight);

	//Selection
	g.SetColor(RGB(228,132,0));
	fillRectangle(g, Point(pickPoint.x - padding + (WidthSixth * 4 * selection), pickPoint.y -padding), padding, boxHeight + padding*2); 
	fillRectangle(g, Point(pickPoint.x + boxLength + (WidthSixth * 4 * selection), pickPoint.y -padding), padding, boxHeight + padding*2);
	fillRectangle(g, Point(pickPoint.x + (WidthSixth * 4 * selection), pickPoint.y - padding), boxLength + 1, padding);
	fillRectangle(g, Point(pickPoint.x + (WidthSixth * 4 * selection), pickPoint.y + boxHeight-1), boxLength + 1, padding);

	//Pick content
	g.SetColor(RGB(204, 151, 6));
	fillRectangle(g, Point(pickPoint.x + 6.75*boxUnit, pickPoint.y + boxUnit*6), boxUnit * 1.5, boxUnit * 12);
	g.SetColor(RGB(192, 192, 192));
	fillRectangle(g, Point(pickPoint.x + 4*boxUnit, pickPoint.y + boxUnit*4), boxUnit * 7, boxUnit+1);
	fillRectangle(g, Point(pickPoint.x + 3*boxUnit, pickPoint.y + boxUnit*5), boxUnit * 9, boxUnit+1);
	fillRectangle(g, Point(pickPoint.x + 2*boxUnit, pickPoint.y + boxUnit*6), boxUnit * 2, boxUnit+1);
	fillRectangle(g, Point(pickPoint.x + 11*boxUnit, pickPoint.y + boxUnit*6), boxUnit * 2, boxUnit+1);
	fillRectangle(g, Point(pickPoint.x + 1*boxUnit, pickPoint.y + boxUnit*7), boxUnit*2, boxUnit+1);
	fillRectangle(g, Point(pickPoint.x + 12*boxUnit, pickPoint.y + boxUnit*7), boxUnit*2, boxUnit+1);

	//Bag content
	g.SetColor(RGB(150,75,0));
	fillRectangle(g, Point(bagPoint.x + 3*boxUnit, bagPoint.y + 6*boxUnit), boxUnit * 9, boxUnit * 12);
	g.SetColor(RGB(125, 50, 0));
	fillRectangle(g, Point(bagPoint.x + 2*boxUnit, bagPoint.y + 6*boxUnit), boxUnit * 11, boxUnit+1);
	fillRectangle(g, Point(bagPoint.x + 3*boxUnit, bagPoint.y + 7*boxUnit), boxUnit * 9, boxUnit+1);
	fillRectangle(g, Point(bagPoint.x + 4*boxUnit, bagPoint.y + 8*boxUnit), boxUnit * 7, boxUnit+1);
	fillRectangle(g, Point(bagPoint.x + 5*boxUnit, bagPoint.y + 9*boxUnit), boxUnit * 5, boxUnit+1);
	fillRectangle(g, Point(bagPoint.x + 6*boxUnit, bagPoint.y + 10*boxUnit), boxUnit * 3, boxUnit+1);
	g.SetColor(RGB(100, 25, 255));
	//fillHexagon(g, Point(bagPoint.x + 7 * boxUnit, bagPoint.y + 15*boxUnit), boxUnit*2);
	g.SetColor(RGB(100, 25, 0));
	fillRectangle(g, Point(bagPoint.x + 7*boxUnit, bagPoint.y + 10*boxUnit), boxUnit * 1, boxUnit*3);


	//Ladder content
	g.SetColor(RGB(204, 151, 6));
	fillRectangle(g, Point(ladderPoint.x + 3*boxUnit, ladderPoint.y + boxUnit*3), boxUnit*3, boxUnit * 15);
	fillRectangle(g, Point(ladderPoint.x + boxUnit * 9, ladderPoint.y + boxUnit * 3), boxUnit*3, boxUnit * 15);
	fillSquare(g, Point(ladderPoint.x + boxUnit* 6, ladderPoint.y + boxUnit *6), boxUnit*3 + 1);
	fillSquare(g, Point(ladderPoint.x + boxUnit* 6, ladderPoint.y + boxUnit *12), boxUnit*3 + 1);

	//Upgrade bar
	g.SetColor(RGB(40,40,40));
	pickBar.draw(g);
	bagBar.draw(g);

	//Text
	g.SetColor(RGB(0,0,0));
	writeMoney(g, Point(pickPoint.x + boxUnit * 3, pickPoint.y + boxUnit * 21), 150);
	writeMoney(g, Point(bagPoint.x + boxUnit * 3, bagPoint.y + boxUnit * 21), 350);
	writeMoney(g, Point(ladderPoint.x + boxUnit * 4, ladderPoint.y + boxUnit * 21), 30);
	g.SetColor(RGB(255, 255, 50));
	writeMoney(g, Point(25,25), c->inventory.money);
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

	if (Core::Input::IsPressed(VK_ESCAPE)) c->storeOpen = false, selection += 1;

	if (Core::Input::IsPressed(VK_RETURN)) 
	{
		switch (selection)
		{
		case 0:
			upgradePick();
			break;
		case 1:
			upgradeBag();
			break;
		case 2:
			addLadder();
			break;
		default:
			break;
		}
	}
}
void Store::upgradeBag()
{
};

void Store::upgradePick()
{

};