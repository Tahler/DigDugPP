
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
const float MAX_SPEED = 5.0;
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

	if (Core::Input::IsPressed(Core::Input::KEY_UP)) jump();

	//if (Core::Input::IsPressed(Core::Input::KEY_UP)) acceleration.y = -pushAcceleration;
	//else if (Core::Input::IsPressed(Core::Input::KEY_DOWN)) acceleration.y = pushAcceleration;
	//else acceleration.y = 0;
}
void Character::jump()
{
	if (!isJumping)
	{
		isJumping = true;
		// This is hard coded right now... perhaps there is some calculation to jump exactly one block
		velocity.y = -4.0;
	}
}
void Character::move()
{
	// Check for collisions then move
	Block* check;
	if (velocity.x < 0) // moving left
	{
		check = &(world->getBlockAt(Point(location.x - 1, location.y)));
		if (!check->isTraversable)
		{
			if (check->intersects(getBoundingBox())) 
			{
				velocity.x = 0;
				location.x = (*check).a.x + BLOCK_SIZE;
			}
			else location.x += velocity.x;
		}
		else location.x += velocity.x;
	}
	else if (velocity.x > 0) // moving right
	{
		check = &(world->getBlockAt(Point(location.x + BLOCK_SIZE, location.y)));
		if (!check->isTraversable)
		{
			if (check->intersects(getBoundingBox())) 
			{
				velocity.x = 0;
				location.x = (*check).a.x - BLOCK_SIZE;
			}
			else location.x += velocity.x;
		}
		else location.x += velocity.x;
	}

	if (velocity.y < 0) // moving up
	{
		check = &(world->getBlockAt(Point(location.x, location.y - 1)));
		if (!check->isTraversable)
		{
			if (check->intersects(getBoundingBox())) 
			{
				velocity.y = 0;
				location.y = (*check).a.y + BLOCK_SIZE;
			}
			else location.y += velocity.y;
		}
		else location.y += velocity.y;
	}
	else if (velocity.y > 0) // moving down
	{
		check = &(world->getBlockAt(Point(location.x, location.y + BLOCK_SIZE + 1)));
		if (!check->isTraversable)
		{
			if (check->intersects(getBoundingBox())) 
			{
				velocity.y = 0;
				location.y = (*check).a.y - BLOCK_SIZE;
			}
			else location.y += velocity.y;
		}
		else location.y += velocity.y;
	}

	checkKeyInput();

	// Adjust for gravity
	velocity.y += Gravity::acceleration;
	// and friction
	acceleration.x += -0.02 * velocity.x;
	
	// Adjust for own fluid motion
	// Don't let the guy run too fast
	if (std::abs(velocity.x) > MAX_SPEED) 
	{
		// Normalize the vector (make it equal to 1 or -1) and multiply by the MAX_SPEED
		velocity.x *= MAX_SPEED / std::abs(velocity.x);
	}
	velocity.x += acceleration.x;
	velocity.y += acceleration.y;
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
