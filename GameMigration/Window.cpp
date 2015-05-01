
#include "Window.h"
#include "Blocks.h"
#include "World.h"
#include "Physics.h"

using Physics::Vector;

// Measured in pixels
//const int WINDOW_WIDTH = 24 * BLOCK_SIZE;
//const int WINDOW_HEIGHT = 16 * BLOCK_SIZE;
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = 800;

void Window::shift(Vector& shift)
{
	//if (box.a.x + shift.x >= BLOCK_SIZE) box += shift;
	//if (box.b.x + shift.x <= 0) box += shift; // hard coded

	if (box.a.x > 0 && box.b.x < 2400) box += shift;

	//box += shift;
	deadzone += shift;
}
void Window::moveUpperLeftTo(Point& newLocation)
{
	box = Physics::Rectangle(newLocation, Point(newLocation.x + WINDOW_WIDTH, newLocation.y + WINDOW_HEIGHT));
	//deadzone = Physics::Rectangle(newLocation, Point(newLocation.x + WINDOW_WIDTH, newLocation.y + WINDOW_HEIGHT));
}

void Window::draw(Core::Graphics& g)
{
	g.SetColor(RGB(0x63, 0x19, 0x9c));
	box.draw(g);
	deadzone.draw(g);
}