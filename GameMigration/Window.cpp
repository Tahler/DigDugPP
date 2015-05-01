
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

Window::Window(Point& upperLeft)
{
	box = Physics::Rectangle(upperLeft, Point(upperLeft.x + WINDOW_WIDTH, upperLeft.y + WINDOW_HEIGHT));
}
void Window::shift(Vector& shift)
{
	box += shift;
}
void Window::moveUpperLeftTo(Point& newLocation)
{
	box = Physics::Rectangle(newLocation, Point(newLocation.x + WINDOW_WIDTH, newLocation.y + WINDOW_HEIGHT));
}