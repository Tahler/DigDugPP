
#ifndef WINDOW_H
#define WINDOW_H

#include "Physics.h"

using Physics::Point;
using Physics::Vector;
using Physics::Rectangle;

extern const int WINDOW_WIDTH, WINDOW_HEIGHT; //, DEADZONE_DIVISOR;

class Window
{
public:
	Physics::Rectangle box;
	Physics::Rectangle deadzone;

	Window() : 
		box(Physics::Rectangle(Point(0, 0), Point(0, 0))),
		deadzone(Physics::Rectangle(Point(0, 0), Point(0, 0)))
	{}
	Window(Point upperLeft) :
		box(Physics::Rectangle(upperLeft, Point(upperLeft.x + WINDOW_WIDTH, upperLeft.y + WINDOW_HEIGHT))),
		deadzone(Physics::Rectangle(Point((box.b.x - box.a.x) / 3, (box.b.y - box.a.y) / 3), Point((box.b.x - box.a.x) * 2 / 3, (box.b.y - box.a.y) * 2 / 3))) // 1/3 size of box
	{}
	bool deadzoneIsCentered();
	void shift(Vector);

	void update();
	void drawAt(Core::Graphics&, Vector);
};

#endif