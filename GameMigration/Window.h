
#ifndef WINDOW_H
#define WINDOW_H

#include "Physics.h"

extern const int WINDOW_WIDTH, WINDOW_HEIGHT;

class Window
{
	Physics::Rectangle box;
public:
	Window() {}
	Window(Point& upperLeft);
	void shift(Vector& shift);
	void moveUpperLeftTo(Point& newLocation);
};

#endif