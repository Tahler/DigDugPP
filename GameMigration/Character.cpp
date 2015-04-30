
#include "Character.h"

#include "Core.h"
#include "Physics.h"
#include "World.h"

using Physics::Gravity;
using Physics::Point;
using Physics::Vector;
using Physics::Rectangle;
using Physics::operator+;

// Character //
Character::Character()
{
	location = Point(0, 0);
	velocity = Vector(0, 0);
	acceleration = Vector(0, 0);
	isColliding = false;
	isJumping = false;
}
Character::Character(World* w, float x, float y)
{
	world = w;
	location = Point(x, y);
	velocity = Vector(0, 0);
	acceleration = Vector(0, 0);
	isColliding = false;
	isJumping = false;
}
Physics::Rectangle Character::getBoundingBox()
{
	return Physics::Rectangle(location, Point(location.x + BLOCK_SIZE, location.y + BLOCK_SIZE));
}
void Character::checkKeyInput()
{
	float pushAcceleration = 0.2f;

	if (Core::Input::IsPressed(Core::Input::KEY_LEFT)) acceleration.x = -pushAcceleration;
	else if (Core::Input::IsPressed(Core::Input::KEY_RIGHT)) acceleration.x = pushAcceleration;
	else acceleration.x = 0;

	if (Core::Input::IsPressed(Core::Input::KEY_UP)) acceleration.y = -pushAcceleration;
	else if (Core::Input::IsPressed(Core::Input::KEY_DOWN)) acceleration.y = pushAcceleration;
	else acceleration.y = 0;
}
void Character::move()
{
	checkKeyInput();

	// Adjust for gravity
	velocity.y += Gravity::acceleration;
	// and friction
	acceleration.x += -0.02 * velocity.x;
	
	// Adjust for own fluid motion
	velocity.x += acceleration.x;
	velocity.y += acceleration.y;

	// Move
	Block* check;
	if (velocity.x < 0) // moving left
	{
		check = &(world->getBlockAt(Point(location.x - 1, location.y)));
		if (!(*check).intersects(getBoundingBox())) location.x += velocity.x;
		else 
		{
			velocity.x = 0;
			location.x = (*check).a.x + BLOCK_SIZE;
		}
	}
	else if (velocity.x > 0) // moving right
	{
		check = &(world->getBlockAt(Point(location.x + BLOCK_SIZE, location.y)));
		if (!(*check).intersects(getBoundingBox())) location.x += velocity.x;
		else 
		{
			velocity.x = 0;
			location.x = (*check).a.x - BLOCK_SIZE;
		}
	}

	if (velocity.y < 0) // moving up
	{
		check = &(world->getBlockAt(Point(location.x, location.y - 1)));
		if (!(*check).intersects(getBoundingBox())) location.y += velocity.y;
		else 
		{
			velocity.y = 0;
			location.y = (*check).a.y + BLOCK_SIZE;
		}
	}
	else if (velocity.y > 0) // moving down
	{
		check = &(world->getBlockAt(Point(location.x, location.y + BLOCK_SIZE + 1)));
		if (!(*check).intersects(getBoundingBox())) location.y += velocity.y;
		else 
		{
			velocity.y = 0;
			location.y = (*check).a.y - BLOCK_SIZE;
		}
	}
}
void Character::update()
{
	move();
}
void Character::draw(Core::Graphics g)
{
	// draw image eventually
	g.SetColor(RGB(10, 10, 255));
	getBoundingBox().draw(g);
	g.SetColor(RGB(255, 255, 255));
}
