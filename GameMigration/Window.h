
#ifndef WINDOW_H
#define WINDOW_H

#include "Physics.h"

using Physics::Point;
using Physics::Vector;
using Physics::Rectangle;

extern const int WINDOW_WIDTH, WINDOW_HEIGHT;

class Window
{
public:
	Physics::Rectangle box;

	Window() : 
		box(Physics::Rectangle(Point(0, 0), Point(0, 0)))
	{}
	Window(Point& upperLeft);
	void shift(Vector&);
	void moveUpperLeftTo(Point&);
};

#endif