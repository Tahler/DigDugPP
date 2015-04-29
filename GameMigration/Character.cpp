
#include "Character.h"
#include "Physics.h"

using Physics::Gravity;
using Physics::Point;
using Physics::Vector;
using Physics::Rectangle;

// Character //
Character::Character()
{
	location = Point(0, 0); // The upper left corner of the bounding box
	velocity = Vector(0, 0);
	acceleration = Vector(0, 0);
	isColliding = false;
	isJumping = false;
}
Character::Character(Point& p)
{
	velocity = Vector(0, 0);
	acceleration = Vector(0, 0);
	isColliding = false;
	isJumping = false;
	location = p;
}
Physics::Rectangle Character::getBoundingBox()
{
	// HARDCODED...
	return Physics::Rectangle(location, Point(location.x + 50, location.y + 50));
}
void Character::move()
{
	// Adjust for gravity
	velocity.y += Gravity::acceleration;

	// Adjust for own fluid motion
	velocity.x += acceleration.x;
	velocity.y += acceleration.y;

	// Move
	location += velocity;

}
void Character::draw(Core::Graphics g)
{
	// draw image eventually
	g.SetColor(RGB(10, 10, 255));
	getBoundingBox().draw(g);
	g.SetColor(RGB(255, 255, 255));
}
