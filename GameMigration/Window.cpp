
#include "Window.h"
#include "Blocks.h"
#include "World.h"
#include "Physics.h"

#include <iostream>
using std::cout;

using Physics::Vector;

// Measured in pixels
//const int WINDOW_WIDTH = 24 * BLOCK_SIZE;
//const int WINDOW_HEIGHT = 16 * BLOCK_SIZE;
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;
//const int DEADZONE_DIVISOR = 3;

bool Window::deadzoneIsCentered()
{
	Point center = Point((box.b.x - box.a.x) / 3, (box.b.y - box.a.y) / 3);
	return (deadzone.a.x < center.x + 50 && deadzone.a.x > center.x - 50); // may need to give a buffer (it may not ever be exact)
}
void Window::shift(Vector& shift)
{
	color = RGB(0x63, 0x19, 0x9c);
	color = RGB(255, 0, 0); // trace with red

	// Don't let the window box go outside the world
	// The window box should only shift if the deadzone is not in the center
	
		//if (deadzoneIsCentered())
		//box += shift;
	
	box += shift;
	deadzone += shift;
	update();
}

void Window::update()
{
	if (deadzone.a.x - box.a.x < 400) box += Vector(-(400 - (deadzone.a.x - box.a.x)), 0);
	else if (box.b.x - deadzone.b.x < 400) box += Vector((400 - (box.a.x - deadzone.a.x)), 0);

	if (box.a.x < 0) box += Vector(-box.a.x, 0);
	else if (box.b.x > 2400) box += Vector(2400 - box.b.x, 0);
}
void Window::draw(Core::Graphics& g)
{
	g.SetColor(color);
	box.draw(g);
	deadzone.draw(g);
}