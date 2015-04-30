
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
const float DRAG = 0.02;
bool movingRight = true;

Physics::Rectangle Character::getBoundingBox()
{
	return Physics::Rectangle(location, Point(location.x + BLOCK_SIZE, location.y + BLOCK_SIZE));
}
void Character::checkKeyInput()
{
	float pushAcceleration = 0.2f;

	if (Core::Input::IsPressed(Core::Input::KEY_LEFT)) acceleration.x = -pushAcceleration, movingRight = false;
	else if (Core::Input::IsPressed(Core::Input::KEY_RIGHT)) acceleration.x = pushAcceleration, movingRight = true;
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
void Character::checkCollisions()
{
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
		}
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
		}
	}

	if (velocity.y > 0) // moving down
	{
		isJumping = true; // If the character is falling he should not be able to jump
		check = &(world->getBlockAt(Point(location.x, location.y + BLOCK_SIZE + 1)));
		if (!check->isTraversable)
		{
			if (check->intersects(getBoundingBox())) 
			{
				isJumping = false;
				velocity.y = 0;
				location.y = (*check).a.y - BLOCK_SIZE;
			}
		}
	}
	else if (velocity.y < 0) // moving up
	{
		check = &(world->getBlockAt(Point(location.x, location.y - 1)));
		if (!check->isTraversable)
		{
			if (check->intersects(getBoundingBox())) 
			{
				velocity.y = 0;
				location.y = (*check).a.y + BLOCK_SIZE;
			}
		}
	}
}
void Character::move()
{
	// Don't go outside the window, otherwise allow movement
	if (location.x >= 0 && location.x + BLOCK_SIZE <= WINDOW_WIDTH) location.x += velocity.x;
	if (location.y >= 0 && location.y + BLOCK_SIZE <= WINDOW_HEIGHT) location.y += velocity.y;
}
void Character::update()
{
	checkKeyInput();

	checkCollisions();
	move();
	
	// Adjust for gravity
	velocity.y += Gravity::acceleration;
	// and friction
	acceleration.x += -DRAG * velocity.x;

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
void Character::draw(Core::Graphics g)
{
	// draw image eventually
	g.SetColor(RGB(28, 212, 52));
	fillRectangle(g, Point(location.x + BLOCK_FIFTH, location.y + BLOCK_FIFTH), BLOCK_FIFTH * 3, BLOCK_FIFTH * 1);
	fillSquare(g, Point(location.x + BLOCK_FIFTH * 2, location.y + BLOCK_FIFTH*2), BLOCK_FIFTH);
	g.SetColor(RGB(247, 214, 143));
	fillSquare(g, Point(location.x + 2 * BLOCK_FIFTH, location.y), BLOCK_FIFTH);
	
	//Hands
	if(movingRight)
	{
		fillSquare(g, Point(location.x + BLOCK_FIFTH, location.y + BLOCK_FIFTH * 2), BLOCK_FIFTH);
		fillSquare(g, Point(location.x + 4 * BLOCK_FIFTH, location.y + BLOCK_FIFTH), BLOCK_FIFTH);
	} 
	else 
	{
		fillSquare(g, Point(location.x, location.y + BLOCK_FIFTH), BLOCK_FIFTH);
		fillSquare(g, Point(location.x + 3 * BLOCK_FIFTH, location.y + BLOCK_FIFTH * 2), BLOCK_FIFTH);
	}
	g.SetColor(RGB(38, 88, 158));
	fillRectangle(g, Point(location.x + BLOCK_FIFTH * 2, location.y + BLOCK_FIFTH * 3), BLOCK_FIFTH, BLOCK_FIFTH * 2);
	//g.SetColor(RGB(10, 10, 255));
	//getBoundingBox().draw(g);
}
