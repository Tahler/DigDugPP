
#include "Window.h"
#include "Blocks.h"
#include "World.h"
#include "Physics.h"

using Physics::Vector;

// Measured in pixels
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
	box += shift;
	deadzone += shift;
	update();
}

// Ensure the boxes are in the correct place
void Window::update()
{
	// The window box should only shift if the deadzone is not in the center
	if (deadzone.a.x - box.a.x < WINDOW_WIDTH / 3) box += Vector(-(WINDOW_WIDTH / 3 - (deadzone.a.x - box.a.x)), 0);
	else if (box.b.x - deadzone.b.x < WINDOW_WIDTH / 3) box += Vector((WINDOW_WIDTH / 3 - (box.a.x - deadzone.a.x)), 0);
	if (deadzone.a.y - box.a.y < WINDOW_HEIGHT / 3) box += Vector(0, -(WINDOW_HEIGHT / 3 - (deadzone.a.y - box.a.y)));
	else if (box.b.y - deadzone.b.y < WINDOW_HEIGHT / 3) box += Vector(0, (WINDOW_HEIGHT / 3 - (box.a.y - deadzone.a.y)));

	// Don't let the window box go outside the world
	if (box.a.x < 0) box += Vector(-box.a.x, 0);
	else if (box.b.x > WORLD_WIDTH * BLOCK_SIZE) box += Vector(WORLD_WIDTH * BLOCK_SIZE - box.b.x, 0);
	if (box.a.y < 0) box += Vector(0, -box.a.y);
	else if (box.b.y > WORLD_HEIGHT * BLOCK_SIZE) box += Vector(0, WORLD_HEIGHT * BLOCK_SIZE - box.b.y);
 }
//// Only used for tracing
//void Window::draw(Core::Graphics& g)
//{
//	g.SetColor(RGB(255, 0, 0)); 
//	box.draw(g);
//	deadzone.draw(g);
//}