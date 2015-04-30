
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
const float DRAG = 0.1;

Physics::Rectangle Character::getBoundingBox()
{
	return Physics::Rectangle(location, Point(location.x + BLOCK_SIZE, location.y + BLOCK_SIZE));
}
void Character::checkKeyInput()
{
	if (Core::Input::IsPressed(Core::Input::KEY_LEFT)) velocity.x = -MAX_SPEED;
	else if (Core::Input::IsPressed(Core::Input::KEY_RIGHT)) velocity.x = MAX_SPEED;
	else velocity.x = 0;

	if (Core::Input::IsPressed(Core::Input::KEY_UP)) jump();
}
void Character::jump()
{
	if (!isJumping)
	{
		isJumping = true;
		// Perhaps there is some calculation to jump exactly one block
		velocity.y = -MAX_SPEED;
	}
}
void Character::checkCollisions()
{
	// No matter what direction, there are two corners that have to be checked.
	Block* neighbor;
	Block* neighbor2;
	Physics::Rectangle* box = &getBoundingBox();

	if (velocity.x < 0) // moving left
	{
		neighbor = &(world->getBlockAt(Point(box->a.x - MAX_SPEED, box->a.y)));
		neighbor2 = &(world->getBlockAt(Point(box->a.x - MAX_SPEED, box->b.y)));
		if (!neighbor->isTraversable || !neighbor2->isTraversable)
		{
			velocity.x = 0;
			if (neighbor->intersects(*box) && neighbor2->intersects(*box)) 
			{
				location.x = neighbor->a.x + BLOCK_SIZE;
			}
		}
	}
	else if (velocity.x > 0) // moving right
	{
		neighbor = &(world->getBlockAt(Point(box->b.x + MAX_SPEED, box->a.y)));
		neighbor2 = &(world->getBlockAt(Point(box->b.x + MAX_SPEED, box->b.y)));
		if (!neighbor->isTraversable || !neighbor2->isTraversable)
		{
			velocity.x = 0;
			if (neighbor->intersects(*box) || neighbor2->intersects(*box)) 
			{
				location.x = neighbor->a.x - BLOCK_SIZE;
			}
		}
	}

	if (velocity.y > 0) // moving down
	{
		isJumping = true; // If the character is falling he should not be able to jump
		
		neighbor = &(world->getBlockAt(Point(box->a.x, box->b.y + MAX_SPEED)));
		neighbor2 = &(world->getBlockAt(Point(box->b.x, box->b.y + MAX_SPEED)));
		if (!neighbor->isTraversable || !neighbor2->isTraversable)
		{
			isJumping = false;
			velocity.y = 0;
			if (neighbor->intersects(*box) || neighbor2->intersects(*box)) 
			{
				location.y = neighbor->a.y - BLOCK_SIZE;
			}
		}
	}
	else if (velocity.y < 0) // moving up
	{
		neighbor = &(world->getBlockAt(Point(box->a.x, box->b.y - MAX_SPEED)));
		neighbor2 = &(world->getBlockAt(Point(box->b.x, box->b.y - MAX_SPEED)));
		if (!neighbor->isTraversable || !neighbor2->isTraversable)
		{
			velocity.y = 0;
			if (neighbor->intersects(*box) || neighbor2->intersects(*box)) 
			{
				location.y = neighbor->a.y + BLOCK_SIZE;
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
}
void Character::draw(Core::Graphics g)
{
	g.SetColor(RGB(28, 212, 52));
	//fillSquare(g, location, BLOCK_SIZE);
	fillRectangle(g, Point(location.x + BLOCK_FIFTH, location.y + BLOCK_FIFTH), BLOCK_FIFTH * 3, BLOCK_FIFTH * 1);
	fillSquare(g, Point(location.x + BLOCK_FIFTH * 2, location.y + BLOCK_FIFTH*2), BLOCK_FIFTH);
	g.SetColor(RGB(247, 214, 143));
	fillSquare(g, Point(location.x + 2 * BLOCK_FIFTH, location.y), BLOCK_FIFTH);
	
	//Hands
	if(velocity.x > 0)
	{
		fillSquare(g, Point(location.x + BLOCK_FIFTH, location.y + BLOCK_FIFTH * 2), BLOCK_FIFTH);
		fillSquare(g, Point(location.x + 4 * BLOCK_FIFTH, location.y + BLOCK_FIFTH), BLOCK_FIFTH);
	} 
	else if (velocity.x < 0)
	{
		fillSquare(g, Point(location.x, location.y + BLOCK_FIFTH), BLOCK_FIFTH);
		fillSquare(g, Point(location.x + 3 * BLOCK_FIFTH, location.y + BLOCK_FIFTH * 2), BLOCK_FIFTH);
	} 
	else 
	{
		fillSquare(g, Point(location.x + BLOCK_FIFTH, location.y + BLOCK_FIFTH * 2), BLOCK_FIFTH);
		fillSquare(g, Point(location.x + 3 * BLOCK_FIFTH, location.y + BLOCK_FIFTH * 2), BLOCK_FIFTH);
	}
	g.SetColor(RGB(38, 88, 158));
	fillRectangle(g, Point(location.x + BLOCK_FIFTH * 2, location.y + BLOCK_FIFTH * 3), BLOCK_FIFTH, BLOCK_FIFTH * 2);
	g.SetColor(RGB(10, 10, 255));
	getBoundingBox().draw(g);
	
}
